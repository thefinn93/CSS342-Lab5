/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 *
 */

#ifndef NODEDATA_CPP
#define NODEDATA_CPP

#include "nodeData.h"

#include <iostream>

using namespace std;

/*-------ostream operators------*/

/**
 * The ostream operator<< overload.
 * @return A ostream with the token followed by its frequency, separated by a space.
 */
ostream& operator<< (ostream &output, const NodeData &thisNode) {
    //Print NodeData token, followed by NodeData frequency
    output << thisNode.token << "\t" << thisNode.frequency;
    return output;
}

/*-------Assignment Operator-------*/

/**
 * The assignment operator= overload.
 * @param rightData The NodeData containing the variables values the left side NodeData is being assigned.
 * @return Reference to a new NodeData that is a copy of the right side NodeData.
 */
NodeData& NodeData::operator=(const NodeData& right) {
    this->token = right.getToken();
    this->frequency = right.getFrequency();
    return *this;
}

/*-------Comparison Operators-------*/

/**
 * The equality comparison operator==.
 * @param rightData The NodeDatat the left side is being compared to.
 * @return True if the NodeData objects contain identical data.
 */
bool NodeData::operator==(const NodeData& right) const {
    if (token.compare(right.getToken()) == 0) {
        return true;    // Tokens match.
    } else {
        return false;   // Tokens do not match.
    }
}
/**
 * The less than comparison operator<.
 * @param right The nodeData the left side is being compared to.
 * @return True if the leftDeata character value is less that the rightData
 * character value.
 */
bool NodeData::operator< (const NodeData& right) const {
    string rightToken = right.getToken();
    for(int character = 0; character < (int)token.size() &&
            character < (int)rightToken.size(); character++) {
        // Compare the ASCII values of the two characters
        if(token[character] < rightToken[character]) {
            return true;
        } else if(token[character] > rightToken[character]) {
            return false;
        }
    }
    // At this point, the two strings are equal up to the length of the shorter
    // one. If right is longer, we say it's greater
    return token.size() < rightToken.size();
}

/**
 * The greater than comparison operator.
 * @param right The nodeData the left side is being compared to.
 * @return True if the leftDeata character value is less that the rightData
 * character value.
 */
bool NodeData::operator>(const NodeData& right) const {
    string rightToken = right.getToken();
    for(int character = 0; character < (int)token.size() &&
            character < (int)rightToken.size(); character++) {
        // Compare the ASCII values of the two characters
        if(token[character] < rightToken[character]) {
            return false;
        } else if(token[character] > rightToken[character]) {
            return true;
        }
    }
    // At this point, the two strings are equal up to the length of the shorter
    // one. If right is longer, we say it's greater
    return token.size() > rightToken.size();
}
/*-------Constructors-------*/

/**
 * The empty constructor, initializes the node token to "" and frequency to 0.
 */
NodeData::NodeData() {
    token = "";
    frequency = 0;
}

/**
 * A full constructor, which accepts the full array of data that the node
 * can hold, which are subsequently stored in the node.
 * @param newFrequency  The frequency data to store in the node.
 * @param newToken      The token data to store in the node.
 */
NodeData::NodeData(string newToken, int newFrequency) {
    if(newFrequency < 0) {
        /// I'm sure there is a nicer way to do exceptions, but I don't know it
        throw "Negative frequency";
    } else {
        token = newToken;
        frequency = newFrequency;
    }
}

/**
 * A token-only constructor, which initializes the frequency to 1.
 * @param newToken  The token to store in the node
 */
NodeData::NodeData(string newToken) {
    token = newToken;
    frequency = 1;
}

/**
 * Copy constructor. Copies the data over, leaving the pointers NULL.
 * @param toCopy The NodeData to copy
 */
NodeData::NodeData(NodeData const &toCopy) {
    frequency = toCopy.getFrequency();
    token = toCopy.getToken();
}


/*-------Public Methods-------*/

/**
 * NodeData frequency getter.
 * @return The frequency of the token stored in this node.
 */
int NodeData::getFrequency() const {
    return frequency;
}

/**
 * NodeData token getter.
 * @return The token stored in this node.
 */
string NodeData::getToken() const {
    return token;
}

/**
 * Increments frequency.
 * @param amount    The amount to increase the frequency by. Defaults to 1.
 * @return True if increment successful.
 */
bool NodeData::increaseFrequency(int amount = 1) {
    if(amount > 0) {
        frequency += amount;
        return true;
    } else {
        return false;
    }
}

/**
 * Decrement frequency. Should not be needed.
 * @param amount    The amonut to decrease the frequency by. Defaults to 1.
 * @pre Assumes frequency >= 1
 * @return True if decrement successful.
 */
bool NodeData::decreaseFrequency(int amount = 1) {
    // Cannot end up less than zero
    if(amount > 0){
        if(frequency-amount >= 0) {
            frequency -= amount;
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}


/**
 * Sets the token data stored in this node.
 * @pre Assumes newToken is a valid char[]
 * @return True if successful.
 */
bool NodeData::setToken(string newToken) {
    token = newToken;
    return true;
}

/**
 * Set the NodeData frequency equal to newFrequency.
 * @param newFrequency The new frequency of the token in the NodeData.
 * @pre Assumes newFrequency is >= 1
 * @return True if new frequency set successfully.
 */
bool NodeData::setFrequency(int newFrequency) {
    if(newFrequency >= 0) {
        frequency = newFrequency;
        return true;
    } else {
        return false;
    }
}

#endif /* NODEDATA_CPP */

