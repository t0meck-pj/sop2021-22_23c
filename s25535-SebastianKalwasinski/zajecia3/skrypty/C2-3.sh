#!/bin/bash

green=$(echo -e "\e[32m")
lblue=$(echo -e "\e[94m")
k0=$(echo -e "\e[0m")

#Pliki=$(find . -maxdepth 1 -type f | sed s/\\.\\///g)
#Katalogi=$(find . -maxdepth 1 ! -path . -type d | sed s/\\.\\///g)
#${zmienna/"To"/"NaTo"/} - Jednorazowo 
#${zmienna//"To"/"NaTo"/} - Globalnie

Pli=$(find . -maxdepth 1 -type f)
Kat=$(find . -maxdepth 1 ! -path . -type d)

Pliki=${Pli//"./"/}
Katalogi=${Kat//"./"/}

for i in ${Pliki}; do
	echo "Paczaj na plika: ${lblue}${i}${k0}"
done

for i in ${Katalogi}; do
	echo "Paczaj na kataloga: ${green}${i}${k0}"
done

