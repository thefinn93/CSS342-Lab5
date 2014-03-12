#!/bin/bash
set -e

cd lab5
for testFile in test-*.cpp; do
    echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
    echo $testFile
    echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
    g++ -Werror $testFile
    valgrind --error-exitcode=1 --leak-check=yes ./a.out
    rm a.out
done
