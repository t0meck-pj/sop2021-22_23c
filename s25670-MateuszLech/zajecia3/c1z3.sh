#!/bin/bash

if [[ ${0} =~ \.sh$ ]]; then 
    echo "Skrypt ma właściwe rozszerzenie"
else 
    echo "Zmieniona rozszerzenia na .sh"
    mv ${0} ${0}.sh
fi
