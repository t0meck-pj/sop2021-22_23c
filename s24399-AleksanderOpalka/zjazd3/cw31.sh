#!/bin/bash

print_with_color() {
	echo -e "${2}${1}\e[0m"
}

#example use

print_with_color "proba123" "\e[31m";
