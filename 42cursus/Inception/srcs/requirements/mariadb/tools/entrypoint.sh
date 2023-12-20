#!/bin/bash

echo "== START MARIADB SETTING =="
apt-get update -y && \
apt-get upgrade -y && \
apt-get -y install mariadb-server

sed -i "s/bind-address .*/bind-address = 0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf

service mysql start
echo "CREATE DATABASE IF NOT EXISTS $WORDPRESS_DB" | mysql -uroot -p"비밀번호"
echo "CREATE USER IF NOT EXISTS $DB_USER"