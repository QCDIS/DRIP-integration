# Pull base image  
FROM ubuntu:16.04

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

ARG RELESE_VERSION=3.0-pre-alpha
# ARG RELESE_VERSION

ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN add-apt-repository ppa:deadsnakes/ppa
RUN apt-get update -y
RUN apt-get upgrade -y 
RUN apt-get install -y wget software-properties-common libssl-dev libffi-dev python3.6 python3.6-dev python3.6-pip

# Install python stuff
RUN pip3 install --upgrade pip
RUN pip3 install pydot
RUN pip3 install numpy
RUN pip3 install networkx==1.10
RUN pip3 install flask
RUN pip3 install tosca-parser==1.5.0
RUN pip3 install pika==0.11.2
RUN export LC_ALL="en_US.UTF-8"
RUN pip3 install paramiko
RUN pip3 install python_logging_rabbitmq
RUN pip3 install names



# Install planner
WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-planner.tar.gz
RUN tar -xzvf drip-planner.tar.gz

ENTRYPOINT sleep 10 && python3.6 /root/drip_planner2/src/rpc_server.py $RABBITMQ_HOST planner_queue

# docker build -t drip-planner .
# docker run -e RABBITMQ_HOST=172.17.0.2 drip-planner
