#!/bin/bash
work_dir=$(pwd -P)
echo $work_dir
DIRECTORY="$work_dir/attachments"
echo $DIRECTORY

if [ -d "$DIRECTORY" ]; then
  echo "$DIRECTORY does exist."
  rm -rf "$DIRECTORY/*.jpg"
fi




