#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "credits.cpp"
#include "tbst.h"


using namespace std;

int const WIDTH = 30;
int const DEFAULT_TEST_SIZE = 13;

/// The int value that, when cast as a char, becomes a capital A
int const INTTOCHAR_CAPS_START = 65;

/// The int value that, when cast as a char, becomes a lower case a
int const INTTOCHAR_LOWER_START = 97;

/// The size of the alphabet
int const ALPHABET_SIZE = 26;

int getTestSize(int argc, char** argv) {
    int testSize = DEFAULT_TEST_SIZE;
    if(argc > 1) {
        testSize = atoi(argv[1]);
    }
    if(testSize < 0) {
        cerr << "Test size may *not* be negative!" << endl;
        exit(1);
    }
    return testSize;
}

void testConstructors() {
    cout << "=============== Testing Constructors ==================" << endl;
    cout << "no tests yet defined" << endl;

    cout.width(WIDTH);
    cout << left << "Empty constructor:";
    ThreadedBST empty = ThreadedBST();
    cout << "PASS (didn't crash)" << endl;

    cout.width(WIDTH);
    cout << left << "Constructor with a root node:";
    Node* root = new Node();
    ThreadedBST constructorTest2 = ThreadedBST(root);
    cout << "PASS (didn't crash)" << endl;

    cout.width(WIDTH);
    cout << left << "Copy constructor:";
    ThreadedBST copy = ThreadedBST(constructorTest2);
    cout << "PASS (didn't crash)" << endl;
}

char* frequencyToToken(int frequency) {
    if(frequency < ALPHABET_SIZE*2 && frequency < 0) {
        if(frequency < ALPHABET_SIZE) {
            char* character;
            character[0] = char(frequency + INTTOCHAR_CAPS_START);
            cerr << "Character for " << frequency << " is " << character << endl;
            return character;
        } else {
            char* character;
            character[0] = char(frequency + INTTOCHAR_LOWER_START);
            cerr << "Character for " << frequency << " is " << character << endl;
            return character;
        }
    } else {
        throw("Can't stringify that int");
    }
}

ThreadedBST testInsertion(int testSize) {
    cout << "================= Testing Insertion ====================" << endl;
    cout.width(WIDTH);
    cout << "Insert just token";
    ThreadedBST tokenOnly = ThreadedBST();
    for(int treeSize = 0; treeSize < testSize; treeSize++) {
        cerr << "Inserted node #" << treeSize << endl;
        tokenOnly.insert(frequencyToToken(treeSize)); //, treeSize);
    }
    cout << "PASS (didn't crash, see traversal tests to actually verify "
        << "insertion" << endl;
    return tokenOnly;
}
void visitAndPrint(NodeData data) {
    cout << " * " << data << endl;
}

void testTraversal(ThreadedBST traverseMe) {
    cout << "================ Testing Traversals ====================" << endl;
//    void (visit)(NodeData) = visitAndPrint;
    traverseMe.preorder(visitAndPrint);
}

void testRemove() {
    cout << "================== Testing Removing ====================" << endl;
    cout << "no tests yet defined" << endl;
}

void testMisc() {
    cout << "=============== Testing Misc. Functions =================" << endl;
    cout << "no tests yet defined" << endl;
}

int main(int argc, char** argv) {
    credits();
    testConstructors();
    int testSize = getTestSize(argc, argv);
    ThreadedBST traverseMe = testInsertion(testSize);
    testTraversal(traverseMe);
    testRemove();
    testMisc();
    return 0;
}
