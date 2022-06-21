#!/bin/bash
# Przygotuj funkcję obliczającą rekurencyjnie ciąg Fibonacciego. Niech wynik
# zwraca za pomocą return. Czy są jakieś ograniczenia?
# Rekurencyjnie i return czyli:
# Nie używamy pętli
# Nie używamy echo
# Wartość ma być zwracana przez literał return

function FIBONACCI {
  if [[ $1 -le 1 ]]; then
    return "$1"
  else
    FIBONACCI $(($1-1))
    local RETURNED=$?
    FIBONACCI $(($1-2))
    return $((RETURNED+$?))
  fi

}

FIBONACCI 6
echo $?

# W bash-u funkcja moze zwracać jedynie wartości z przedziału 0-255
# tak więc wynik jest poprawny jedynie do 13 wyrazu ciągu.