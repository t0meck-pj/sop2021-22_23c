#!/bin/bash

x=${#1}
y=$((x-1))

echo "Twój tekst: " "$1"
echo "Długość tekstu: ""${#1}"
echo "Pierwszy znak tekstu: "${1:0:1}
echo "Ostatni znak tekstu: "${1:y:1}

if [ "$1" == "SOP" ]; then
	echo -e "\e[32mSOP\e[0m"
fi

