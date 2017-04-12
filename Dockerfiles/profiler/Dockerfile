# Pull base image  
FROM ansible/centos7-ansible:stable

RUN yum update 
RUN yum upgrade
RUN ssh-keygen -q -t rsa -N '' -f /root/.ssh/id_rsa
RUN ssh-agent bash
RUN ssh-add ~/.ssh/id_rsa


ENTRYPOINT tail -f /dev/null

# docker build -t drip-profiler .
# docker run --name drip-profiler-inst -d drip-profiler
