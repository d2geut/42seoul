FROM debian:buster

RUN apt-get update -y && \
apt-get upgrade -y && \
apt-get -y install nginx openssl vim
COPY ./conf/default /var/www/html/default
COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]