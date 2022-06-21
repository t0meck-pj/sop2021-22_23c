#!/bin/bash

A=$1
len=${#A}
e=${A:len-1:1}

if [ "$e" == "a" ];then
  echo $A ma kota, a kot ma ${A:0:len-1}ę
else
  echo $A ma kota, a kot ma ${A}a
fi
