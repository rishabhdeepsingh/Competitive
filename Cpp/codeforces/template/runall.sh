#!/usr/bin/env bash

problem=$1

if [[ -z "$problem" ]]; then
    problem=(`pwd`)        
fi
cd $problem
echo $problem

infiles=(`ls in*`)
if [[ -z "$infiles" ]]; then
    echo "No in files"
    exit 0
fi

g++ -O2 -DLOCAL -std=c++17 -Wno-used-result -Wshadow -Wall -DLOCAL -o sol sol.cpp

echo ${infiles[@]}

for file in ${infiles[@]}
do
    echo "input for file $file:"
    cat "$file"
    ./sol < $file > out$file
    printf "output:\n"
    cat out$file
    echo ""
done

echo ""
echo "All Done!!!!"
