#!/bin/bash

echo "== START NGINX SETTING =="

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt \
		-subj "/C=KR/ST=Seoul/L=Gaepo/O=42/OU=seoul/CN=hanryu/emailAddress=hanryu@gmail.com"

yes | cp -f /var/www/html/default /etc/nginx/sites-available/default

echo "== FINISH NGINX SETTING =="
exec "$@"