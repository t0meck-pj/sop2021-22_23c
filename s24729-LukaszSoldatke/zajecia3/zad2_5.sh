#!/bin/bash

for i in $@; do
	if [ -f $i ]; then
		echo -e "Zawartosc pliku $i:\n"
		cat $i
		echo -e "\n"
		echo -e "Zawartosc pliku $i ale od tylu:\n"
		tac $i
	else
		echo -e "\nNie ma pliku $i"
	fi
done
