#!/bin/bash

function fibonacci {
	LIMIT=15
	NUMBER1=0
	NUMBER2=1

	for (( i = 0; i < $LIMIT; i++ )); do
		echo $NUMBER1
		SUM=$(($NUMBER1 + $NUMBER2))
		NUMBER1=$NUMBER2
		NUMBER2=$SUM
	done
}

echo $(fibonacci)
