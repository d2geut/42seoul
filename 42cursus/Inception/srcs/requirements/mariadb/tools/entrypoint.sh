#!/bin/bash

echo "== START MARIADB SETTING =="
apt-get update -y && \
apt-get upgrade -y && \
apt-get -y install mariadb-server \
vim

sed -i "s/bind-address.*/bind-address = 0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf

service mysql start
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';" | mysql -uroot -p$DB_ROOT_PASS	# 최초 1회는 암호를 변경해야 root를 사용할 수 있음
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME" | mysql -uroot -p$DB_ROOT_PASS
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" | mysql -uroot -p$DB_ROOT_PASS
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';" | mysql -uroot -p$DB_ROOT_PASS
echo "FLUSH PRIVILEGES;" | mysql -uroot -p$DB_ROOT_PASS
service mysql stop

echo "== FINISH MARIADB SETTING =="
exec "$@"