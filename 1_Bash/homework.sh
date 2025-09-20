#!/bin/bash
work_dir=$(pwd -P)
echo $work_dir
DIRECTORY="$work_dir/attachments"
echo $DIRECTORY

if [ -d "$DIRECTORY" ]; then
  echo "$DIRECTORY does exist."
else
  echo "$DIRECTORY does not exist. Creating.."
  mkdir "$DIRECTORY"
fi

echo "Getting photos from https://picsum.photos/800/400.."
for (( i=1; i <= 10; i++ ))
do
    echo "Saving $i file.."
    file="$DIRECTORY/img_$i.jpg"
    echo $file
    curl https://picsum.photos/800/400 -L > "$file"
done



