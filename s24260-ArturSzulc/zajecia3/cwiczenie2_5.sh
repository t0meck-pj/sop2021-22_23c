#!/bin/bash

for i in $*; do
	if [[ -f $i ]] && [[ -s $i ]]; then    #check if file extist in filesystem
		fileContent=$(cat $i);
		numberOfLetter=${#fileContent}
		printf "Wiadomosc odwrocona: \n"
		for ((j=$numberOfLetter; j>=0; j--)); do
			printf "${fileContent:$j:1}"
		done
		printf "\n"
		printf "Wiadomosc (nie)odwrocona: \n"
		printf "$fileContent \n \n"
	fi
done
