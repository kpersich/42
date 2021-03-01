service nginx start
service mysql start
service php7.3-fpm start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;"| mysql -u root
echo "CREATE USER 'kpersich'@'localhost' IDENTIFIED BY '28041995';" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'kpersich'@'localhost' WITH GRANT OPTION;"| mysql -u root
echo "FLUSH PRIVILEGES;"| mysql -u root
echo "update mysql.user set plugin='' where user='kpersich';"| mysql -u root

bash