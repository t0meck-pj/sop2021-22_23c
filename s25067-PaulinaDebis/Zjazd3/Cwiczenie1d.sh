#!/bin/bash

X=$(ls -p | grep -v / | wc -l)

if [ $X -gt 5 ]; then
	echo W katalogu jest wiecej niz 5 plikow
fi



