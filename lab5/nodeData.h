/**
 * 
 */

#ifndef NODEDATA_H
#define	NODEDATA_H

#include <iostream>

using namespace std;

class NodeData {
    
    /*-------ostream operators------*/
    
    /**
     * The ostream operator<< overload.
     * @return A ostream with the token followed by its frequency, separated by a space.
     */
    friend ostream& operator<< (ostream&, const NodeData&);
    
    
public:
    /*-------Assignment Operator-------*/
    
    /**
     * The assignment operator= overload.
     * @param Right
     * @return Reference to a new NodeData that is a copy of the right side NodeData.
     */
    NodeData& operator=(const NodeData& rightData);
    
    /*-------Comparison Operators-------*/
    
    /**
     * The equality comparison operator==.
     * @param rightData Nodedata the the left side Nodedata is being compared to.
     * @return True if the Nodedata objects contain identical data.
     */
    bool operator== (const NodeData& rightData) const;
    
    /**
     * The less than comparison operator<.
     * @param rightData
     * @return 
     */
    bool operator< (const NodeData& rightData) const;
    
    /**
     * The greater than comparison operator>.
     * @param rightData
     * @return 
     */
    bool operator> (const NodeData& rightData) const;
    
    /*-------Constructors-------*/
    
    /**
     * The empty constructor, initializes the node token to "" and frequency to 0.
     */
    NodeData();

    /**
     * A full constructor, which accepts the full array of data that the node
     * can hold, which are subsequently stored in the node.
     * @param newFrequency  The frequency data to store in the node.
     * @param newToken      The token data to store in the node.
     */
    NodeData(int newFrequency, char newToken[]);

    /**
     * Copy constructor. Copies the data over, leaving the pointers NULL.
     * @param nodeToCopy
     */
    NodeData(const NodeData& nodeDataToCopy);

    
    /*-------Public Methods-------*/
    
    /**
     * Node frequency access.
     * @return The frequency data stored in this node.
     */
    const int getFrequency();

    /**
     * 
     * @return The token data in this node.
     */
    const char getToken();

    /**
     * Sets the frequency data stored in this node.
     * @return True if successful.
     */
    
    /**
     * Increments frequency up by one.
     * @return True if increment successful.
     */
    bool increaseFrequency();
    
    /**
     * Decrement frequency down by one. Should not be needed.
     * @return True if decrement successful.
     */
    bool decreaseFrequency();
    

    /**
     * Sets the token data stored in this node.
     * @return True if successful.
     */
    bool setToken(char newToken[]);

private:
    
    /// Stores the frequency data
    int frequency;

    /// Stores the token data
    char token[];
    
};

#endif	/* NODEDATA_H */

