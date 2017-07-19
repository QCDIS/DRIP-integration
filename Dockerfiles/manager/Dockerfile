FROM ubuntu:16.04

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"


# ARG RABBITMQ_HOST=127.0.0.1
# ARG MONOG_HOST=127.0.0.1
ARG RELESE_VERSION=0.2
ARG CERTS=/etc/grid-security/certificates


##install java
ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get upgrade -y
RUN apt-get install -y wget software-properties-common mongodb-clients openssh-client
RUN add-apt-repository -y ppa:webupd8team/java
RUN apt-get update
RUN "oracle-java8-installer shared/accepted-oracle-license-v1-1 select true" | debconf-set-selections
RUN echo debconf shared/accepted-oracle-license-v1-1 select true | debconf-set-selections
RUN echo debconf shared/accepted-oracle-license-v1-1 seen true | debconf-set-selections
RUN apt-get install -y oracle-java8-installer

##install drip-manager
WORKDIR /root
# RUN wget http://www-eu.apache.org/dist/tomcat/tomcat-7/v7.0.75/bin/apache-tomcat-7.0.75.tar.gz
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/0.1/apache-tomcat-7.0.75.tar.gz
RUN tar -xzf apache-tomcat-7.0.75.tar.gz
WORKDIR apache-tomcat-7.0.75
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-api-1.0-SNAPSHOT.tar.gz 
RUN tar -xzvf drip-api-1.0-SNAPSHOT.tar.gz
RUN cat drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN mv drip-api-1.0-SNAPSHOT webapps/drip-api

#Conf ssl 
WORKDIR /root
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/blob/master/conf/keystore.tar.gz?raw=true
RUN tar -xzf keystore.tar.gz

RUN wget https://raw.githubusercontent.com/QCAPI-DRIP/DRIP-integradation/master/conf/server.xml
ARG keystorePass
sed -i "s#keystoreFile=\"\${user.home\}/.keystore\" keystorePass=\"changeit\"#keystoreFile=\"\${user.home\}/.keystore\" keystorePass=\"$keystorePass\"#" server.xml



WORKDIR /root
EXPOSE 8080

# ENTRYPOINT sed -ie "s/^message.broker.host=.*/message.broker.host=$RABBITMQ_HOST/" /root/apache-tomcat-7.0.75/webapps/drip-api/WEB-INF/classes/drip.properties && sed -ie "s/^db.host=.*/db.host=$MONOG_HOST/" /root/apache-tomcat-7.0.75/webapps/drip-api/WEB-INF/classes/drip.properties && sleep 10 && /root/apache-tomcat-7.0.75/bin/shutdown.sh && /root/apache-tomcat-7.0.75/bin/startup.sh && tail -f ./apache-tomcat-7.0.75/logs/catalina.out


ENTRYPOINT sed -ie "s/^message.broker.host=.*/message.broker.host=$RABBITMQ_HOST/" /root/apache-tomcat-7.0.75/webapps/drip-api/WEB-INF/classes/drip.properties && sed -ie "s/^db.host=.*/db.host=$MONOG_HOST/" /root/apache-tomcat-7.0.75/webapps/drip-api/WEB-INF/classes/drip.properties && /root/apache-tomcat-7.0.75/bin/shutdown.sh && sleep 20 && mongo -eval 'db.user.insert({"password":"$2a$10$QdysFgsH0sl6Y4BD84UhGO7yyNfoDPXjjEHkDJ3pX6cRfHDj2Q0BO","roles":["ADMIN"],"username":"admin","accountNonExpired":true,"accountNonLocked":true,"credentialsNonExpired":true,"enabled":true})' $MONOG_HOST/drip && /root/apache-tomcat-7.0.75/bin/startup.sh && tail -f /root/apache-tomcat-7.0.75/logs/catalina.out


# To build: docker build -t drip-manager .
# To run: docker run --name drip-manager-inst -p 127.0.0.1:8080:8080 -d drip-manager

