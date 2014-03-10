#include "credits.cpp"
#include "nodeData.h"
#include <string>

using namespace std;

int WIDTH = 30;

void testConstructors() {
    cout.width(WIDTH);
    cout << left << "Empty constructor:";
    NodeData emptyConstructor = NodeData();
    cout << "PASS (didn't crash)" << endl;

    cout.width(WIDTH);
    cout << left << "Full constructor:";
    NodeData fullConstructor = NodeData((string)"Test", 1);
    cout << "PASS (didn't crash)" << endl;

    cout.width(WIDTH);
    cout << left << "Token-only constuructor:";
    NodeData tokenOnly = NodeData((string)"moretest");
    cout << "PASS (didn't crash)" << endl;
}

int main(int argc, char** argv) {
    credits();
    testConstructors();
    return 0;
}
