#!/bin/bash

name=`basename "$0"`

if [[ $name =~ ^.*\.sh$ ]]; then
	echo "Plik konczy sie na .sh"
else
	nameWithoutExtenstion="${name%.*}"
	echo $name
	mv $name "$nameWithoutExtenstion.sh"
fi
