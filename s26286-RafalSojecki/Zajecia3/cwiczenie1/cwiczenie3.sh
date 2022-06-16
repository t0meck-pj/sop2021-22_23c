#!/bin/bash
# Napisz skrypt, który:
# sprawdzi, czy jego nazwa kończy się .sh .
# Jeśli nie, to niech zmieni swoją nazwę poprzez dopisanie tego rozszerzenia
# (rozszerzenie nazwy pliku). Sprawdzenie można zrobić na kilka sposobów,
# polecam przetestować 3 typowe:
# - dopasowanie do wyrażenia regularnego (to jest bardziej uniwersalny sposób)
# - porównanie ostatnich 3 liter nazwy skryptu
# - użyć wbudowanego w basha mechanizmu do wyciągania części napisów ${%},
# ${%%}, ${#}, ${##} 

EXTENSION="${0##*.}"
FILENAME="${0##*/}"

if [[ $EXTENSION != "sh" ]]; then
  mv "$0" "$FILENAME.sh"
fi
