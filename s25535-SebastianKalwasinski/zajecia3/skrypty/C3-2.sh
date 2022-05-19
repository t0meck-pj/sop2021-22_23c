#!/bin/bash

fib(){
	local ind=$1
	if (( ind <= 0 )); then
		echo 1
		return 1
	else
		local var1=$((ind - 1))
		local var2=$((ind - 2))
		local var11=$(fib $var1)
		local var22=$(fib $var2)
		echo $(($var11 + $var22))
		wynik=$(($var11 + $var22))
		return $wynik
	fi
}
printf "echo = "
fib $1
echo "return = "$?

