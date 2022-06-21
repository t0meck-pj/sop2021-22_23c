#!/bin/bash

tak=$1

first=${tak:0:1}
last=${tak:${#tak}-1:1}

echo $first
echo $last
echo 'Tekst => '$* | sed s/SOP/`echo -e "\e[32mSOP\e[0m"`/g
