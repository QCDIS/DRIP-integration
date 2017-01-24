# Pull base image  
FROM nginx:latest

MAINTAINER S. Koulouzis "S.Koulouzis@uva.nl"


RUN apt-get update && apt-get upgrade -y

WORKDIR /etc/nginx
COPY nginx.conf /etc/nginx
RUN mkdir /etc/nginx/sites-enabled/
COPY *_server_block /etc/nginx/sites-enabled/


ENTRYPOINT nginx && tail -f /dev/null

#CMD tail -f /dev/null 