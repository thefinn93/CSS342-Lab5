#include "credits.cpp"
#include "nodeData.h"
#include "node.h"
#include "tbst.h"
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

int WIDTH = 35;

int const DEFAULT_TEST_SIZE = 13;

/// The int value that, when cast as a char, becomes a capital A
int const INTTOCHAR_CAPS_START = 65;

/// The int value that, when cast as a char, becomes a lower case a
int const INTTOCHAR_LOWER_START = 97;

/// The size of the alphabet
int const ALPHABET_SIZE = 26;

void testNodeDataConstructors() {
    cout << "NodeData Constructors Tests" << endl;
    cout.width(WIDTH);
    cout << left << "Empty constructor:";
    try {
        NodeData emptyConstructor = NodeData();
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Full constructor:";
    try {
        NodeData fullConstructor = NodeData((string)"Test", 1);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Token-only constuructor:";
    try {
        NodeData tokenOnly = NodeData((string)"moretest");
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Negative frequency:";
    try {
        NodeData negativeFreq = NodeData((string)"wat", -1);
        cout << "FAIL (didn't throw exception)";
    } catch (const char* error) {
        if(strcmp(error, "Negative frequency") == 0) {
            cout << "PASS (exception: " << error << ")";
        } else {
            cout << "FAIL (incorrect exception " << error << ")";
        }
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Copy constructor:";
    NodeData copyme = NodeData((string)"test");
    try {
        NodeData copyconstructor = NodeData(copyme);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

}

void testNodeDataGetters() {
    cout << "NodeData Getters Tests" << endl;
    NodeData getMyData = NodeData("omgtoken", 3);

    cout.width(WIDTH);
    cout << "getToken():";
    string token = getMyData.getToken();
    if(token.compare("omgtoken") == 0) {
        cout << "PASS";
    } else {
        cout << "FAIL (" << getMyData.getToken() << ")";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "getFrequency():";
    if(getMyData.getFrequency() == 3) {
        cout << "PASS";
    } else {
        cout << "FAIL (" << getMyData.getFrequency() << ")";
    }
    cout << endl;

}

void testNodeDataSetters() {
    cout << "Setters Tests" << endl;
    NodeData setMyData = NodeData();

    cout.width(WIDTH);
    cout << "setToken():";
    setMyData.setToken("loltoken");
    if(setMyData.getToken().compare("loltoken") == 0) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "setFrequency():";
    setMyData.setFrequency(5);
    if(setMyData.getFrequency() == 5) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "setFrequency() invalid:";
    try {
        if(setMyData.setFrequency(-3)) {
            if(setMyData.getFrequency() == -3) {
                cout << "FAIL (returned true, set invalid frequency)";
            } else if(setMyData.getFrequency() == 5) {
                cout << "FAIL (returned true but did not set)";
            } else {
                cout << "FAIL (returned true, set frequency to " <<
                    setMyData.getFrequency();
            }
        } else {
            if(setMyData.getFrequency() == -3) {
                cout << "FAIL (returned false, but set invalid frequency)";
            } else if(setMyData.getFrequency() == 5) {
                cout << "PASS (returned false)";
            } else {
                cout << "FAIL (returned false, set frequency to " <<
                    setMyData.getFrequency();
            }
        }
    } catch (const char* error) {
        if(strcmp(error, "Invalid frequency") == 0) {
            cout << "PASS";
        } else {
            cout << "FAIL";
        }
        cout << "(threw error " << error << ")";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "increaseFrequency default:";
    setMyData.setFrequency(1);
    setMyData.increaseFrequency();
    if(setMyData.getFrequency() == 2) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "increaseFrequency non-default:";
    setMyData.setFrequency(1);
    setMyData.increaseFrequency(3);
    if(setMyData.getFrequency() == 4) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "increaseFrequency invalid:";
    setMyData.setFrequency(3);
    try {
        setMyData.increaseFrequency(-1);
        if(setMyData.getFrequency() == 3) {
            cout << "PASS (didn't throw anything)";
        } else if(setMyData.getFrequency() == 2) {
            cout << "FAIL (decreased frequency when fed negative)";
        } else {
            cout << "FAIL (set frequency to " << setMyData.getFrequency()
                << ")";
        }
    } catch(const char* error) {
        if(strcmp(error, "Cannot increase frequency negatively") == 0) {
            cout << "PASS";
        } else {
            cout << "FAIL";
        }
        cout << " (threw " << error << ")";
    } catch(...) {
        cout << "FAIL (Threw something other than a const char)";
    }
    cout << endl;

    setMyData.setFrequency(3);
    cout.width(WIDTH);
    cout << "Decrease frequency:";
    setMyData.decreaseFrequency();
    if(setMyData.getFrequency() == 2) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    setMyData.setFrequency(3);
    cout.width(WIDTH);
    cout << "Decrease frequency (non-default):";
    setMyData.decreaseFrequency(2);
    if(setMyData.getFrequency() == 1) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    setMyData.setFrequency(3);
    cout.width(WIDTH);
    cout << "Decrease frequency (invalid):";
    try {
        setMyData.decreaseFrequency(-1);
        if(setMyData.getFrequency() == 3) {
            cout << "PASS (didn't throw anything)";
        } else if(setMyData.getFrequency() == 2) {
            cout << "FAIL (decreased frequency when fed negative)";
        } else if(setMyData.getFrequency() == 4) {
            cout << "FAIL (increased frequency when fed negative)";
        } else {
            cout << "FAIL (set frequency to " << setMyData.getFrequency()
                << ")";
        }
    } catch(const char* error) {
        if(strcmp(error, "Cannot decrease frequency negatively") == 0) {
            cout << "PASS";
        } else {
            cout << "FAIL";
        }
        cout << " (threw " << error << ")";
    } catch(...) {
        cout << "FAIL (Threw something other than a const char)";
    }
    cout << endl;
}

void testNodeDataStreams() {
    cout << "NodeData Stream Tests" << endl;
    NodeData streamMe = NodeData("test", 3);
    cout.width(WIDTH);
    cout << left << "Testing ostream:";
    cout << streamMe << endl;
    for(int positionOnLine = 0; positionOnLine < WIDTH; positionOnLine++) {
        /// Print the proper number of spaces to make this line up with
        /// the line above
        cout << " ";
    }
    cout << "test (3)" << endl;
}

void testNodeDataOperators() {
    cout << "Operators Tests" << endl;
    NodeData apples = NodeData("apples");
    NodeData bananas = NodeData("bananas");
    NodeData bananas2 = NodeData("bananas");

    cout.width(WIDTH);
    cout << "Less than (<) positve:";
    if(apples < bananas) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Less than (<) negative:";
    if(bananas < apples) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Greater than (>) positive:";
    if(bananas > apples) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Greater than (>) negative:";
    if(apples > bananas) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;


    cout.width(WIDTH);
    cout << "Equal to (==) positive:";
    if(bananas == bananas2) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Equal to (==) negative:";
    if(apples == bananas) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Assignment (=) operator:";
    NodeData applesCopy = apples;
    if(applesCopy == apples) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;
}

void testNodeConstructors() {
    cout << "Testing Node Constructors" << endl;

    cout.width(WIDTH);
    cout << left << "Empty constructor test:";
    try {
        Node emptyConstructorTest();
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Copy constructor test:";
    Node copyMe = Node();
    try {
        Node copiedNode = Node(copyMe);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Token-only constructor test:";
    try {
        Node tokenConstructor = Node("test");
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Token, frequency constructor test:";
    try {
        Node fullNodeDataConstructor = Node("test", 3);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;


    cout.width(WIDTH);
    cout <<  left << "Full constructor test:";
    NodeData fullNodeData = NodeData("testing", 5);
    Node* leftChild = new Node();
    Node* rightChild = new Node();
    try {
        Node fullConstructor = Node(fullNodeData, leftChild, rightChild, true,
                true);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;
    delete rightChild;
    delete leftChild;
}

void testNodeOperators() {
    cout << "Node Operator Test" << endl;

    cout.width(WIDTH);
    cout <<  left << "Less than (<) operator:";
    Node nodeApples = Node("apples");
    Node nodeBananas = Node("bananas");

    if(nodeApples < nodeBananas) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Less than (<) operator negative:";
    if(nodeBananas < nodeApples) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Greater than (>) operator:";

    if(nodeBananas > nodeApples) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Greater than (>) operator negative:";
    if(nodeApples > nodeBananas) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    Node nodeApples2 = Node("apples");
    cout.width(WIDTH);
    cout <<  left << "Equality (==) operator:";

    if(nodeApples == nodeApples2) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Equality (==) operator negative:";
    if(nodeBananas == nodeApples) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "Assignment (=) operator:";
    Node nodeBananas2 = nodeBananas;
    if(nodeBananas2 == nodeBananas) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;
}

void testNodeGetters() {
    cout << "Node Getters Test" << endl;

    cout.width(WIDTH);
    cout << "getData():";
    NodeData applesNodeData = NodeData("apples", 4);
    Node applesNode = Node("apples", 4);
    if(applesNode.getData() == applesNodeData) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "isLeftPtrThread():";
    Node* child = new Node();
    Node applesNodeWithThreads = Node(applesNodeData, child, child, true,
            false);
    if(applesNodeWithThreads.isLeftPtrThread()) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "isRightPtrThread():";
    if(applesNodeWithThreads.isRightPtrThread()) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "getLeftChildPtr():";
    if(applesNodeWithThreads.getLeftChildPtr() == child) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    /// This one really serves no purpose, unless we accidently break one but
    /// not the other, which seems highly unlikely to happen.
    cout.width(WIDTH);
    cout << "getRightChildPtr():";
    if(applesNodeWithThreads.getRightChildPtr() == child) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    delete child;
}

void testSetters() {
    cout << "Node Setters Test" << endl;

    cout.width(WIDTH);
    cout << "setData():";
    Node testSetData = Node();
    NodeData dataToSet = NodeData("OMGTOKEN", 5);
    testSetData.setData(dataToSet);
    if(testSetData.getData() == dataToSet) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "setLeftPtrIsThread():";
    Node* child = new Node();
    Node testThreadSetters = Node(dataToSet, child, child, false, false);
    testThreadSetters.setLeftPtrIsThread(true);
    if(testThreadSetters.isLeftPtrThread()) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "setRightPtrIsThread():";
    testThreadSetters.setRightPtrIsThread(true);
    if(testThreadSetters.isRightPtrThread()) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    Node* otherChild = new Node();
    cout.width(WIDTH);
    cout << left << "setLeftPtr():";
    testThreadSetters.setLeftPtr(otherChild);
    if(testThreadSetters.getLeftChildPtr() == otherChild) {
        cout << "PASS";
    } else if(testThreadSetters.getLeftChildPtr() == child) {
        cout << "FAIL";
    } else {
        cout << "FAIL (set pointer to something else)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << left << "setRightPtr():";
    testThreadSetters.setRightPtr(otherChild);
    if(testThreadSetters.getRightChildPtr() == otherChild) {
        cout << "PASS";
    } else if(testThreadSetters.getRightChildPtr() == child) {
        cout << "FAIL";
    } else {
        cout << "FAIL (set pointer to something else)";
    }
    cout << endl;


    delete otherChild;
    delete child;

}

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

void testTBSTConstructors() {
    cout << "TBST Testing Constructors" << endl;
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

ThreadedBST testTBSTInsertion(int testSize) {
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

void testTBSTTraversal(ThreadedBST traverseMe) {
    cout << "================ Traversals ====================" << endl;
    cout << "Iterative in order:" << endl;
    traverseMe.iterativeInorder(visitAndPrint);
}

void testTBSTRemove() {
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

void testTBSTMisc() {
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
    testNodeDataConstructors();
    testNodeDataGetters();
    testNodeDataSetters();
    testNodeDataStreams();
    testNodeDataOperators();

    testNodeConstructors();
    testNodeOperators();
    testNodeGetters();


    testTBSTConstructors();
    int testSize = getTestSize(argc, argv);
    ThreadedBST traverseMe = testTBSTInsertion(testSize);
    testTBSTTraversal(traverseMe);
    testTBSTRemove();
    testTBSTMisc();
    return 0;
}
