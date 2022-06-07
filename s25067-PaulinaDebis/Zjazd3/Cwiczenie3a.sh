#!/bin/bash

tekst=${1}
kolor=${2}

function kolorowytekst {
	if [[ $kolor == "czerwony" ]]; then
		echo -e "\e[1;31m $tekst \e[0m"
	elif [[ $kolor == "czarny" ]]; then
                echo -e "\e[1;30m $tekst \e[0m"
        elif [[ $kolor == "zielony" ]]; then
                echo -e "\e[1;32m $tekst \e[0m"
        elif [[ $kolor == "żółty" ]]; then
                echo -e "\e[1;33m $tekst \e[0m"
  	elif [[ $kolor == "niebieski" ]]; then
                echo -e "\e[1;34m $tekst \e[0m"
        elif [[ $kolor == "biały" ]]; then
                echo -e "\e[1;37m $tekst \e[0m"
	else echo Nie ma takiego koloru w bazie
	fi
}

kolorowytekst $tekst $kolor


