#!/bin/bash


self_name=$(basename "$0")
name_len=${#self_name}
extension=${self_name:$name_len-3:3}

if [[ "$extension" == ".sh" ]];then
  echo "Ten plik ma rozszerzenie .sh"
else
  mv $self_name "$self_name.sh"
  echo "Ten plik teraz juz ma ma rozszerzenie .sh"
fi
