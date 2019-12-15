#!/bin/bash

read -a tasks -p "Please give the tasks of tasks: "
# If empty take a default contest 
if [[ ${#tasks[@]} -eq 0 ]] ; then
    echo "Taking defaults a,b,c,d,e "
    tasks=(a b c d e)
fi

echo ${tasks[@]}

for task in ${tasks[@]}
do
    if [ -d "$task" ]; then
        echo "Task $task already exists; continuing"
        continue
    fi
    mkdir $task
    cp template.cpp $task/sol.cpp 
    cp runall.sh gen.cpp test.sh time.sh $task/
done

 echo "Done Creating files"
