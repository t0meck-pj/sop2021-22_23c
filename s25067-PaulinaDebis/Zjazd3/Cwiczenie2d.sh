#!/bin/bash

for i in $(find . -maxdepth 1 -type f); do
	X=`basename "$i"`
	rozszerzenie=${X: -2}

	if [[ $rozszerzenie -eq "c" ]]; then
		cc $i -o {i::-2}
	
	else echo Plik $i nie ma rozszerzenia .c

	fi
	
done

