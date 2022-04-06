#!/bin/bash

email="^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}$"
postcode="^[0-9]{2}-[0-9]{3}"
name="[A-Z][a-zA-Z]*"

if [[ $1 =~ $email ]]; then echo "email"
elif [[ $1 =~ $postcode ]]; then echo "kod pocztowy"
elif [[ $1 =~ $name ]]; then echo "imie"
else echo "Podany tekst nie pasuje do zadnego wyrazenia"
fi
