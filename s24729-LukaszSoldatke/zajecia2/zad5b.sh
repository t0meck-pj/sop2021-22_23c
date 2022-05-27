#!/bin/bash

str=$1
length=${#str}

echo "Pierwszy znak:" ${str:0:1}
echo "Ostatni znak:" ${str:$(($length-1)):1}
echo "Tekst:" $str

if [ "$str" == "SOP" ]; then
	echo -e ${str/SOP/"\e[32mSOP\e[0m"}
fi
