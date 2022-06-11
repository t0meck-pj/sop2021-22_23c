#!/bin/bash

adresEmail=${1}

iloscLiter=${#imie}

if [[ ${adresEmail} =~ [A-Za-z0-9]+@[a-z]+.[a-z] ]]; then
        echo Adres email jest dobrze zapisany
elif [[ ${adresEmail} =~ [A-Za-z0-9]+_[A-Za-z0-9]+@[a-z]+.[a-z] ]]; then
        echo Adres email jest dobrze zapisany
elif [[ ${adresEmail} =~ [A-Za-z0-9]+-[A-Za-z0-9]+@[a-z]+.[a-z] ]]; then
        echo Adres email jest dobrze zapisany

else    echo Adres email jest zle zapisany

fi


