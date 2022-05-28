#!/bin/bash

function fibonacci(){
  if [ $1 -le 1 ]; then
    echo 0
  elif [ $1 -eq 2 ]; then
    echo 1
  else
     echo $(( $(fibonacci $(($1 - 1)) ) + $(fibonacci $(($1 - 2)) ) ))
  fi
}

echo $(fibonacci $1)
