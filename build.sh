#!/bin/bash

# Compile the source file
g++ -o Movie_Rental_And_Buying_System DiverCode.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executable created: Movie_Rental_And_Buying_System"
else
    echo "Compilation failed."
fi
