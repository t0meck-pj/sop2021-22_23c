#!/bin/bash

ilosc=${#}

echo "Ilość = $ilosc"

for i in "$@"; do
	echo $i
done

echo "==="

for j in "$*"; do
	echo $j
done

