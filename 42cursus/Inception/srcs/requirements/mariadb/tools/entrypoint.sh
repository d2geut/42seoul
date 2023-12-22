#!/bin/bash

echo "== START MARIADB SETTING =="

sed -i "s/bind-address.*/bind-address = 0.0.0.0/" /etc/mysql/mariadb.conf.d/50-server.cnf
sed -i "s/password =/password = $DB_ROOT_PASS/g" /etc/mysql/debian.cnf
mkdir -p /var/run/mysqld
chown -R mysql:mysql /var/lib/mysql /var/run/mysqld

service mysql start
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" | mysql -u root -p$DB_ROOT_PASS
echo "CREATE USER IF NOT EXISTS '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" | mysql -u root -p$DB_ROOT_PASS
echo "GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_USER'@'%';" | mysql -u root -p$DB_ROOT_PASS
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';" | mysql -u root -p$DB_ROOT_PASS
echo "FLUSH PRIVILEGES;" | mysql -u root -p$DB_ROOT_PASS
service mysql stop

echo "== FINISH MARIADB SETTING =="
exec "$@"