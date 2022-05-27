#!/bin/bash

fib(){
	local pozycja=$1
        if (( $pozycja <= 0 )); then
		return 0
	elif (( $pozycja == 1 )); then
		return 1
#       elif (( $pozycja == 2 )); then
#               return 1
#       elif (( $pozycja == 3 )); then
#               return 2        
	else
	local zmienna1=$((pozycja - 1))
	#echo "zmienna1 = $zmienna1"
	
	local zmienna2=$((pozycja - 2))
	#echo "zmienna2 = $zmienna2"
	
	#echo '$? ='$?
	fib $zmienna1
	#echo '$? ='$?  
	local wynik1=$?
	
	fib $zmienna2
	local wynik2=$?
	
	WYNIK=$((wynik1+wynik2))
	return $WYNIK
	fi
}
if (( $# == 1 )); then
	fib $1
	echo -e "\e[32mreturn = $?\e[0m"
else
	echo -e "\e[31mNiepoprawna ilosc argumentow\e[0m"
fi

