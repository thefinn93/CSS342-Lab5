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

void testSetters() {
    cout << "================= Setters Tests ==================" << endl;
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
}

void testStreams() {
    cout << "================= Stream Tests ==================" << endl;
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

void testOperators() {
    cout << "================= Operators Tests ==================" << endl;
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
        cout "PASS";
    } else {
        cout "FAIL";
    }
    cout << endl;
}

int main(int argc, char** argv) {
    credits();
    testConstructors();
    testGetters();
    testSetters();
    testStreams();
    testOperators();
    return 0;
}
