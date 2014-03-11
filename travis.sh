#!/bin/bash
set -e
which valgrind || sudo apt-get install valgrind > /dev/null
which doxygen || sudo apt-get install doxygen > /dev/null

cd lab5
for testFile in test-*.cpp; do
    echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
    echo $testFile
    echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
    g++ -Werror $testFile
    valgrind ./a.out
    rm a.out
done

echo "Doxygen"
echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"
doxygen *.cpp *.h | grep "warning\|error"

echo "Big lines"
echo "▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇"

biglines=`awk 'length > 80 {print FILENAME "(" FNR "): " $0}' *.cpp *.h`
if [ "$biglines" != "" ]; then
    echo "Big lines detected!"
    awk 'length > 80 {print FILENAME "(" FNR "): " $0}' *.cpp *.h
    exit 1;
else
    echo "No big lines detected!";
fi
