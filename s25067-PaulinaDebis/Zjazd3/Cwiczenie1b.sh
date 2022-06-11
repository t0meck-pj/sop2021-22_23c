#!/bin/bash

X=$currentDir

if [ -e $X/config.cfg ] ; then
	cat $X/config.cfg
elif [[ $# -gt 0 ] && [ -e $X/$1 ]] ; then
	echo $X/$1
else
	echo Blad
fi

# -e istnieje, exist
# jezeli w aktualnym katalogu w ktorym sie znajdujemy istnieje plik config.cfg to go wykonaj. jezeli nie istnieje
# ale ilosc parametrow podanych jest wieksza niz zero i istnieje plik o nazwie takiej jak wartosc parametru skryptu to go wykonaj
# jezeli ani tego ani tego nie ma, wyswietl informacje o bledzie


