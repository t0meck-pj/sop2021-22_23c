#!/bin/bash

if [ -f $PWD/config.cfg ]; then
   $PWD/config.cfg
elif [ $# -gt 0 ] &&  [ -f $PWD/$1 ]; then
   $PWD/$1
else
   echo "Error"
fi
