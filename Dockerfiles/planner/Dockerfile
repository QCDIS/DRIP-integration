# Pull base image  
FROM ubuntu:16.04

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

ARG RELESE_VERSION=3.0-pre-alpha
# ARG RELESE_VERSION

ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get update -y
RUN apt-get upgrade -y 
RUN apt-get install -y wget software-properties-common libssl-dev libffi-dev python3 python3-dev python3-pip

# Install python stuff
RUN pip install --upgrade pip
RUN pip install pydot
RUN pip install numpy
RUN pip install networkx==1.10
RUN pip install flask
RUN pip install tosca-parser
RUN pip install pika==0.11.2
RUN export LC_ALL="en_US.UTF-8"
RUN pip install paramiko
RUN pip install python_logging_rabbitmq



# Install planner
WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-planner.tar.gz
RUN tar -xzvf drip-planner.tar.gz

ENTRYPOINT sleep 10 && python /root/drip_planner2/src/rpc_server.py $RABBITMQ_HOST planner_queue

# docker build -t drip-planner .
# docker run -e RABBITMQ_HOST=172.17.0.2 drip-planner
