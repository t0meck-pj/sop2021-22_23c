#!/bin/bash

A=$1
len=${#A}
e=${A:len-1:1}

if [ "$e" == "a" ];then
  echo  -e "$A ma kota, kot ma $A" | sed 's/a$/e/g'
else
  echo $A ma kota, a kot ma ${A}a
fi
