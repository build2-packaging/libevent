#!/usr/bin/env bash 

args=( "$@" )

echo "$args"

for sourcename in "${args[@]}"; do
  file=../../../../upstream/$sourcename
  echo "$file"
  [[ -e $file ]] && ln -sv "$file"
done

echo "done"
