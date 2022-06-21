#!/bin/bash

PS1COPY=$PS1
STRING=$1

if [[ $2 == black ]]; then COLOR='\033[0;30m'; fi
if [[ $2 == red ]]; then COLOR='\033[0;31m'; fi
if [[ $2 == green ]]; then COLOR='\033[0;32m'; fi
if [[ $2 == brown ]]; then COLOR='\033[0;33m'; fi
if [[ $2 == blue ]]; then COLOR='\033[0;34m'; fi
if [[ $2 == magenta ]]; then COLOR='\033[0;35m'; fi
if [[ $2 == cyan ]]; then COLOR='\033[0;36m'; fi
if [[ $2 == white ]]; then COLOR='\033[0;37m'; fi

function f1 {
	echo -e $COLOR$STRING
}

f1

PS1=$PS1COPY
