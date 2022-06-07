#!/bin/bash


imie=${1}

iloscLiter=${#imie}

if [[ ${imie:0:1} =~ [A-Z] && {imie:1:$iloscLiter} =~ [a-z] ]]; then
	echo Imie jest dobrze zapisane
else 	echo Imie jest zle zapisane

fi




