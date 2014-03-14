/* 
 * File:   lab5main.cpp
 * Author: Nick
 *
 * Created on February 26, 2014, 8:20 PM
 */

#include <cstdlib>
#include <iostream>
#include "tbst.h"

using namespace std;

char const DEFAULT_FILE[] = "hamlet.txt";

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream& infile(DEFAULT_FILE);
    
    ThreadedBST tokenTree();
    
    char currentToken[];
    
    while (!infile.eof()) {
        infile = infile.getline(currentToken, 99, ' ');
        tokenTree.insert(currentToken);
    }

    return 0;
}

