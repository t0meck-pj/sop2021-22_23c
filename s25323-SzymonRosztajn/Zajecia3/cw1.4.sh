#!/bin/bash

numbOfFiles=$(ls -p | grep -vc /)

if [ $numbOfFiles -gt 5 ]; then
	echo "Jest wiecej niz 5 plików"
else
	echo "Jest mniej niż 5 plików"
fi

