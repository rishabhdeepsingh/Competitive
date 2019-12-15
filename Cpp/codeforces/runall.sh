#!/bin/bash
problem=$1
if [ -z "$problem" ]; then
    problem=(`pwd`)        
fi
cd $problem
echo $problem

g++-9 -O2 -DLOCAL -std=c++17 -Wno-used-result -Wshadow -Wall -o sol sol.cpp

infiles=(`ls in*`)
echo ${infiles[@]}

for file in ${infiles[@]}
do
    echo "$file"
    ./sol < $file > out$file 
    cat out$file
done

echo "Done!!!!"
