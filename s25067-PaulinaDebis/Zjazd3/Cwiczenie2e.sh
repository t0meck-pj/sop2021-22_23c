#!/bin/bash

pliki=$(ls)
znaki=$(cat $pliki)
dlugosc=${#znaki}

for (( i=0 ; i< $dlugosc ; i++ )); do
	echo "${znaki:$i:1}"
done

for (( i= $dlugosc ; i>=0 ; i-- )); do
	echo "${znaki:$i:1}"
done

