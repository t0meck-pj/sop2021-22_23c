#!/bin/bash

X=${1}

CiagFibonacciego () {
	if [[ $X == 0 ]]; then
		return 0

	elif [[ $X == 1 ]]; then
		return 1
	
	else
		A=$(CiagFibonacciego $[$X-1])
		B=$(CiagFibonacciego $[$X-2])
		let wynik=$A+$B
		return echo $wynik

	fi
}

CiagFibonacciego $X



