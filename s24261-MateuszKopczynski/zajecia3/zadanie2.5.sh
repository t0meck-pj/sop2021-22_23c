#!/bin/bash

for i in $@; do
    filename="$(basename $i)"

    if [ -s $i ]; then
       echo -e "\n Plik $filename od poczatku: \n"
       cat $i

       echo -e "\n Plik $filename od konca: \n"
       cat $i | rev
    else
       echo -e "\n Plik $filename nie istnieje \n"
    fi
done
