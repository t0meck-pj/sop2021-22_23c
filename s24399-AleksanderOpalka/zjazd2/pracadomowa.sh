#!/bin/bash

#wywolanie ->
#./pracadomowa.sh "$(<tekst.txt)"

echo "$1" | sed -e "s/Aleksander/\x1b[31mAleksander\x1b[0m/g"
