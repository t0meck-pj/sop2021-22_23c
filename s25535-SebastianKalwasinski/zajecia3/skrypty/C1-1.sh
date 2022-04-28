#!/bin/bash

ilosc="$#"
pierwszy=$1

red=`echo -e "\e[31m"`
green=`echo -e "\e[32m"`
Blblue=`echo -e "\e[104m"`
k0=`echo -e "\e[0m"`

if [[ $ilosc > 1 ]]; then
	echo "${green}Pierwszy argument = $pierwszy${k0}"

elif [[ $ilosc == 1 ]]; then
	echo "${Blblue}A jak ktoś podał jeden argument to co? ${k0}"

elif [[ $ilosc == 0 ]]; then
	echo "${red}Nie podano żadnego argumentu${k0}"
fi

