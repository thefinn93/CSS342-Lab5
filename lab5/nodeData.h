/* 
 * File:   nodeData.h
 * Author: Nick
 *
 * Created on February 26, 2014, 8:11 PM
 */

#ifndef NODEDATA_H
#define	NODEDATA_H

class nodeData {
public:

    /**
     * The empty constructor, initializes the node with empty data values
     * and NULL child pointers
     */
    nodeData();

    /**
     * A full constructor, which accepts the full array of data that the node
     * can hold, which are subsequently stored in the node.
     * @param newFrequency  The frequency data to store in the node.
     * @param newToken      The token data to store in the node.
     * @param left          A pointer to this node's left child (may be NULL)
     * @param right         A pointer to this node's right child (may be NULL)
     */
    nodeData(int newFrequency, char[] newToken, char nodeData* left, nodeData* right);

    /**
     * Copy constructor. Copies the data over, leaving the pointers NULL.
     * @param nodeToCopy
     */
    nodeData(const nodeData& nodeToCopy);

    /**
     * @return The frequency data stored in this node.
     */
    int getFrequency();

    /**
     * @return The token data in this node.
     */
    char getToken();

    /**
     * Sets the frequency data stored in this node.
     * @return True if successful.
     */
    bool setFrequncy();

    /**
     * Sets the token data stored in this node.
     * @return True if successful.
     */
    bool setToken();

private:

    /// Stores the frequency data
    int frequency;

    /// Stores the token data
    char token[];

    /// A pointer to this node's left child
    nodeData* leftChildPtr;

    /// A pointer to this node's right child
    nodeData* rightChildPtr;

};

#endif	/* NODEDATA_H */

