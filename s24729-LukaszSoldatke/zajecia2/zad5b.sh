#!/bin/bash

str=$1
length=${#str}
echo ${str:0:1}
echo ${str:$(($length-1)):1}
echo -e ${str/SOP/"\e[32mSOP\e[0m"}
