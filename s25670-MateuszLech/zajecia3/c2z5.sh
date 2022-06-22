#!/bin/bash

# w normalnej kolejnosci 
normalnie(){
        for ((i = 0; i < $dlugosc; i++)); do
                local wynik=${string:i:1}
                printf "$wynik"
        done
        printf "\n"
        }

# w odwrotnej kolejnosci
odwrotnie(){
        for ((i = $dlugosc; i >= 0; i--)); do
                local wynik=${string:i:1}
                printf "$wynik"
        done
        printf "\n"
        }
        
# czytaj plik
czytaj(){
        string=
        while read linia; do
                string=$string$linia
        done < $1
        dlugosc=${#string}
        }
        
# wyswietl
for i in $*; do
        czytaj $i
        normalnie
        odwrotnie
        printf "\n"
done
