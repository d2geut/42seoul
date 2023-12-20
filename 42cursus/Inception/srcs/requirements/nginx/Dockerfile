FROM debian:buster

COPY ./conf/default /var/www/html/default
COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/bin/bash", "/entrypoint.sh"]
CMD ["nginx", "-g", "daemon off;"]