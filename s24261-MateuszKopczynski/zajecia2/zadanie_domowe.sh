#!/bin/bash

file=$1

sed -e s/Mateusz/`echo -e "\e[31mMateusz\e[0m"`/g $file
