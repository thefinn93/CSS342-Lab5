#include "credits.cpp"
#include "node.h"

#include <string>

int WIDTH = 30;

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
        Node tokenConstructor = Node((string)"test");
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
    Node nodeApples = Node((string)"apples");
    Node nodeBananas = Node((string)"bananas");

    if(nodeBananas < nodeApples) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Less than (<) operator negative:";
    if(nodeApples < nodeBananas) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Greater than (>) operator:";

    if(nodeApples > nodeBananas) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout <<  left << "Greater than (>) operator negative:";
    if(nodeBananas > nodeApples) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    Node nodeApples2 = Node((string)"apples");
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

}


int main() {
    credits();
    testConstructors();
//    testOperators();
    return 0;
}
