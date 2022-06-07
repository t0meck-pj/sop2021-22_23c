#!/bin/bash

X=$(ls -l | grep -e "^-" | awk '{print $9}')

# tworze tablice
declare -a tablica

count=0

for A in $X; do 
    tablica[$count]=$A
    (( count++ ))
done

# w normalnej kolejnosci 
for B in ${tablica[@]}; do 
    echo $B
done

# w odwrotnej kolejnosci
echo 
echo "Odwrotna kolejność"
for (( i=(( ${#tablica[@]} -1 )); i>=0; i-- )); do 
    echo ${tablica[$i]}
done
