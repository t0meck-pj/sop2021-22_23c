#!/bin/bash

if [[ -f config.cfg ]]; then
./config.cfg
elif [ ! -f config.cfg ] && [ $# -gt 0 ]; then
./$1
else
echo "Blad - config.cfg nie istnieje i nie podano parametru"
fi
