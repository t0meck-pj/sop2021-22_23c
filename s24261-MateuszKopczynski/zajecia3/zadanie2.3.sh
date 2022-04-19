#!/bin/bash

dirsAndFiles=$(ls)

for i in $dirsAndFiles; do
    if [ -d $i ]; then
       echo $i
    fi

    if [ -f $i ]; then
       echo "Patrzcie Państwo, oto plik: $i"
    fi
done
