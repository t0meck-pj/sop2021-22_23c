#!/bin/bash



print_with_color() {
	echo -e "${2}${1}\e[0m"
}


print_with_color "test" "\e[31m";
