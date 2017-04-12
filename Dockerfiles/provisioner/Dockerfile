# Pull base image  
FROM ubuntu:latest

MAINTAINER Huan "h.zhou@uva.nl"

ARG release_version=0.0.3

WORKDIR /root/

#install openssh and wget
RUN apt-get update && apt-get upgrade -y

RUN apt-get install openssh-server wget software-properties-common inetutils-ping -y

##install jdk 1.8
ENV DEBIAN_FRONTEND=noninteractive
RUN echo debconf shared/accepted-oracle-license-v1-1 select true | debconf-set-selections
RUN echo debconf shared/accepted-oracle-license-v1-1 seen true | debconf-set-selections
RUN add-apt-repository -y ppa:webupd8team/java
RUN apt-get update
RUN apt-get install -y oracle-java8-set-default

RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-provisioner-1.0-SNAPSHOT-jar-with-dependencies.jar

ARG RABBITMQ_HOST=172.17.0.1
WORKDIR /root
RUN echo rabbitmq.host=$RABBITMQ_HOST > provisioner.properties
RUN cat provisioner.properties
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/database.tar.gz
RUN tar -xzvf database.tar.gz

ENTRYPOINT java -jar drip-provisioner-1.0-SNAPSHOT-jar-with-dependencies.jar /root/provisioner.properties

#Build: docker build -t drip-pro .
# Run: docker run --name drip-pro-inst -d drip-pro
