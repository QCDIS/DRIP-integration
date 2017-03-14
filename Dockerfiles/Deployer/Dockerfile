# Pull base image  
FROM ubuntu:latest

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
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/beta/drip-deployer.tar.gz
RUN tar -xzvf drip-deployer.tar.gz

WORKDIR drip-deployer
ENTRYPOINT python rpc_server.py 172.17.0.2

# docker build -t drip-deployer .
# docker run --name drip-deployer-inst -d drip-deployer
