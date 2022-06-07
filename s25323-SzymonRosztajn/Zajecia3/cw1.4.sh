#!/bin/bash

numbOfFiles=$(find . | wc -l)

if [ $numbOfFiles -gt 5 ]; then
	echo "Jest wiecej niz 5 plików"
else
	echo "Jest mniej niż 5 plików"
fi

