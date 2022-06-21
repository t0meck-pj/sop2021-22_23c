#!/bin/bash

if [[ $1 =~ ^[A-Z][^0-9]* ]]; then
	echo "Imie $1 jest poprawne!";

elif [[ $1 =~ "\d{2}-\d{3}" ]]; then
  echo "Kod $1 jest poprawny!";

elif [[ $1 =~ ^(.+)@(.+)$ ]];then
  echo "Adres e-mail: $1 jest poprawny";
fi
