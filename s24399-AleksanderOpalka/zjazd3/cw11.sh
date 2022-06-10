#!/bin/bash

if [[ $# > 0 ]]; then
  for var in "$@"
  do
      echo "$var"
  done
else
	echo "Argument not found"
fi
