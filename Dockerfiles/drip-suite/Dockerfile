FROM ubuntu:latest

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get upgrade -y
RUN apt-get install -y mongodb mongodb-server openssh-server wget git inetutils-ping software-properties-common build-essential libssl-dev libffi-dev python-dev graphviz graphviz-dev python-pip screen rabbitmq-server myproxy 

# Install python stuff
RUN pip install --upgrade pip
RUN pip install pydot
RUN pip install numpy
RUN pip install networkx==1.10
RUN pip install flask
RUN pip install tosca-parser
RUN pip install pika
RUN export LC_ALL="en_US.UTF-8"
RUN pip install paramiko
RUN pip install ansible


##install java
RUN apt-get install -y python-software-properties debconf-utils apt-utils
RUN add-apt-repository -y ppa:webupd8team/java
RUN apt-get update
RUN "oracle-java8-installer shared/accepted-oracle-license-v1-1 select true" | debconf-set-selections
RUN echo debconf shared/accepted-oracle-license-v1-1 select true | debconf-set-selections
RUN echo debconf shared/accepted-oracle-license-v1-1 seen true | debconf-set-selections
RUN apt-get install -y oracle-java8-installer



ARG RABBITMQ_HOST=127.0.0.1
ARG MONOG_HOST=127.0.0.1
ARG RELESE_VERSION=0.1
ARG CERTS=/etc/grid-security/certificates

#Install provisioner
WORKDIR /root/
RUN mkdir /root/drip-provisioner/
WORKDIR /root/drip-provisioner/
RUN wget https://raw.githubusercontent.com/EGI-FCTF/fedcloud-userinterface/master/fedcloud-ui.sh
RUN chmod +x fedcloud-ui.sh
RUN ./fedcloud-ui.sh
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-provisioner-1.0-SNAPSHOT-jar-with-dependencies.jar
RUN echo rabbitmq.host=$RABBITMQ_HOST > provisioner.properties
RUN echo trusted.certificates.folder=$CERTS > provisioner.properties
RUN echo domain.info.path=/root/drip-provisioner/ > provisioner.properties
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/database.tar.gz
RUN tar -xzvf database.tar.gz

# Install planner
WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-planner.tar.gz
RUN tar -xzvf drip-planner.tar.gz

# Install deployer
WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-deployer.tar.gz
RUN tar -xzvf drip-deployer.tar.gz


##install drip-manager
WORKDIR /root
# RUN wget http://www-eu.apache.org/dist/tomcat/tomcat-7/v7.0.75/bin/apache-tomcat-7.0.75.tar.gz
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/0.1/apache-tomcat-7.0.75.tar.gz
RUN tar -xzf apache-tomcat-7.0.75.tar.gz
WORKDIR apache-tomcat-7.0.75
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-api-1.0-SNAPSHOT.tar.gz 
RUN tar -xzvf drip-api-1.0-SNAPSHOT.tar.gz
RUN sed -ie "s/^message.broker.host=.*/message.broker.host=$RABBITMQ_HOST/" drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN sed -ie "s/^db.host=.*/db.host=$MONOG_HOST/" drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN cat drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN mv drip-api-1.0-SNAPSHOT webapps/drip-api




# Build startAll 
WORKDIR /root
RUN mkdir -p /data/db
RUN echo "echo Strating Rabbitmq Server" >> startAll.sh
RUN echo "rabbitmq-server -detached" >> startAll.sh
RUN echo "echo Strating MongoDB" >> startAll.sh
RUN echo "mongod --smallfiles --fork --syslog" >> startAll.sh
RUN echo "sleep 1" >> startAll.sh
RUN echo "echo Strating Provisioner" >> startAll.sh
RUN echo "screen -L -dmS provisioner java -jar /root/drip-provisioner/drip-provisioner-1.0-SNAPSHOT-jar-with-dependencies.jar /root/drip-provisioner/provisioner.properties" >> startAll.sh
RUN echo "cat drip-provisioner.out" >> startAll.sh
RUN echo "echo Strating Planner" >> startAll.sh
RUN echo "screen -L -dmS planner python drip-planner/rpc_server.py 127.0.0.1" >> startAll.sh
RUN echo "cat drip-planner.out" >> startAll.sh
RUN echo "echo Strating Deployer" >> startAll.sh
RUN echo "screen -L -dmS deployer python drip-deployer/rpc_server.py 127.0.0.1" >> startAll.sh
RUN echo "cat drip-deployer.out" >> startAll.sh
RUN echo "sleep 10"
RUN echo "echo Adding admin account" >> startAll.sh
RUN echo mongo -eval "'"'db.user.insert({"password":"$2a$10$QdysFgsH0sl6Y4BD84UhGO7yyNfoDPXjjEHkDJ3pX6cRfHDj2Q0BO","roles":["ADMIN"],"username":"admin","accountNonExpired":true,"accountNonLocked":true,"credentialsNonExpired":true,"enabled":true})'"'" localhost/drip >> startAll.sh
RUN echo "/root/apache-tomcat-7.0.75/bin/startup.sh" >> startAll.sh
RUN echo "sleep 10" >> startAll.sh
RUN echo "tail -f /root/apache-tomcat-7.0.75/logs/catalina.out" >> startAll.sh

EXPOSE 8080
RUN chmod +x startAll.sh
ENTRYPOINT ./startAll.sh

# docker build -t drip .
# docker run --name drip-inst -d drip -p 127.0.0.1:8080:8080
# docker run -it --rm -p 127.0.0.1:8080:8080 drip
