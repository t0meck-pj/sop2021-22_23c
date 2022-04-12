#!/bin/bash
plik=./zadanie_domowe.txt
cat $plik | sed s/Sebastian/`echo -e "\e[31mSebastian\e[0m"`/

