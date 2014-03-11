#include "credits.cpp"
#include "nodeData.h"
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

int WIDTH = 30;

void testConstructors() {
    cout << "================= Constructors Tests ==================" << endl;
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

void testGetters() {
    cout << "================= Getters Tests ==================" << endl;
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


int main(int argc, char** argv) {
    credits();
    testConstructors();
    testGetters();
    return 0;
}
