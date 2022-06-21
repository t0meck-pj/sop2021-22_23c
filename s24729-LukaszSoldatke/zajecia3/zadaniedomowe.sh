#!/bin/bash

IMIE="^[a-zA-Z]+(([',. -][a-zA-Z ])?[a-zA-Z]*)*$"
KODPOCZTOWY="^[0-9][0-9]\-[0-9][0-9][0-9]$"
EMAIL="^[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,3}$"

if [[ $1 =~ $IMIE ]]; then echo "imie"
elif [[ $1 =~ $KODPOCZTOWY ]]; then echo "kod pocztowy"
elif [[ $1 =~ $EMAIL ]]; then echo "e-mail"
else echo "Tekst nie pasuje do zadnego z wzorcow"
fi
