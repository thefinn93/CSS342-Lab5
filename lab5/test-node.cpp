#include "credits.cpp"
#include "node.h"

#include <string>

int WIDTH = 35;

void testConstructors() {
    cout << "============== Constructors =================" << endl;

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

void testOperators() {
    cout << "===================== Operators Test ===================" << endl;

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

void testGetters() {
    cout << "===================== Getters Test ===================" << endl;

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
    cout << "===================== Setters Test ===================" << endl;

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

int main() {
    credits();
    testConstructors();
    testOperators();
    testGetters();
    return 0;
}
