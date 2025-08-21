#!/bin/bash

VAR=$(echo  "$1 + $2" | bc)

echo "Sum = $VAR"

until [ $VAR -eq 0 ]
do
   VAR=$((VAR-1))
   echo $VAR
done

