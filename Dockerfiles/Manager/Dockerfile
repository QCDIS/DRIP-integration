FROM ubuntu:latest

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

##install java
ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends openjdk-8-jdk
RUN apt-get upgrade -y
RUN apt-get install -y wget git


##install drip-manager
WORKDIR /root
RUN wget http://www-eu.apache.org/dist/tomcat/tomcat-7/v7.0.75/bin/apache-tomcat-7.0.75.tar.gz
RUN tar -xzf apache-tomcat-7.0.75.tar.gz
WORKDIR apache-tomcat-7.0.75
RUN echo
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-api-1.0-SNAPSHOT.tar.gz 
RUN tar -xzvf drip-api-1.0-SNAPSHOT.tar.gz

ARG RABBITMQ_HOST=172.17.0.2
ARG MONOG_HOST=172.17.0.3
RUN sed -ie "s/^message.broker.host=.*/message.broker.host=$RABBITMQ_HOST/" drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN sed -ie "s/^db.host=.*/db.host=$MONOG_HOST/" drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN cat drip-api-1.0-SNAPSHOT/WEB-INF/classes/drip.properties
RUN mv drip-api-1.0-SNAPSHOT webapps/drip-api

WORKDIR /root
RUN echo "./apache-tomcat-7.0.75/bin/startup.sh" >> startAll.sh
RUN echo "tail -f ./apache-tomcat-7.0.75/logs/catalina.out" >> startAll.sh
RUN echo "while true" >> startAll.sh
RUN echo "do" >> startAll.sh
RUN echo "sleep 10s" >> startAll.sh
RUN echo "done" >> startAll.sh


EXPOSE 8080
RUN chmod +x startAll.sh
ENTRYPOINT ./startAll.sh

# To build: docker build -t drip-manager .
# To run: docker run --name drip-manager-inst -p 127.0.0.1:8080:8080 -d drip-manager

