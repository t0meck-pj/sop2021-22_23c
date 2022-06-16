#!/bin/bash
# Napisz skrypt, który będzie wypisywał wszystkie argumenty wywołania skryptu
# (pamiętaj o tym, że argument może w sobie zawierać jakieś spacje) napisane
# w cudzysłowach.

for FILENAME in "$@"
do
  echo "$FILENAME"
done
