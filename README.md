# FastIO For Different Languages in Competitive Programming

Fast Input and output Class for Competitive Coding.

# Settings

## [C++](https://github.com/rishabhdeepsingh/Competitive/tree/master/Cpp)
Install Jhelper plugin and import the CPP project in Clion

## [Java](https://github.com/rishabhdeepsingh/Competitive/tree/master/Java)
Install CHelper plugin and import the Java Project in Intellij Idea

## [Kotlin](https://github.com/rishabhdeepsingh/Competitive/tree/master/Kotlin)
Create a new Project and use the template file.

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

