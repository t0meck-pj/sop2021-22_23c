#!/bin/bash

number=1
value=0
howManyIteration=$1
iteration=0

fibonacci() {
	if [[ $iteration == $1 ]]; then
		return 0;
	fi
        echo $number
	number=$(($number+$value))
	value=$(($number-$value))
	iteration=$((iteration + 1))
	fibonacci $howManyIteration
}

fibonacci $howManyIteration
