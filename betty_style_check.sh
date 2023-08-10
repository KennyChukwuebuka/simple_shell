#!/bin/bash

shopt -s nullglob

c_files=( *.c )

# Check if no .c files are found
if [ ${#c_files[@]} -eq 0 ]; then
    echo "No c files found in the current directory"
    exit 1
fi

# Check if 'betty' command is available
if ! command -v betty &> /dev/null; then
    echo "Error: 'betty' command not found. Please install it."
    exit 1
fi
    for file in "${c_files[@]}"; do
        # Run the 'betty' command to check the coding style of the file
        betty "$file"
    done

    echo "Style check completed for all .c files."   
