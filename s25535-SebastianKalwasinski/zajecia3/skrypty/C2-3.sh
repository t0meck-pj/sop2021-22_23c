#!/bin/bash

green=$(echo -e "\e[32m")
lblue=$(echo -e "\e[94m")
k0=$(echo -e "\e[0m")

Pliki=$(find . -maxdepth 1 -type f | sed s/\\.\\///g)
Katalogi=$(find . -maxdepth 1 ! -path . -type d | sed s/\\.\\///g)

for i in ${Pliki}; do
	echo "Paczaj na plika: ${lblue}${i}${k0}"
done

for i in ${Katalogi}; do
	echo "Paczaj na kataloga: ${green}${i}${k0}"
done

