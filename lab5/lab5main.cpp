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
#include "credits.cpp"

using namespace std;

char const DEFAULT_FILE[] = "hamlet.txt";

int main(int argc, char** argv) {
    credits();

    ifstream infile(DEFAULT_FILE);

    if (!infile) {
        cerr << "NO FILE OPEN" << endl;
        exit(1);
    }


    ThreadedBST tokenTree;

    char currentToken[99];
    char checkForSkipChar[1];


    while (!infile.eof()) {
        while (char(infile.peek()) == '\n' || char(infile.peek()) == '\t') {
            infile.ignore(1);
        }
        infile.getline(currentToken, 99, ' ');
        cout << currentToken << endl;
        tokenTree.insert(currentToken);
    }


    return 0;
}

