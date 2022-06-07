#!/bin/bash

for i in $(ls); do
cat $i
done
for i in $(ls -r); do
tac $i
done

