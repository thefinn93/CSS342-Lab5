/* 
 * File:   lab5main.cpp
 * Author: Nick
 *
 * Created on February 26, 2014, 8:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "tbst.h"

using namespace std;

char const DEFAULT_FILE[] = "hamlet.txt";

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << "START";
    
    ifstream infile(DEFAULT_FILE);
    
    if (!infile) {
        cerr << "NO FILE OPEN" << endl;
    }
    
    
    ThreadedBST tokenTree;
    
    char currentToken[99];
    
    
    
    cout << infile.eof();
    
    while (!infile.eof()) {
        cout << char(infile.peek());
        infile.getline(currentToken, 99, ' ');
        cout << currentToken;
        tokenTree.insert(currentToken);
    }
    
    cout << tokenTree.getNumberOfNodes();

    return 0;
}

