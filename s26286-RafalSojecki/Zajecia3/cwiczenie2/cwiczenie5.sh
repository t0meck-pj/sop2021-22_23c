#!/bin/bash
# Napisz skrypt, który wczyta listę plików do wypisania z wiersza poleceń,
# a następnie wypisze ich zawartości raz w kolejności od początku do końca,
# a raz na odwrót. Podpowiedzi:
# -indeksy ujemne tablicy mogą się przydać
# -można wyliczać wartości wyrażeń arytmetycznych (i+1)
# -przyda się for
# -może się przydać: cat oraz tac ale postaraj się zrobić to bez używania tych
# poleceń (drukowanie znak po znaku od początku do końca i od końca do
# początku)

for FILENAME in "$@"
do
  CONTENT=()
  while read -r LINE; do
    CONTENT[${#CONTENT[@]}]="$LINE"
  done < "$FILENAME"
  # Rozwiązanie bez drukowania znak po znaku 
  # for value in "${CONTENT[@]}"
  # do
  #   echo $value
  # done
  # for (( i=${#CONTENT[@]}; i>=0; i-- ));
  # do
  #   echo "${CONTENT[$i]}" | rev
  # done
  for (( i=0; i<=${#CONTENT[@]}; i++ ));
  do
    LINE="${CONTENT[$i]}"
    for (( j=0; j<=${#LINE}; j++ ));
    do
      echo -n "${LINE:j:1}"
    done
    echo ""
  done
  for (( i=${#CONTENT[@]}; i>=0; i-- ));
  do
    LINE="${CONTENT[$i]}"
    for (( j=${#LINE}; j>=0; j-- ));
    do
      echo -n "${LINE:j:1}"
    done
    echo ""
  done
done
