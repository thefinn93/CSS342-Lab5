/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 * 
 */

#ifndef NODEDATA_H
#define	NODEDATA_H

#include <iostream>
#include <string>

using namespace std;

class NodeData {
    /*-------ostream operators------*/
    /**
     * The ostream operator<< overload.
     * @return An ostream with the token followed by its frequency
     */
    friend ostream& operator<< (ostream&, const NodeData&);

public:
    /*-------Assignment Operator-------*/
    /**
     * The assignment operator= overload.
     * @param rightData The NodeData containing the variables values the left
     * side NodeData is being assigned.
     * @return Reference to a new NodeData that is a copy of the right side
     * NodeData.
     */
    NodeData& operator=(const NodeData& rightData);

    /*-------Comparison Operators-------*/
    /**
     * The equality comparison operator==.
     * @param rightData The NodeDatat the left side is being compared to.
     * @return True if the NodeData objects contain identical data.
     */
    bool operator== (const NodeData& rightData) const;

    /**
     * The less than comparison operator<.
     * @param rightData The nodeData the left side is being compared to.
     * @return True if the leftData character value is less that the rightData
     * character value.
     */
    bool operator< (const NodeData& rightData) const;
    /**
     * The greater than comparison operator>.
     * @param rightData The NodeData the left side is being compared to.
     * @return True if leftData character value is greater than rightData
     * character value.
     */
    bool operator> (const NodeData& rightData) const;

    /*-------Constructors-------*/

    /**
     * The empty constructor, initializes the node token to "" and frequency
     * to 0.
     */
    NodeData();

    /**
     * A full constructor, which accepts the full array of data that the node
     * can hold, which are subsequently stored in the node.
     * @param newFrequency  The frequency data to store in the node.
     * @param newToken      The token data to store in the node.
     */
    NodeData(string newToken, int newFrequency);

    /**
     * A token-only constructor.
     * @param newToken      The token data to store in the node.
     */
    NodeData(string newToken);

    /**
     * Copy constructor. Copies the data over, leaving the pointers NULL.
     * @param nodeDataToCopy The NodeData to copy
     */
    NodeData(NodeData const &nodeDataToCopy);


    /*-------Public Methods-------*/

    /**
     * NodeData frequency getter.
     * @return The frequency of the token stored in this node.
     */
    int getFrequency() const;

    /**
     * NodeData token getter.
     * @return The token stored in this node.
     */
    string getToken() const;

    /**
     * Increments frequency.
     * @param amount    The amount to increase the frequency by. Defaults to 1
     * @return True if increment successful.
     */
    bool increaseFrequency(int amount);

    /**
     * Decrement frequency. Should not be needed.
     * @param amount    The amount to decrease the frequency by. Defaults to 1.
     * @return True if decrement successful.
     */
    bool decreaseFrequency(int amount);


    /**
     * Sets the token data stored in this node.
     * @return True if successful.
     */
    bool setToken(string newToken);

    /**
     * Set the NodeData frequency equal to newFreqency.
     * @param newFrequency The new frequency of the token in the NodeData.
     * @return True if new frequency set successfully.
     */
    bool setFrequency(int newFrequency);

private:
    /// Stores the frequency data
    int frequency;

    /// Stores the token data
    string token;
};

//#include "nodeData.cpp"
#endif	/* NODEDATA_H */

