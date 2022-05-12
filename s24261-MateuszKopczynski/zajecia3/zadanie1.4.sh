#!/bin/bash

files=$(ls -p | grep -vc /)

if [ $files -gt "5" ]; then
   echo "Jest wiecej niz 5 plikow"
else
   echo "Jest mniej niz 5 plikow"
fi
