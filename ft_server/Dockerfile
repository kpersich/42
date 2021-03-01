FROM debian:buster
RUN apt-get update -y
RUN apt-get upgrade -y

RUN apt install nginx -y
RUN apt install wget -y
RUN apt install mariadb-server mariadb-client -y

#install phpMyAdmin
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring php-gettext
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN tar xvf phpMyAdmin-5.0.4-english.tar.gz
RUN mv phpMyAdmin-5.0.4-english /var/www/html/phpmyadmin
RUN rm -rf phpMyAdmin-5.0.4-english.tar.gz
#install wordpress
RUN wget -c https://it.wordpress.org/latest-it_IT.tar.gz -O - | tar -xz -C .
RUN mv wordpress var/www/html/
RUN rm -rf wordpress-5.6.2-it_IT

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=GB/ST=Rome/L=Rome/O=Global Security/OU=IT Department/CN=localhost" -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt
COPY ./srcs/config.inc.php  /var/www/html/phpmyadmin
COPY ./srcs/default etc/nginx/sites-available
COPY ./srcs/wp-config.php /var/www/html/wordpress
COPY ./srcs/init.sh /
COPY ./srcs/autoindex /bin
RUN chmod 777 /bin/autoindex
RUN mkdir /var/www/html/phpmyadmin/tmp/
RUN chmod 777 /var/www/html/phpmyadmin/tmp/
RUN rm /var/www/html/index.nginx-debian.html 
CMD bash init.sh