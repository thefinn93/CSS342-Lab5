#!/bin/bash
set -e
cd lab5
doxygen Doxyfile
if [ "`cat doxygenWarnings.txt | wc -l`" != "0" ]; then
    echo "DOXYGEN WARNINGS!"
    cat doxygenWarnings.txt
    exit 1
fi
