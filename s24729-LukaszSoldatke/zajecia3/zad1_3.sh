#!/bin/bash

if [[ $0 =~ .sh$ ]]; then
echo "Rozszerzenie to .sh"
else
mv $0 "$0.sh"
fi
