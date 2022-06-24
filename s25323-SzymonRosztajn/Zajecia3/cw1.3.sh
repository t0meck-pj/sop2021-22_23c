#!/bin/bash

if [[ $0 =~ .sh$ ]]; then
echo "Plik konczy się na .sh"
else
mv $0 "$0.sh"
fi
