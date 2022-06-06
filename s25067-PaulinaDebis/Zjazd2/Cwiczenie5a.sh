#!/bin/bash
x=${1}

if [ "${x: -1}" = "a" ]; then
echo $x ma kota, a kot ma ${x//a/ę}
else 
echo $x ma kota, a kot ma ${x}a

fi
