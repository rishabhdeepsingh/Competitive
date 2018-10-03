# FastIO-Java


Fast Input and output Class for Competitive Coding.

For C++ Use
## Slow
    g++ -DLOCAL -std=c++17 -Wshadow -Wall -o "squares" "squares.cpp" -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
    
## Fast 
    g++ -O2 -std=c++17 -Wno-unused-result -Wshadow -Wall -o "squares" "squares.cpp" (in directory: /home/kamil/c/squares)
    
## Temp
    g++ -static -DRDS -lm -s -x c++ -Wl,--stack=268435456 -O2 -std=c++17 -D__USE_MINGW_ANSI_STDIO=0 -o run.exe {filename.cpp}
