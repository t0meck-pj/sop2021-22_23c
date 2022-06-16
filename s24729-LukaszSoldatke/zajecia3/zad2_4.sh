#!/bin/bash

for i in $(ls -p | grep -v /); do
	if [ ${i:${#i}-2} == ".c" ]; then
		cc $i -o ${i%.*}
	fi
done
