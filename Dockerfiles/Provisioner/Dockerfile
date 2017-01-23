# Pull base image  
FROM ubuntu:14.04

MAINTAINER Huan "h.zhou@uva.nl"

ARG release_version=0.0.2

WORKDIR /root/

#install openssh and wget
RUN apt-get update
RUN apt-get install openssh-server -y
RUN apt-get install wget -y
RUN apt-get install git -y

##install jdk 1.8
RUN wget --no-cookies --no-check-certificate --header "Cookie: oraclelicense=accept-securebackup-cookie;" http://download.oracle.com/otn-pub/java/jdk/8u74-b02/jdk-8u74-linux-x64.tar.gz
RUN tar -xzf jdk-8u74-linux-x64.tar.gz
ENV JAVA_HOME /root/jdk1.8.0_74
ENV PATH $PATH:$JAVA_HOME/bin
RUN rm jdk-8u74-linux-x64.tar.gz

##install apache
RUN wget https://archive.apache.org/dist/tomcat/tomcat-6/v6.0.45/bin/apache-tomcat-6.0.45.tar.gz
RUN tar -xzf apache-tomcat-6.0.45.tar.gz
RUN rm apache-tomcat-6.0.45.tar.gz


#install SWITCH jar files
RUN git clone https://github.com/zh9314/SWITCH.git
WORKDIR /root/SWITCH/bin
RUN wget https://github.com/zh9314/EC2ProvisioningTool/releases/download/$release_version/EC2Provision.jar
RUN wget https://github.com/zh9314/ExoGENIProvisioningTool/releases/download/$release_version/ExoGENIProvision.jar
RUN wget https://github.com/zh9314/ProvisioningToolCore/releases/download/$release_version/ProvisioningCore.jar
RUN git clone https://github.com/zh9314/SWITCH_lib.git ./lib
WORKDIR /root/apache-tomcat-6.0.45/webapps/
RUN wget https://github.com/zh9314/REST_Provisioner/releases/download/$release_version/REST_Provisioner.war

WORKDIR /root/
      
ENTRYPOINT sh /root/SWITCH/bin/start.sh
