#!/bin/bash

filename="$(basename $0)"

if [ ${filename: -2} != "sh" ]; then
   echo "Plik nie posiada rozszerzenia .sh"
   mv $filename ${filename}.sh
fi

