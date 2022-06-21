#!/bin/bash
# Pamiętasz jedno z zadań poprzednich?
# A=Ala
# echo $A ma kota, a kot ma ${A}ę
# Przerób je tak, aby tekst wypisywał się poprawnie.
# Napisz skrypt, który będzie wypisywał taki tekst także dla imion
# męskich. Pomijamy zdrobnienia i imiona które się dziwnie odmieniają
# (na przykład Marek). Niech skrypt ten przyjmuje jeden argument - imię.
# Przykładowe wywołanie:
# $ ./pszetżkole Ala
# Ala ma kota, a kot ma Alę
# $ ./pszetżkole Justyna
# Justyna ma kota, a kot ma Justynę
# $ ./pszetżkole Stefan
# Stefan ma kota, a kot ma Stefana
# Czy jest to możliwe w czystym bash-u?

NAME=$1
if [ "${NAME: -1}" == "a" ];then
	echo "$NAME ma kota, a kot ma ${NAME%?}ę."
else
	echo "$NAME ma kota, a kot ma ${NAME}a."
fi
