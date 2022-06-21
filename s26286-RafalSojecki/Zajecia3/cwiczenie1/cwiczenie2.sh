#!/bin/bash
# Napisz skrypt, który:
# - sprawdzi, czy istnieje plik config.cfg w bieżącym katalogu.
# - Jeśli taki plik istnieje, to niech go wykona.
# - Jeśli nie istnieje, to niech sprawdzi, czy podano argument i wykona plik o
# nazwie takiej jak wartość argumentu (parametru) skryptu.
# -Jeśli żadne z powyższych nie nastąpiło, to niech wyświetli komunikat o błędzie.

FILE="config.cfg"

if [[ -e $FILE ]]; then
  echo -e "$(./$FILE)"
elif [[ -e $1 ]]; then
  echo -e "$(./"$1")"
else
  echo "Błąd"
fi
