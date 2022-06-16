#!/bin/bash
# Napisz skrypt, który dla każdego pliku w bieżącym katalogu, który ma
# rozszerzenie .c wykona taką komendę:
#    cc (tu_nazwa_pliku) -o (tu_nazwa_pliku_bez_rozszerzenia)
# Oczywiście zamień (tu_nazwa_pliku) na nazwę pliku, a
# (tu_nazwa_pliku_bez_rozszerzenia) na nazwę pliku z obciętym rozszerzeniem.
# Jeśli chcesz przykładowe pliki do potestowania, oto one :-)
# http://lmgtfy.com/?q=example+c+file

FILES=$(ls -p)

for FILENAME in ${FILES}
do
  EXTENSION="${FILENAME##*.}"
  if [[ $EXTENSION == "c" ]]; then
    FILENAMENOEXTENSION="${FILENAME%.*}"
    cc "$FILENAME" -o "$FILENAMENOEXTENSION"
  fi
done
