#!/bin/bash
FILES=()
# If the directory exists
if [ -e dip ] && [ -d dip ]; then
   echo "dip Directory exists"
   # List all files
   FILES=$(ls ./dip)
# loop over the files
   for str in ${FILES[@]}; do
      echo "Found file: $str"
# delete all of them
      echo "Deleting file: $str"
      rm ./dip/"$str"
   done
fi



