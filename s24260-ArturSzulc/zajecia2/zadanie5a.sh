#!/bin/bash

#A=Ala
#echo $A ma kota, a kot ma ${A:a:2}ę

name=$1

if [ ${name: -1} = "a" ]; then

  echo "$name ma kota, a kot ma ${name::-1}ę"
else
  echo "$name ma kota, a kot ma ${name}a"
fi
