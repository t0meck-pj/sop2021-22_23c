#!/bin/bash


if [ -f "config.cfg" ]; then
	cat "config.cfg"
elif [[ $1 ]]; then
	echo "$1"
else
	echo "Bład!!"
fi
