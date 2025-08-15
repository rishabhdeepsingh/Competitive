#!/bin/bash

directory=$1
read -a tasks -p "Please give the tasks of tasks \"a b c \": "

if [[ ${#directory[@]} -eq 0 ]]; then
    echo "Changing dir to $directory"
    mkdir -p $directory
    cd $directory
fi

# If empty take a default contest 
if [[ ${#tasks[@]} -eq 0 ]]; then
    echo "Taking defaults a,b,c"
    tasks=(a b c)
fi

echo ${tasks[@]}

for tt in ${tasks[@]}
do
    task=$tt
    if [[ "$directory" ]]; then
        task="$directory/$tt"
    fi

    if [[ -d "$task" ]]; then
        echo "Task $task already exists"
        continue
    fi
    mkdir -p $task
    cp template/* $task
done

echo "Done Creating files"