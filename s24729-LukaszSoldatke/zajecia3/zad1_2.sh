#!/bin/bash

if [[ -f config.cfg ]]; then
./config.cfg
elif [ $# -gt 0 ] && [ -f $1 ]; then
./$1
else
echo "Blad - config.cfg nie istnieje i nie podano parametru lub podany jako parametr plik nie istnieje"
fi
