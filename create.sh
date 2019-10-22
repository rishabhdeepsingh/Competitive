#!/bin/bash

# Remove all Directories
rm -R -- */

read -a tasks -p "Please give the tasks of tasks: "
# If empty take a default contest 
if [[ ${#tasks[@]} -eq 0 ]] ; then
    echo "Taking defaults a,b,c,d,e "
    tasks=(a b c d e f)
fi

printf "%s\n" "${tasks[@]}" | xargs -I {} sh -c 'mkdir -p $1 && cp template.cpp $1/sol.cpp' sh {}
 
