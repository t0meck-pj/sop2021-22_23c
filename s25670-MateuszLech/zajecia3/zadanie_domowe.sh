#!/bin/bash

if [[ $1 =~ ^[0-9][0-9]+'-'+[0-9][0-9][0-9] ]]; then
	echo "Kod pocztowy"

elif [[ $1 =~ ^[A-Z][a-ząćęłńóśźż] ]]; then
	echo imię

elif [[ $1 =~ ^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$ ]]; then
	echo email

else
	echo "Nie wiem co to"
fi
