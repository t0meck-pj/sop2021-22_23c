#!/bin/bash

kodPocztowy=${1}

iloscLiczb=${#kodPocztowy}

if [[ ${kodPocztowy:0:$iloscLiczb} =~ [0-9] && $iloscLiczb < 6 ]]; then
        echo Kod pocztowy jest dobrze zapisany
else    echo Kod pocztowy jest zle zapisany

fi


