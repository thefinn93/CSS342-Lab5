/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 * 
 */

#ifndef NODE
#define	NODE

#include "node.h"

/**
 * A node in a ThreadedBST
 */
class Node {
    /**
     * The empty constructor, initializes the node with empty data values
     * and NULL child pointers
     */
    Node() {

    }

    /**
     * A full constructor, which accepts the full array of data that the node
     * can hold, which are subsequently stored in the node.
     * @param data          The NodeData to store in the node.
     * @param left          A pointer to this node's left child (may be NULL)
     * @param right         A pointer to this node's right child (may be NULL)
     */
    Node(NodeData data, Node* left, Node* right) {
    }

    /**
     * Copy constructor. Copies the data over, leaving the pointers NULL.
     * @param nodeToCopy
     */
    Node(const NodeData& nodeToCopy) {
    }

    /**
     * @return The data stored in this node.
     */
    NodeData getData() {
    }

    /**
     * Sets the data stored in this node.
     * @param data  The data to store in this node
     * @return True if successful.
     */
    bool setData(NodeData data) {
    }
};

#endif /* NODE */
