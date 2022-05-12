#!/bin/bash

# W Polsce kody pocztowe mają format dd-ddd (d oznacza cyfrę) i umieszcza się je z lewej strony nazwy miejscowości.

if [[ $1 =~ [1-9]{1}[0-9]{1}[-][0-9]{3}$ ]]; then
	echo "$1: Jest kodem pocztowym"
else
	echo "$1: Nie jest kodem pocztowym"
fi
