#!/bin/bash

#normalnie

for i in *; do
  while read line; do
     echo $line;
  done < $i
done

#od tylu

for i in *; do
  inner_file=$(cat $i);
  total_length=${#inner_file}
  for (( i = $total_length ; i > 0; i-- )); do
    printf "${inner_file:$i:1}"
  done
done
