#!/bin/bash

if [ -e $currentDir/config.cfg ] ; then
	$currentDir/config.cfg
elif [ $# -gt 0 ] && [ -e $currentDir/$1 ] ; then
	$currentDir/$1
else
	echo Blad
fi

# -e istnieje, exist
# jezeli w aktualnym katalogu w ktorym sie znajdujemy istnieje katalog konfig.cfg to go wyswietl. jezeli nie istnieje
# ale ilosc parametrow podanych jest wieksza niz zero i istnieje plik o nazwie takiej jak wartosc parametru skryptu to go wyswietl
# jezeli ani tego ani tego nie ma, wyswietl informacje o bledzie


