#!/bin/bash

plik="config.cfg"
argument=$1

red=`echo -e "\e[31m"`
k0=`echo -e "\e[0m"`


if [[ -e $plik ]]; then
	echo -e `./$plik`

elif [[ -e $argument ]]; then
	echo -e `./$argument`

else
	echo "${red}Nie ma takiego pliku${k0}"
fi

