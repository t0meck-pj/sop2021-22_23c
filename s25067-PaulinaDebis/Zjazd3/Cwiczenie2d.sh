#!/bin/bash

rozszerzenie="${filename##*.}"

if [ "${rozszerzenie}"  -eq "c" ]; then
    	newname="${filename%.*}"
	cc $filename -o $newname
fi

