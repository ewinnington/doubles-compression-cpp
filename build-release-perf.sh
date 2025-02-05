#!/usr/bin/env bash
mkdir -p output
clang++ -O3 -std=c++17 -o ./output/performance_test ./tests/performance_test.cpp