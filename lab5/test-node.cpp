#include "credits.cpp"
#include "node.h"
#include "nodeData.h"

#include <string>

int WIDTH = 30;

void testConstructors() {
    cout << "============== Constructors =================" << endl;

    cout.width(WIDTH);
    cout << "Empty constructor test:";
    try {
        Node emptyConstructorTest = Node();
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Copy constructor test:";
    Node copyMe = Node();
    try {
        Node copiedNode = Node(copyMe);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Full constructor test:";
    Node *left = new Node();
    Node *right = new Node();
    NodeData *data = new NodeData("test", 3);
    try {
        Node fullConstructor = Node(data, left, right, true, true);
        cout << "PASS (didn't crash)";
    } catch(...) {
        cout << "FAIL (crashed)";
    }
    delete left;
    delete right;
    delete data;
}

void testOperators() {
    cout << "===================== Operators Test ===================" << endl;

    cout.width(WIDTH);
    cout << "Less than (<) operator:";
    NodeData* apples = new NodeData("apples");
    NodeData* bananas = new NodeData("bananas");
    Node* left = new Node();
    Node* right = new Node();
    Node nodeApples = Node(apples, left, right, true, true);
    Node nodeBananas = Node(bananas, left, right, true, true);

    if(nodeBananas < nodeApples) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Less than (<) operator negative:";
    if(nodeApples < nodeBananas) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Greater than (>) operator:";

    if(nodeApples > nodeBananas) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Greater than (>) operator negative:";
    if(nodeBananas > nodeApples) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    Node nodeApples2 = Node(apples, left, right, true, true);
    cout.width(WIDTH);
    cout << "Equality (==) operator:";

    if(nodeApples == nodeApples2) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << endl;

    cout.width(WIDTH);
    cout << "Equality (==) operator negative:";
    if(nodeBananas == nodeApples) {
        cout << "FAIL";
    } else {
        cout << "PASS";
    }
    cout << endl;

    delete left;
    delete right;
    delete apples;
    delete bananas;

}


int main() {
    credits();
    testConstructors();
    return 0;
}
