# Pull base image  
FROM ubuntu:16.04

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

ARG RELESE_VERSION=0.2


ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get upgrade -y
RUN apt-get install -y wget git inetutils-ping software-properties-common build-essential libssl-dev libffi-dev python-dev graphviz graphviz-dev python-pip

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



# Install planner
WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-planner.tar.gz
RUN tar -xzvf drip-planner.tar.gz

ENTRYPOINT sleep 10 && python /root/drip-planner/rpc_server.py $RABBITMQ_HOST

# docker build -t drip-planner .
# docker run -e RABBITMQ_HOST=172.17.0.2 drip-planner
