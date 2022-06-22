#!/bin/bash

function fibonacci(){
  if [ $1 -le 1 ]; then
    return "$1"
  else
    fibonacci $(($1-1))
    local part1=$?
    fibonacci $(($1-2))
    local part2=$?
    return $((part1+part2))
  fi
}

fibonacci 13
echo $?