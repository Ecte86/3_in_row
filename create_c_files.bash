#!/usr/bin/env bash

# Ask if user wants to create a c or cpp file
printf "Do you want to create a c or cpp file? (c/cpp): "
read -r file_type

# Ask user for name of file
printf "Enter name of file (no extension): "
read -r filename



# Create file with given name and .c (or .cpp) extension in src folder
if [[ "${file_type,}" == "c"* ]]; then
    touch src/"$filename".c
elif [[ "${file_type,}" == "cpp"* ]]; then
    touch src/"$filename".cpp
else
    echo "Invalid file type"
    exit 1
fi

# ask user if they want to create a header file
printf "Do you want to create a header file? (y/n): "
read -r header

# if user wants to create a header file, create it in include folder
# (check first char for y or n, case insensitive)
if [[ "${header,}" == "y"* ]]; then
    if [[ "${file_type,}" == "c"* ]]; then
        touch include/"$filename".h
    elif [[ "${file_type,}" == "cpp"* ]]; then
        touch include/"$filename".hpp
    else
        echo "Invalid file type"
        exit 1
    fi
fi
