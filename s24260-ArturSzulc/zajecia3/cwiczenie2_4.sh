#!/bin/bash

text=$(ls -p | grep */ -v)

for i in $text; do
	if [[ ${i: -2} == ".c" ]]; then
		cc $i -o ${i::-2}
	fi
done
