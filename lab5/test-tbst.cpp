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
    if(testSize < 1) {
        cerr << "Test size may *not* be negative or 0!" << endl;
        exit(1);
    }
    return testSize--;
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

string frequencyToToken(int frequency) {
    frequency++;
    if(frequency < ALPHABET_SIZE*2 && frequency > 0) {
        if(frequency < ALPHABET_SIZE) {
            char character(frequency + INTTOCHAR_CAPS_START);
            string characterAsString(1, character);
            return characterAsString;
        } else {
            char character(frequency + INTTOCHAR_LOWER_START);
            string characterAsString(1, character);
            return characterAsString;
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
        string tokenToInsert = frequencyToToken(treeSize);
        tokenOnly.insert(tokenToInsert); //, treeSize);
    }
    cout << "PASS (didn't crash, see traversal tests to actually verify "
        << "insertion" << endl;
    return tokenOnly;
}
void visitAndPrint(NodeData data) {
    cout << " * " << data << endl;
}

void testTraversal(ThreadedBST traverseMe) {
    cout << "================ Traversals ====================" << endl;
    cout << "Iterative in order:" << endl;
    traverseMe.inorder(visitAndPrint);
}

void testRemove() {
    cout << "================== Testing Removing ====================" << endl;
    ThreadedBST removeTest = ThreadedBST();
    removeTest.insert("remove this token");

    cout.width(WIDTH);
    cout << "Remove:";
    removeTest.remove("remove this token");
    if(removeTest.isEmpty()) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;
}

void testMisc() {
    cout << "=============== Testing Misc. Functions =================" << endl;

    cout.width(WIDTH);
    cout << left << "Testing isEmpty (positive):";
    ThreadedBST emptyBST = ThreadedBST();
    if(emptyBST.isEmpty()) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Testing isEmpty (negative):";
    ThreadedBST notSoEmptyBST = ThreadedBST();
    notSoEmptyBST.insert("nodes");
    notSoEmptyBST.insert("moreNodes");
    if(notSoEmptyBST.isEmpty()) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Test getNumberOfNodes:";
    if(notSoEmptyBST.getNumberOfNodes() == 2) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Test isTokenInTree:";
    if(notSoEmptyBST.isTokenInTree("nodes")) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Test isTokenInTree (negative):";
    if(notSoEmptyBST.isTokenInTree("this token does not exist")) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Test getFrequencyOfToken:";
    if(notSoEmptyBST.getFrequencyOfToken("nodes") == 1) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

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
