#!/bin/bash
make
./build/Kth-largest.out > output
gprof ./build/Kth-largest.out gmon.out -b -p
gprof ./build/Kth-largest.out gmon.out > analysis.txt