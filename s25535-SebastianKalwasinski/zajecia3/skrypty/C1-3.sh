#!/bin/bash

plik=$0

# Kolory =======================================================================

lgreen=`echo -e "\e[92m"`
pink=`echo -e "\e[95m"`
lcyan=`echo -e "\e[96m"`
k0=`echo -e "\e[0m"`


# Trzy ostatnie znaki ==========================================================

dlugosc=${#plik}
pozycja=$((dlugosc - 3))
rozszerzenie1=${plik:pozycja:3}


# Bash-owy mechanizm ===========================================================


foo=${plik%.*}
rozszerzenie2=${plik#*$foo}


# Regex-y ======================================================================

rozszerzenie3=$(echo "$plik" | sed -r s/\.\\/\\w+\|-\\w+//g)


# Warunki ======================================================================

if [[ $rozszerzenie1 == ".sh" ]]; then
echo "${pink}Pozycje kończą się na .sh, Jej!${k0}"
fi

if [[ $rozszerzenie2 == ".sh" ]]; then
echo "${lgreen}Bash mówi .sh${k0}"
fi

if [[ $rozszerzenie3 = ".sh" ]]; then
echo "${lcyan}Regexy też mówią .sh${k0}"

nazwa=$(echo "$plik" | sed -r s/\\.\\/\|\\.sh//g) 

elif [[ $rozszerzenie3 != ".sh" ]]; then
echo `mv $nazwa ${nazwa}.sh`
fi

