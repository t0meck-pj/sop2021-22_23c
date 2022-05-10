#!/bin/bash

files=$(ls -p | grep -v /)

for i in $files; do
    if [ ${i: -1} == "c" ]; then
     cc $i -o ${i: -2}
    fi
done
