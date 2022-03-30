#!/bin/bash

x=${#1}
y=$((x-1))
z=${1:y:1} 
a=${1:0:y}
W="\e[36m------------------------------------------------\e[0m"

echo -e $W
if [ "$z" == "a" ];then
	b=${z/a/ę}
	echo "Imie przed zmianą: "${1}
	echo "Imie po zmianie: "${a}${b}
	echo -e "\e[36mWYNIK:\e[0m ${1} ma kota a kot ma ${a}${b}."

elif [ "$z" == "n" ];then
	echo "Imie przed zmianą: "${1}
	echo "Imie po zmianie: "${1}a
	echo -e "\e[36mWYNIK:\e[0m ${1} ma kota a kot ma ${1}a."

else
	echo -e "To imie \e[31mnie pasuje\e[0m do skryptu"
fi
echo -e $W

