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
    //if (token is == rightData token & quantity == rightData quantity)
    //return true, else return false
}

/**
 * The less than comparison operator<.
 * @param rightData The nodeData the left side is being compared to.
 * @return True if the leftDeata character value is less that the rightData character value.
 */
bool NodeData::operator< (const NodeData& rightData) const {
    //if token ascii value is less than rightData token ascii value
    //return true, else return false
}

/**
 * The greater than comparison operator>.
 * @param rightData The NodeData the left side is being compared to.
 * @return True if leftData character value is greater than rightData character value.
 */
bool NodeData::operator> (const NodeData& rightData) const{
    //if the token ascii value is greater than the rightData token ascii value
    //return true, else return false
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
    //set token to newToken[]
    //set frequency to newFrequency
}

/**
 * Copy constructor. Copies the data over, leaving the pointers NULL.
 * @param nodeDataToCopy The NodeData to copy
 */
NodeData::NodeData(const NodeData& nodeDataToCopy) {
    //using getters
    //set token to nodeDataToCopy token
    //set frequency to nodeDataToCopy frequency
}


/*-------Public Methods-------*/

/**
 * NodeData frequency getter.
 * @return The frequency of the token stored in this node.
 */
const int NodeData::getFrequency() {
    //return frequency
}

/**
 * NodeData token getter.
 * @return The token stored in this node.
 */
const char NodeData::getToken() {
    //return token
    /*token is a char[], will this work*/
}

/**
 * Increments frequency up by one.
 * @return True if increment successful.
 */
bool NodeData::increaseFrequency() {
    //set frequency equal to frequency + 1
    //return True
}

/**
 * Decrement frequency down by one. Should not be needed.
 * @pre Assumes frequency >= 1
 * @return True if decrement successful.
 */
bool NodeData::decreaseFrequency() {
    //set frequency equal to frequency - 1
    //return True
    /* Note
     * DecreaseFrequency does no error checking.
     * Error checking should be done during implementation.
     * (Is this correct thinking? Not sure)
     */
}


/**
 * Sets the token data stored in this node.
 * @pre Assumes newToken is a valid char[]
 * @return True if successful.
 */
bool NodeData::setToken(char newToken[]) {
    //set token equal to newToken
    //return True
}

/**
 * Set the NodeData frequency equal to newFrequency.
 * @param newFrequency The new frequency of the token in the NodeData.
 * @pre Assumes newFrequency is >= 1
 * @return True if new frequency set successfully.
 */
bool NodeData::setFrequency(int newFrequency) {
    //set frequency equal to newFrequency
    //return True
    /* Note
     * setFrequency does no error checking.
     * Error checking should be done during implementation.
     * (Is this correct thinking? Not sure)
     */
}

#endif /* NODEDATA_CPP */

