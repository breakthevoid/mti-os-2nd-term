#!/bin/bash
IFS=$'\n'

file=$1

for name in $(cat $file)
do
    echo "Hello, $name!"
done

