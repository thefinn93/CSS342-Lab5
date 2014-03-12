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


/*-----------Comparison Operators-----------*/

/**
 * Checks if the value of this Node's data is equal to that of right Node's data
 * @param right The node to compare to.
 * @return True if the two Node's data are equal, False otherwise.
 */
bool Node::operator==(const Node& right) const {
    return (getData() == right.getData());
}

/**
 * Checks if the value of this Node's data is less than that of another
 ** Node's.
 * @param right The node to compare to.
 * @return  True if this Node's data is less than that of the right
 ** Node's, False otherwise
 */
bool Node::operator<(const Node& right) const {
    return (getData() < right.getData());
}

/**
 * Checks if the value of this Node's data is greater than that of
 ** another Node's.
 * @param right The node to compare to.
 * @return  True if this Node's data is greater than that of the right
 ** Node's, False otherwise
 */
bool Node::operator>(const Node& right) const {
    return (getData() > right.getData());
}

/**
 * Sets the data in this Node to the same values of the data of another
 ** Node.
 * @param right The node to copy the data from.
 * @return This node.
 */
Node& Node::operator=(const Node& right) {
    data = right.getData();
}


/**
 * The empty constructor, initializes the node with empty data values
 * and NULL child pointers
 */
Node::Node() {
    data = new NodeData();
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    leftPtrIsThread = false;
    rightPtrIsThread = false;
}

/**
 * A full constructor, which accepts the full array of data that the node
 * can hold, which are subsequently stored in the node.
 * @param data          The NodeData to store in the node.
 * @param left          A pointer to this node's left child (may be NULL)
 * @param right         A pointer to this node's right child (may be NULL)
 */
Node::Node(NodeData* newNodeData, Node* left, Node* right, bool leftIsThread,
        bool rightIsThread) {
    data = newNodeData;
    leftChildPtr = left;
    rightChildPtr = right;
    leftPtrIsThread = leftIsThread;
    rightPtrIsThread = rightIsThread;

}

/**
 * Copy constructor. Copies the data over, leaving the pointers NULL.
 * @param nodeToCopy
 */
Node::Node(const Node& nodeToCopy) {
    data = nodeToCopy.getData();
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    leftPtrIsThread = false;
    rightPtrIsThread = false;
}

/**
 * @return The data stored in this node.
 */
NodeData* Node::getData() const {
    return data;
}

/**
 * Sets the data stored in this node.
 * @param data  The data to store in this node
 * @return True if successful.
 */
bool Node::setData(const NodeData& newData) {
    data = new NodeData(newData);
    return true;
}

/**
 * Checks if the left pointer is a "thread", ie. points to a node
 * that is not a child of this node.
 * @return True if the left pointer is a thread, false otherwise
 */
bool Node::isLeftPtrThread() {
    if (leftPtrIsThread) {
        return true;
    }
}

/**
 * Checks if the right pointer is a "thread", ie. points to a node
 * that is not a child of this node.
 * @return True if the right pointer is a thread, false otherwise
 */
bool Node::isRightPtrThread() {
    if (rightPtrIsThread) {
        return true;
    }
}

/**
 * Sets whether or not the left child is a "thread"
 * @param newvalue The new value
 */
void Node::setLefttPtrIsThread(bool newValue) {
    leftPtrIsThread = newValue;
}

/**
 * Sets whether or not the right child is a "thread"
 * @param newvalue The new value
 */
void Node::setRightPtrIsThread(bool newValue) {
    rightPtrIsThread = newValue;
}

Node* Node::getLeftChildPtr() {
    return leftChildPtr;
}

Node* Node::getRightChildPtr() {
    return rightChildPtr;
}

void Node::setLeftPtr(Node* newRightNode) {
    leftChildPtr = newRightNode;
}

void Node::setRightPtr(Node* newRightNode) {
    rightChildPtr = newRightNode;
}
#endif /* NODE */
