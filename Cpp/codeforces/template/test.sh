#!/bin/bash

g++ -o gen gen.cpp
g++ -o sol sol.cpp
g++ -o brute brute.cpp
for((i = 1;;++i));do
    echo $i
    ./gen $i > inputt
    diff -w <(./sol < inputt) <(./brute < inputt) || break
done