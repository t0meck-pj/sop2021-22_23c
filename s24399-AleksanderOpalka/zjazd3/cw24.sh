#!/bin/bash

for x in *;do
  if [[ ${x: -2} == ".c" ]]; then
    cc $x -o ${x::-2}
  fi
done
