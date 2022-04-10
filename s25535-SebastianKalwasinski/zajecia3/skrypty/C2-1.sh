#!/bin/bash

k0=`echo -e "\e[0m"`

for i in {10..1..2}; do

	a=$((i/2+1))
	echo `echo -e "\e[3${a}m"`${i}${k0} 

done

