FROM ubuntu:latest

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

##install java
ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends openjdk-8-jdk
RUN apt-get upgrade -y
RUN apt-get install -y mongodb mongodb-server openssh-server wget git inetutils-ping software-properties-common build-essential libssl-dev libffi-dev python-dev graphviz graphviz-dev python-dev python-pip screen rabbitmq-server

RUN pip install --upgrade pip
RUN pip install pydot
RUN pip install numpy
RUN pip install networkx==1.10
RUN pip install flask
RUN pip install tosca-parser
RUN pip install pika
RUN export LC_ALL="en_US.UTF-8"
RUN pip install paramiko



##install drip-manager
WORKDIR /root
RUN wget http://www-eu.apache.org/dist/tomcat/tomcat-7/v7.0.75/bin/apache-tomcat-7.0.75.tar.gz
RUN tar -xzf apache-tomcat-7.0.75.tar.gz
WORKDIR apache-tomcat-7.0.75
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-api-1.0-SNAPSHOT.tar.gz 
RUN tar -xzvf drip-api-1.0-SNAPSHOT.tar.gz
RUN mv drip-api-1.0-SNAPSHOT webapps/drip-api

WORKDIR /root
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-provisioner-1.0-SNAPSHOT-jar-with-dependencies.jar
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-planner.tar.gz
RUN tar -xzvf drip-planner.tar.gz
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-deployer.tar.gz
RUN tar -xzvf drip-deployer.tar.gz

RUN mkdir -p /data/db

RUN echo "rabbitmq-server -detached" >> startAll.sh
RUN echo "mongod --fork --syslog" >> startAll.sh
RUN echo "./apache-tomcat-7.0.75/bin/startup.sh" >> startAll.sh

#----------------Wait for rabbitmq----------------------------------
RUN echo "sleep 30"
RUN echo "screen -d -m java -jar drip-provisioner-1.0-SNAPSHOT-jar-with-dependencies.jar" >> startAll.sh
RUN echo "screen -d -m python drip-planner/rpc_server.py" >> startAll.sh
RUN echo "screen -d -m python drip-deployer/rpc_server.py" >> startAll.sh
# RUN echo exec mongo -eval "'"'db.user.insert({"password":"$2a$10$QdysFgsH0sl6Y4BD84UhGO7yyNfoDPXjjEHkDJ3pX6cRfHDj2Q0BO","roles":["ADMIN"],"username":"admin","accountNonExpired":true,"accountNonLocked":true,"credentialsNonExpired":true,"enabled":true})'"'" localhost/drip >> startAll.sh
RUN echo "while true" >> startAll.sh
RUN echo "do" >> startAll.sh
RUN echo "sleep 10s" >> startAll.sh
RUN echo "done" >> startAll.sh
RUN echo "tail -f apache-tomcat-7.0.75/logs/catalina.out"

EXPOSE 8080
RUN chmod +x startAll.sh
ENTRYPOINT ./startAll.sh

# To Build: docker build -t drip .
# To Run: docker run --name drip-inst -p 127.0.0.1:8080:8080 -d drip
# Add Admin account: docker exec -t drip-inst mongo -eval 'db.user.insert({"password":"$2a$10$QdysFgsH0sl6Y4BD84UhGO7yyNfoDPXjjEHkDJ3pX6cRfHDj2Q0BO","roles":["ADMIN"],"username":"admin","accountNonExpired":true,"accountNonLocked":true,"credentialsNonExpired":true,"enabled":true})' localhost/drip