#! /bin/bash

X=$(ls)

for S in $X; do
    if [[ $s =~ \.c$ ]]; then
        $(cc $S -o ${s:: -2})
    fi
done
