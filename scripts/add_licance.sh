#!/bin/bash


PATTERN=py
NAME=$USER

sed -i "s/--NAME--/$NAME/g" license.txt

for i in *.$PATTERN
do
  if ! grep -q Copyright $i
  then
    cat pythonLine license.txt $i >$i.new && mv $i.new $i
  fi
done