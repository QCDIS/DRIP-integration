# Pull base image  
FROM ubuntu:latest

MAINTAINER Huan "h.zhou@uva.nl"


##install java
ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install -y wget software-properties-common build-essential libssl-dev libffi-dev python-dev graphviz graphviz-dev python-dev python-pip

RUN pip install --upgrade pip
RUN pip install pydot
RUN pip install numpy
RUN pip install networkx==1.10
RUN pip install flask
RUN pip install tosca-parser
RUN pip install pika
RUN export LC_ALL="en_US.UTF-8"
RUN pip install paramiko




WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-planner.tar.gz
RUN tar -xzvf drip-planner.tar.gz

WORKDIR drip-planner
ARG RABBITMQ_HOST=172.17.0.2
RUN echo $RABBITMQ_HOST > hostFile
ENTRYPOINT python rpc_server.py 172.17.0.2

# docker build -t drip-planner .
# docker run --name drip-planner-inst -d drip-planner
