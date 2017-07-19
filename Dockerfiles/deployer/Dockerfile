# Pull base image  
FROM ubuntu:16.04


# ARG RABBITMQ_HOST=127.0.0.1
ARG RELESE_VERSION=0.2


ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get upgrade -y
RUN apt-get install -y wget software-properties-common python-pip 

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




WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-deployer.tar.gz
RUN tar -xzvf drip-deployer.tar.gz

ENTRYPOINT sleep 10 && \
 python /root/drip-deployer/rpc_server.py $RABBITMQ_HOST

# docker build -t drip-deployer .
# docker run -e RABBITMQ_HOST=172.17.0.2 drip-deployer 

