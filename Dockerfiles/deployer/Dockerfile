# Pull base image  
FROM ubuntu:16.04


# ARG RABBITMQ_HOST=127.0.0.1
ARG RELESE_VERSION=3.0-pre-alpha
# ARG RELESE_VERSION

ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get upgrade -y 
RUN apt-get update -y 
RUN apt-get install -y wget software-properties-common python2.7 python-pip inetutils-ping

RUN pip2 install --upgrade pip
RUN pip2 install pydot
RUN pip2 install numpy
RUN pip2 install networkx==1.10
RUN pip2 install flask
RUN pip2 install tosca-parser
RUN pip2 install pika==0.10.0
RUN export LC_ALL="en_US.UTF-8"
RUN pip2 install paramiko==2.0.2
RUN pip2 install ansible==2.2.2.0
RUN pip2 install python_logging_rabbitmq
RUN pip2 install virtualenv





WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip-deployer.tar.gz
RUN wget https://github.com/QCAPI-DRIP/DRIP-integration/releases/download/$RELESE_VERSION/drip-deployer.tar.gz
RUN tar -xzvf drip-deployer.tar.gz


ENTRYPOINT tail -f /dev/null
# ENTRYPOINT sleep 10 && \ 
#     source /root/drip-deployer/venv/bin/activate && \
#     python2.7 /root/drip-deployer/rpc_server.py $RABBITMQ_HOST

# docker build -t drip-deployer .
# docker run -e RABBITMQ_HOST=172.17.0.2 drip-deployer 

