#!/bin/bash

rozszerzenie="${filename##*.}"

if [ "${rozszerzenie}"  -ne "sh" ]; then
	mv "filename" "filename.sh"
fi


