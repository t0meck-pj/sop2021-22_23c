#!/bin/bash

if [[ $(ls -p | grep -v / | wc -l) -gt 5 ]]; then
echo "W biezacym katalogu jest wiecej niz 5 plikow"
fi
