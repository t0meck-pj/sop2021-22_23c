#!/bin/bash

text=$1

color='\033[0;'$2'm'
NC='\033[0m'

function printTextWithColor {
	printf "${color} $text ${NC} \n"
	tput sgr0;
}


printTextWithColor;
