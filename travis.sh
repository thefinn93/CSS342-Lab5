#!/bin/bash
set -e
cd lab5
echo "=== test-nodeData.cpp ==="
g++ -Wall test-nodeData.cpp -o test-nodeData
./test-nodeData

echo "=== Big lines ==="

biglines=`awk 'length > 80 {print FILENAME "(" FNR "): " $0}' *.cpp *.h`
if [ "$biglines" != "" ]; then
    echo "Big lines detected!"
    awk 'length > 80 {print FILENAME "(" FNR "): " $0}' *.cpp *.h
    exit 1;
else
    echo "No big lines detected!";
fi
