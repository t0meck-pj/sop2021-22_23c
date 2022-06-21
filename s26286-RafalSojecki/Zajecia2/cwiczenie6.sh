#!/bin/bash
# Napisz skrypt, który wczyta jako argument jakiś tekst. Skrypt 
# ten wypisze kolejno:
# Pierwszy znak z argumentu
# Ostatni znak z argumentu
# Zamieni w argumencie każdy tekst SOP na tekst poniżej (zastosuj
# echo z przełącznikiem -e):
# \e[32mSOP\e[0m
# Przykładowy tekst testowy:
# SOP! SOP w imieniu prawa! SOP w imieniu prawa!
# Wynikowo ma to wyglądać tak:
# SOP! SOP w imieniu prawa! SOP w imieniu prawa!

NAME=$1
if [ "${NAME: -1}" == "a" ];then
	FEMALEVARIANT=$(echo "$NAME" | sed s/a$/ę/g | sed 's/\([^ę]\)$/\1a/g')
    echo "$NAME ma kota, a kot ma ${FEMALEVARIANT}."
else
    MALEVARIANT=$(echo "$NAME" | sed s/a$/*/g | sed 's/\([^ę]\)$/\1a/g')
    echo "$NAME ma kota, a kot ma ${MALEVARIANT}."
fi
