#!/bin/bash

for i in $(ls -la); do
	if [ -f $i ]; then echo "Patrzcie panstwo, oto plik: $i"; fi
	if [ -d $i ]; then echo $i; fi
done
