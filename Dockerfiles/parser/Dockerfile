# Pull base image  
FROM ubuntu:16.04

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

ARG RELESE_VERSION=0.2.3
# ARG RELESE_VERSION

ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends 
RUN apt-get upgrade -y 
RUN apt-get update -y 
RUN apt-get install -y wget software-properties-common python-pip 

RUN pip install --upgrade pip
RUN pip install tosca-parser
RUN pip install pika
RUN export LC_ALL="en_US.UTF-8"
RUN pip install paramiko==2.0.2
RUN pip install python_logging_rabbitmq




# Install parser
WORKDIR /root/
RUN wget https://github.com/QCAPI-DRIP/DRIP-integradation/releases/download/$RELESE_VERSION/drip_parser.tar.gz
RUN tar -xzvf drip_parser.tar.gz

ENTRYPOINT sleep 10 && python /root/drip_parser/src/rpc_server.py $RABBITMQ_HOST tosca_2_docker_compose_queue

# docker build -t drip-parserr .
# docker run -e RABBITMQ_HOST=172.17.0.2 drip-parser
