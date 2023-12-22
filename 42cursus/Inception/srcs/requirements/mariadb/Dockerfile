FROM debian:buster

RUN apt-get update -y && \
apt-get upgrade -y && \
apt-get -y install mariadb-server vim
WORKDIR /etc/mysql
COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
CMD ["mysqld"]