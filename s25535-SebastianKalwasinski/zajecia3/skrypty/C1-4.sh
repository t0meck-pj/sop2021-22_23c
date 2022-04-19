#!/bin/bash

ilosc1=$(echo $(ls -p | grep -vc /))
echo "Jest $ilosc1 plików"

ilosc2=$(find . -maxdepth 1 -type f | wc -l)
echo "Tu też jest $ilosc2 plików"

if [[ "$ilosc1" -gt 5 ]]; then
	echo "Jest więcej niż 5 plików"
fi

if [[ "$ilosc2" -gt 5 ]]; then
	echo "Tu też jest więcej"
fi

