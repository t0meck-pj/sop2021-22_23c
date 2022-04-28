#!/bin/bash

if [[ $1 =~ ^([0-9]{2}-[0-9]{3})$ ]]; then
	echo "$1 Jest kodem pocztowym"

elif [[ $1 =~ ^([A-ZĄŚĆÓŻŹ]{1}[a-ząśćóżź]*)$ ]]; then
	echo "$1 To tekst który może być imieniem"

elif [[ $1 =~ ^[A-Za-z0-9\!\@\#\$\%\^\&\*\(\)\_\-\+\=]*@[a-z\.]*$ ]]; then
	echo "$1 To email."

else
	echo "Warunki nie zostały spełnione, lub nie podano argumentu."
fi

