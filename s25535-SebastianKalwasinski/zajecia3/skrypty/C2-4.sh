#!/bin/bash

wynik1=$(find . -maxdepth 1 -type f -iname "*.c" | sed -r s/\\.\\/\|\\.c//g)
wynik2=$(find . -maxdepth 1 -type f -iname "*.c" | sed -r s/\\.\\///g)
echo $wynik1
echo $wynik2

for i in $wynik; do
	cc $wynik2 -o $wynik1
done

