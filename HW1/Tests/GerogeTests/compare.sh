#!/bin/bash

# Directories
DIR1="expected"
DIR2="my_out"

# Counters for different and identical files
count_diff=0
count_ok=0

# Loop through the file indices
for i in {1..3}
do
    # Construct file names
    FILE1="${DIR1}/t${i}.out"
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
            # Increment the difference counter
            ((count_diff++))
        else
            echo "No differences in t${i}.out."
            # Increment the ok counter
            ((count_ok++))
        fi
    else
        echo "t${i}.out not found in one of the directories."
    fi
done

# Print the summary
echo "Total files with differences: $count_diff"
echo "Total files without differences: $count_ok"
