#!/bin/bash

if [[ $1 =~ ^([0-9]{2}-[0-9]{3})$ ]]; then
        echo "$1 - kod pocztowy"

elif [[ $1 =~ ^([A-ZĄŚĆÓŻŹ]{1}[a-ząśćóżź]+)$ ]]; then
        echo "$1 - imie"

elif [[ $1 =~ ^[A-Za-z0-9\!\@\#\$\%\^\&\*\(\)\_\-\+\=]*@[a-z\.]+$ ]]; then
        echo "$1 - email"
else
	echo "Nie wiem co to"
fi
