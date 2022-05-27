#!/bin/bash

str=$1
lastLetter=${str: -1}

echo str $str
echo lastLetter $lastLetter

case "$lastLetter" in
	"a") echo $str ma kota, a kot ma ${str/a/ę} ;;
	"k") echo $str ma kota, a kot ma ${str/k/ka} ;;
	"w") echo $str ma kota, a kot ma ${str/w/wa} ;;
esac
