#!/bin/bash
# Compile both generator and solution
g++ -o gen gen.cpp
g++ -o sol sol.cpp

# Test solution against multiple files and save to a file so that no output is given
for((i = 1;;++i));do
   echo $i
   ./gen $i > temp_gen
    time (./main < temp_gen > sol_time)
done
