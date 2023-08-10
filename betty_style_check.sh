#!/bin/bash

shopt -s nullglob

c_files=( *.c )

# Check if no .c files are found
if [ ${#c_files[@]} -eq 0 ]; then
    echo "No c files found"
else
    for file in "${c_files[@]}"; do
        # Run the 'betty' command to check the coding style of the file
        betty "$file"
    done
fi

