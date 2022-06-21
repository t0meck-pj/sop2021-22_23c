#!/bin/bash
if [[ -e "./config.cfg" ]]; then
        cat config.cfg
elif [[ $# > 0 ]]; then
        echo "$1"
else
        echo "Blad!"
fi  
