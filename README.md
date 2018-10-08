# FastIO For Java and C++


Fast Input and output Class for Competitive Coding.

## For C++


In ubuntu we can use the following code to check the time
    
    time ./a.out < in 

## Compile
    g++ -DLOCAL -std=c++17 -Wshadow -Wall -o "run" "{filename}.cpp" -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
    g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o "run" "{filename}.cpp"
