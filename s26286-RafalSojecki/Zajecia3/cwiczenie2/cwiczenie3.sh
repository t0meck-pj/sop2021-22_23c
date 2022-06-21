#!/bin/bash
# Napisz skrypt, który wypisze listę plików i katalogów bieżącego katalogu 
# poprzedzając każdą nazwę pliku tekstem "Patrzcie Państwo, oto plik: ". 
# Podpowiedź: https://en.wikipedia.org/wiki/Internal_field_separator

FILES=$(ls -p)
for FILENAME in ${FILES}
do
  if [[ ${FILENAME: -1} == "/" ]]; then
    echo "$FILENAME";
  else
    echo "Patrzcie Państwo, oto plik: $FILENAME";
  fi
done
