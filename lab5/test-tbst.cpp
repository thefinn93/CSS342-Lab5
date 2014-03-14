#include "credits.cpp"
#include "tbst.h"

int WIDTH = 30;

int getTestSize(int argc, char** argv) {
    int testSize = 13;
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
}

void testInsertion(int testSize) {
    cout << "================= Testing Insertion ====================" << endl;
    cout << "no tests yet defined. Would be inserting " << testSize
        << " nodes into a tree" << endl;
}

void testTraversal() {
    cout << "================ Testing Traversals ====================" << endl;
    cout << "no tests yet defined" << endl;
}

void testRemove() {
    cout << "================== Testing Removing ====================" << endl;
    cout << "no tests yet defined" << endl;
}

int main(int argc, char** argv) {
    credits();
    testConstructors();
    int testSize = getTestSize(argc, argv);
    testInsertion(testSize);
    testTraversal();
    testRemove();
    return 0;
}
