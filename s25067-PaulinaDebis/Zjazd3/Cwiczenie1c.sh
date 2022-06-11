#!/bin/bash

X=`basename "$0"`

rozszerzenie=`${X##*.}`

if 	[[ $rozszerzenie -eq "sh" ]]; then
	echo Nazwa pliku jest ok 
	
else	
	echo Stara nazwa pliku ${X}
	mv $0 ${0}.sh
	echo Nowa nazwa pliku ${X}
fi


