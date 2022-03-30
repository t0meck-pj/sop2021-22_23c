#!/bin/bash
name=$1

echo "pierwszy: ${name:0:1}"
echo "ostatni: ${name: -1}"

if [ ${name} = "SOP" ]; then
	echo -e "\e[32mSOP\e[0m"
else 
	echo $name
fi
