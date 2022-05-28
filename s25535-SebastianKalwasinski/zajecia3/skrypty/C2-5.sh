#!/bin/bash

wczytajPlik(){
	string=
	while read linia; do
		string=$string$linia
	done < $1
	dlugosc=${#string}
	}

odPoczatku(){
	for ((i = 0; i < $dlugosc; i++)); do
		local wynik=${string:i:1}
		printf "$wynik"
	done
	printf "\n"
	}

odKonca(){
	for ((i = $dlugosc; i >= 0; i--)); do
		local wynik=${string:i:1}
		printf "$wynik"
	done
	printf "\n"
	}

#=== Tu zaczyna cos sie dziac ===#

for i in $*; do
	printf "\nPlik: $i \n"
	wczytajPlik $i
	odPoczatku
	odKonca
	printf "\n"
done

