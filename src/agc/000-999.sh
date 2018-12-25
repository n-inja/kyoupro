#!/bin/bash

arraymin=(0)
array=(0 1 2 3 4 5 6 7 8 9)
for i in "${arraymin[@]}"
do
  for j in "${array[@]}"
  do
    for k in "${array[@]}"
    do
      mkdir ${i}${j}${k}
    done
  done
done
