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

int main() {
    credits();
    testConstructors();
    return 0;
}
