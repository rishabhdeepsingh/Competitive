# FastIO For Different Languages in Competitive Programming

Fast Input and output Class for Competitive Coding.

# Settings

## Competitive Companion
[Chrome](https://chrome.google.com/webstore/detail/competitive-companion/cjnmckjndlpiamhfimnnjmnckgghkjbl) | [Firefox](https://addons.mozilla.org/en-US/firefox/addon/competitive-companion/)

## [C++](https://github.com/rishabhdeepsingh/Competitive/tree/master/Cpp)
Install [Jhelper2.0](https://github.com/rishabhdeepsingh/JHelper2.0) plugin and import the Cpp project in Clion

# Bash testing for C++
In ubuntu we can use the following code to check the time
    
    time ./a.out < in 
    time ./generator | ./a
    
## Using generator
    
    #!/bin/bash
    g++ -o gen gen.cpp
    g++ -o main main.cpp
    g++ -o brute brute.cpp
    for((i = 1;;++i));do
        echo $i
        ./gen $i > inputt
        diff -w <(./main < inputt) <(./brute < inputt) || break
    done


To copy a single file to multiple Files

    echo a.cpp b.cpp d.cpp | xargs -n 1 cp template.cpp
    
## Compile
### Normal
    g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o "%e" "%f"
### Debugging
    g++ -DLOCAL -std=c++17 -Wshadow -Wall -o "%e" "%f" -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g

