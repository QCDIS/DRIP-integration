FROM ubuntu:latest

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"

##install java
ENV DEBIAN_FRONTEND=noninteractive 
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends openjdk-8-jdk
RUN apt-get upgrade -y
RUN apt-get install -y wget git build-essential autoconf curl chrpath pkg-config \
        ncurses-dev libreadline-dev libedit-dev \
        libunwind-dev \
        libgmp-dev \
        libssl-dev \
        unixodbc-dev \
        zlib1g-dev libarchive-dev \
        libossp-uuid-dev \
        libxext-dev libice-dev libjpeg-dev libxinerama-dev libxft-dev \
        libxpm-dev libxt-dev \
        libdb-dev junit
        
# WORKDIR /root/
# RUN git clone https://github.com/SWI-Prolog/swipl-devel.git
# WORKDIR swipl-devel
# 
# RUN wget https://github.com/SWI-Prolog/swipl-devel/archive/V7.5.0.tar.gz
# RUN tar -xzvf V7.5.0.tar.gz
# WORKDIR swipl-devel-7.5.0
# RUN ./prepare --yes --all
# RUN cp -p build.templ build
# RUN ./build
# RUN cat INSTALL
# RUN swipl --version

ENTRYPOINT tail -f /dev/null

# docker build -t drip-kb .
# docker run --name drip-kb-inst -d drip-kb -p 127.0.0.1:8080:8080