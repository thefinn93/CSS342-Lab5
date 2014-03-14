#!/bin/bash
set -e
which valgrind || sudo apt-get install valgrind > /dev/null
which doxygen || sudo apt-get install doxygen > /dev/null

cd lab5
for testFile in test.cpp lab5main.cpp; do
    echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
    echo $testFile
    echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
    g++ -Werror $testFile
    valgrind --error-exitcode=1 --leak-check=yes ./a.out
    rm a.out
done

echo "Doxygen"
echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
doxygen *.cpp *.h

echo "Big lines"
echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"

biglines=`awk 'length > 80 {print FILENAME "(" FNR "): " $0}' *.cpp *.h`
if [ "$biglines" != "" ]; then
    echo "Big lines detected!"
    awk 'length > 80 {print FILENAME "(" FNR "): " $0}' *.cpp *.h
    if [ "$ALLOW_BIG_LINES" != "yup" ]; then
        exit 1;
    else
        echo "Big lines found, but ALLOW_BIG_LINES is set. Allowing.";
    fi
else
    echo "No big lines detected!";
fi
