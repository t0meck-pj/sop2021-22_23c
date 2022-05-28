#!/bin/bash

number_files_found=$(find . | wc -l)

if [ $number_files_found -gt 5 ]; then
	echo "Znaleziono w danym katalogu wiecej niz 5 plikow"
fi
