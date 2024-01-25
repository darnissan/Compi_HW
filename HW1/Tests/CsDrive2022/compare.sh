#!/bin/bash

# Directories
DIR1="207231267-318261948.returned"
DIR2="dars_out"

# Loop through the file indices
for i in {1..11}
do
    # Construct file names
    FILE1="${DIR1}/t${i}.in.out"
    FILE2="${DIR2}/my_t${i}.out"

    # Check if both files exist
    if [[ -f "$FILE1" && -f "$FILE2" ]]; then
        echo "Comparing t${i}.out..."
        # Run diff and capture the output
        diff_output=$(diff "$FILE1" "$FILE2")
        
        # Check if there were differences
        if [ -n "$diff_output" ]; then
            echo "Differences found in t${i}.out:"
            echo "$diff_output"
        else
            echo "No differences in t${i}.out."
        fi
    else
        echo "t${i}.out not found in one of the directories."
    fi
done
