#!/usr/bin/env bash

# Renames all *.c files to *.cpp and ../include/*.h to ../include/*.hpp

# 1. Rename all *.c files to *.cpp
for file in *.c; do
    mv "$file" "${file%.c}.cpp"
done

# 2. Rename all *.h files to *.hpp
for file in ../include/*.h; do
    mv "$file" "${file%.h}.hpp"
done
