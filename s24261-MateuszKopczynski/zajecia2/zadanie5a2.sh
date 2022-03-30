#!/bin/bash

imie=$1

if [ ${imie: -1} = "a" ]; then

        echo "$imie ma kota, a kot ma ${imie::-1}ę"
else
        echo "$imie ma kota, a kot ma ${imie}a"
fi
