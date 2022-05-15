#!/bin/bash
echo "=============================================================="
echo "By załadować funkcję wpisz source ./C3-1.sh"
echo 'By z niej korzystać napisz C3-1 "$kolor" "Tekst"'
echo "${red}red ${green}green ${k0}i ${blue}blue ${k0}są przypisane."
echo "=============================================================="

red=$(echo -e "\e[31m")
green=$(echo -e "\e[32m")
blue=$(echo -e "\e[34m")
k0=$(echo -e "\e[0m")

C3-1() {
	echo -e "${1}${2}$k0"
}

