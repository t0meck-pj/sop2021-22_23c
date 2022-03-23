#!/bin/bash

word=$1

echo "Pierwszy znak tekstu: ${word:0:1}"
echo "Ostatni znak tekstu: ${word: -1}"

if [ $word == "SOP" ]; then
	echo -e "\e[32mSOP\e[0m"
fi
