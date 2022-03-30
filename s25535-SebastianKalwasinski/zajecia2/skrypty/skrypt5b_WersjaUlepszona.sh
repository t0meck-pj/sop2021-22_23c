#!/bin/bash

x=`echo $* | sed "s/\s//g"`
y=${#x}
z=$((y-1))

echo 'Twój tekst: '$* | sed s/SOP/`echo -e "\e[32mSOP\e[0m"`/g
echo "Ilość wyrazów:" ${#*}
echo "Pierwszy znak:" ${x:0:1}
echo "Ostatni znak:" ${x:z:1}

