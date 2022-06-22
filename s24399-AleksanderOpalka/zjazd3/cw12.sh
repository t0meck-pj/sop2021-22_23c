#!/bin/bash

file="config.cfg"

if [[ -e $FILE ]]; then
	echo -e "$(./$FILE)"
elif [[ $1 ]]; then
	echo -e "$(./"$1")"
else
	echo "Error"
fi
