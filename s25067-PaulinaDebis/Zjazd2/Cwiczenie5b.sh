#!/bin/bash

x=${1}

echo ${1:0:1} #pierwsza litera

echo ${1: -1} #ostatnia litera

y="SOP! SOP w imieniu prawa! SOP w imieniu prawa!"
echo ${y//SOP/`echo -e "\e[32mSOP\e[0m"`}


