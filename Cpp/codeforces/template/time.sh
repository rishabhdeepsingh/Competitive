#!/bin/bash

g++ -o gen gen.cpp
g++ -o sol sol.cpp
for((i = 1;;++i));do
    echo $i
    ./gen $i > test_file
    time (./sol < test_file)
done