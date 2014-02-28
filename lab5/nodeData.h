/**
 * 
 */

#ifndef NODEDATA_H
#define	NODEDATA_H

class NodeData {
    
public:

    
    /*-------Constructors-------*/
    
    /**
     * The empty constructor, initializes the node with empty data values
     * and NULL child pointers
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
    NodeData(const NodeData& nodeToCopy);

    
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
    
    
    bool increaseFrequency();
    
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

