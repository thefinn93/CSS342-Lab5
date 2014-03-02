#ifndef NODEDATA_CPP
#define NODEDATA_CPP

#include "nodeData.h"

using namespace std;

/*-------ostream operators------*/

/**
 * The ostream operator<< overload.
 * @return A ostream with the token followed by its frequency, separated by a space.
 */
ostream& operator<< (ostream&, const NodeData&) {
    //Print NodeData token, followed by NodeData frequency
}

/*-------Assignment Operator-------*/

/**
 * The assignment operator= overload.
 * @param rightData The NodeData containing the variables values the left side NodeData is being assigned.
 * @return Reference to a new NodeData that is a copy of the right side NodeData.
 */
NodeData& NodeData::operator=(const NodeData& rightData) {
    //set variable values of leftData to variable values of rightData
}

/*-------Comparison Operators-------*/

/**
 * The equality comparison operator==.
 * @param rightData The NodeDatat the left side is being compared to.
 * @return True if the NodeData objects contain identical data.
 */
bool NodeData::operator== (const NodeData& rightData) const {

}

/**
 * The less than comparison operator<.
 * @param rightData The nodeData the left side is being compared to.
 * @return True if the leftDeata character value is less that the rightData character value.
 */
bool NodeData::operator< (const NodeData& rightData) const {

}

/**
 * The greater than comparison operator>.
 * @param rightData The NodeData the left side is being compared to.
 * @return True if leftData character value is greater than rightData character value.
 */
bool NodeData::operator> (const NodeData& rightData) const{

}

/*-------Constructors-------*/

/**
 * The empty constructor, initializes the node token to "" and frequency to 0.
 */
NodeData::NodeData():token(""), frequency(0) {
}

/**
 * A full constructor, which accepts the full array of data that the node
 * can hold, which are subsequently stored in the node.
 * @param newFrequency  The frequency data to store in the node.
 * @param newToken      The token data to store in the node.
 */
NodeData::NodeData(char newToken[], int newFrequency = 1) {
}

/**
 * Copy constructor. Copies the data over, leaving the pointers NULL.
 * @param nodeDataToCopy The NodeData to copy
 */
NodeData::NodeData(const NodeData& nodeDataToCopy) {

}


/*-------Public Methods-------*/

/**
 * NodeData frequency getter.
 * @return The frequency of the token stored in this node.
 */
const int NodeData::getFrequency() {

}

/**
 * NodeData token getter.
 * @return The token stored in this node.
 */
const char NodeData::getToken() {

}

/**
 * Sets the frequency data stored in this node.
 * @return True if successful.
 */

/**
 * Increments frequency up by one.
 * @return True if increment successful.
 */
bool NodeData::increaseFrequency() {

}

/**
 * Decrement frequency down by one. Should not be needed.
 * @return True if decrement successful.
 */
bool NodeData::decreaseFrequency() {

}


/**
 * Sets the token data stored in this node.
 * @return True if successful.
 */
bool NodeData::setToken(char newToken[]) {

}

#endif /* NODEDATA_CPP */

