/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 * 
 */

#ifndef NODE_CPP
#define	NODE_CPP

#include "node.h"

using namespace std;

/**
 * A node in a ThreadedBST
 */

    /**
     * The empty constructor, initializes the node with empty data values
     * and NULL child pointers
     */
    Node::Node() {

    }

    /**
     * A full constructor, which accepts the full array of data that the node
     * can hold, which are subsequently stored in the node.
     * @param data          The NodeData to store in the node.
     * @param left          A pointer to this node's left child (may be NULL)
     * @param right         A pointer to this node's right child (may be NULL)
     */
    Node::Node(NodeData data, Node* left, Node* right) {
    }

    /**
     * Copy constructor. Copies the data over, leaving the pointers NULL.
     * @param nodeToCopy
     */
    Node::Node(const NodeData& nodeToCopy) {
    }

    /**
     * @return The data stored in this node.
     */
    NodeData Node::getData() {
        return data;
    }

    /**
     * Sets the data stored in this node.
     * @param data  The data to store in this node
     * @return True if successful.
     */
    bool Node::setData(NodeData data) {
    }


#endif /* NODE */
