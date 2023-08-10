#!/bin/bash

shopt -s nullglob

# Store the list of .c files in the current directory in an array
c_files=( *.c )

# Check if no .c files are found
if [ ${#c_files[@]} -eq 0 ]; then
    echo "No c files found"
else
    # Loop through each .c file found
    for file in "${c_files[@]}"; do
        # Run the 'betty' command to check the coding style of the file
        betty "$file"
    done
fi

