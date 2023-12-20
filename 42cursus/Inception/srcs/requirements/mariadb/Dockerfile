FROM debian:buster

WORKDIR /etc/mysql
COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
CMD ["mysqld"]