# Pull base image  
FROM ubuntu:latest

MAINTAINER Huan "h.zhou@uva.nl"

ARG release_version=0.0.3

WORKDIR /root/

#install openssh and wget
RUN apt-get update && apt-get upgrade -y

RUN apt-get install openssh-server -y
RUN apt-get install wget -y
RUN apt-get install git -y
RUN apt-get install inetutils-ping -y
RUN apt-get install software-properties-common -y 

##install jdk 1.8
ENV DEBIAN_FRONTEND=noninteractive
RUN echo debconf shared/accepted-oracle-license-v1-1 select true | debconf-set-selections
RUN echo debconf shared/accepted-oracle-license-v1-1 seen true | debconf-set-selections
RUN add-apt-repository -y ppa:webupd8team/java
RUN apt-get update
RUN apt-get install -y oracle-java8-set-default

##install apache
RUN wget https://archive.apache.org/dist/tomcat/tomcat-6/v6.0.45/bin/apache-tomcat-6.0.45.tar.gz
RUN tar -xzf apache-tomcat-6.0.45.tar.gz
RUN rm apache-tomcat-6.0.45.tar.gz

##install paramiko
RUN apt-get install build-essential libssl-dev libffi-dev python-dev -y
WORKDIR /root/
RUN wget https://bootstrap.pypa.io/get-pip.py
RUN python get-pip.py
RUN export LC_ALL="en_US.UTF-8"
RUN pip2.7 install paramiko

#install SWITCH jar files
RUN git clone https://github.com/zh9314/SWITCH.git
WORKDIR /root/SWITCH/bin
RUN wget https://github.com/zh9314/SimplePlanner/releases/download/$release_version/Planner.jar   
RUN wget https://github.com/zh9314/EC2ProvisioningTool/releases/download/$release_version/EC2Provision.jar
RUN wget https://github.com/zh9314/ExoGENIProvisioningTool/releases/download/$release_version/ExoGENIProvision.jar
RUN wget https://github.com/zh9314/ProvisioningToolCore/releases/download/$release_version/ProvisioningCore.jar
RUN wget https://github.com/zh9314/ShClean/releases/download/$release_version/ShFileClean.jar
RUN git clone https://github.com/zh9314/SWITCH_lib.git ./lib
RUN git clone https://github.com/oceanshy/Deployment-Agent.git ./deploy
WORKDIR /root/apache-tomcat-6.0.45/webapps/
RUN wget https://github.com/zh9314/REST_Provisioner/releases/download/$release_version/REST_Provisioner.war

WORKDIR /root/
      
ENTRYPOINT sh /root/SWITCH/bin/start.sh
