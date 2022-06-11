#!/bin/bash
# W przypadku bardzo podobnych rozwiazań nie będę ich uznawał.
# Przygotuj wyrażenie regularne, które będzie sprawdzało, czy tekst jest
# poprawnie napisanym polskim imieniem (od wielkiej litery, może mieć
# tylko litery i zawierać polskie znaki).
# Przygotuj wyrażenie regularne sprawdzające czy tekst jest kodem pocztowym
# (cały tekst, czyli zaczyna się od cyfry i kończy się cyfrą).
# Przygotuj wyrażenie regularne sprawdzające e-mail.
# Napisz skrypt który będzie pobierał jeden argument z linii komend i
# wypisywał informację o tym, czy jest to imie, kod pocztowy, czy też
# email. Na przykład
# ./coto Janusz
# imię
# ./coto 68-221
# kod pocztowy
# ./coto 'muniek+spam@gmail.com'
# email

if [[ $1 =~ ^[A-Z,Ł,Ś,Ż].* ]]; then
	echo "Imię"
elif [[ $1 =~ ^[0-9]{2}-[0-9]{3}$ ]]; then
	echo "Kod pocztowy"
elif [[ $1 =~ ^[^.][A-Za-z0-9.+!\#\$%\&\'*+-/=?\^_\`\{\}|\~]+[@]+[A-Za-z0-9]+.+[A-Za-z0-9] ]]; then
	echo "E-mail"   
else
    echo "Nie rozpoznano"     
fi

# regex sprawdzający e-mail stworzony na podstawie informacji z 
# https://en.wikipedia.org/wiki/Email_address#Syntax