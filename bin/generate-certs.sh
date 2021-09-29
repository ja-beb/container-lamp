#!/bin/bash
# Generate ssl certificates for both the site and cdn server. used by proxy server.

# create dirctory structure
if [ ! -z ./ssl ]
then
    mkdir ssl
fi

# Generate ssl certificates for site 
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ssl/site.key -out ssl/site.crt
openssl dhparam -out ssl/site-dhparam.pem 2048

# Generate ssl certificates for cdn 
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ssl/cdn.key -out ssl/cdn.crt
openssl dhparam -out ssl/cdn-dhparam.pem 2048
