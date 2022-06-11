#!/bin/bash

for i in $(find . -maxdepth 1 -type f); do

	echo Patrzcie Panstwo, oto plik: $i

done
