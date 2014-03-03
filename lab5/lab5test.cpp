/* 
 * File:   lab5test.cpp
 * Author: Nick
 *
 * Created on February 26, 2014, 8:21 PM
 */

#include <cstdlib>

using namespace std;

/*NodeData Tests*/

/*Testing Constructors*/

NodeData::NodeData():token(""), frequency(0)

/*
 * Test NodeData()
 * Returns a boolean
 * 
 * Create new NodeData()
 * Check that default values are as expected.
 * Use NodeData() getters.
 * token: ""
 * frequency: 0
 * If token and frequency match these values, return True
 */

NodeData::NodeData(char newToken[], int newFrequency = 1)

//Good data tests

/*
 * Test NodeData(char newToken[])
 * Returns a boolean.
 * 
 * Create new NodeData("Test")
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Test"
 * frequency: 1
 * If token and frequency match these values, return True
 */

/*
 * Test NodeData(char newToken[], int newFrequency)
 * Returns a boolean.
 * 
 * Create new NodeData("Test", 5)
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Test"
 * frequency: 5
 * If token and frequency match these values, return True
 */

//Bad data tests

/*
 * Test NodeData(char newToken[], int newFrequency)
 * Returns a boolean.
 * 
 * Create new NodeData("Test", 5)
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Test"
 * frequency: 5
 * If token and frequency match these values, return True
 */

NodeData::NodeData(const NodeData& nodeDataToCopy) {

}


int main(int argc, char** argv) {

    return 0;
}

