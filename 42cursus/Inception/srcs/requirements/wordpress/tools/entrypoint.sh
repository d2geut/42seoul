#!/bin/bash

echo "== START WORDPRESS SETTING =="

service php7.3-fpm start
sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/g" /etc/php/7.3/fpm/pool.d/www.conf
sed -i "s/;clear_env = no/clear_env = no/g" /etc/php/7.3/fpm/pool.d/www.conf
if [ ! -f /var/www/html/wp-config.php ]; then
	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x wp-cli.phar
	mv wp-cli.phar /usr/bin/wp-cli.phar

	wp-cli.phar core download --allow-root --path=/var/www/html
	wp-cli.phar config create --dbname=$DB_NAME --dbuser=$DB_USER --dbpass=$DB_PASS --dbhost=$DB_HOST --allow-root --path=/var/www/html --skip-check
	wp-cli.phar core install --url=https://$DOMAIN_NAME --title=$TITLE --admin_user=$ADMIN_NAME --admin_password=$ADMIN_PASS --admin_email=$ADMIN_MAIL --allow-root --path=/var/www/html
	wp-cli.phar user create $USER_NAME $USER_MAIL --user_pass=$USER_PASS --role=author --allow-root --path=/var/www/html
fi
service php7.3-fpm stop

echo "== FINISH WORDPRESS SETTING =="
exec "$@"