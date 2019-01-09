#!/bin/bash
clang++ -O0 unroll.cpp -S -o unroll_O0.S
clang++ -O2 unroll.cpp -S -o unroll_O2.S
clang++ -O0 unroll.cpp -c -o unroll_O0.o
clang++ -O2 unroll.cpp -c -o unroll_O2.o
clang++ -O2 main.cpp -c -o main.o

clang++ unroll_O0.o main.o -o test_O0
clang++ unroll_O2.o main.o -o test_O2
