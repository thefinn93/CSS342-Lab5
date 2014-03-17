/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 */

#ifndef NODE_H
#define	NODE_H

#include "nodeData.h"

/**
 * A node in a ThreadedBST
 */
class Node {
public:

    /*-----------Comparison Operators-----------*/
    /**
     * Checks if the value of this Node's data is equal to that of right Node's
     * data
     * @param right The node to compare to.
     * @return True if the two Node's data are equal, False otherwise.
     */
    bool operator==(const Node& right) const;

    /**
     * Checks if the value of this Node's data is less than that of another
     ** Node's.
     * @param right The node to compare to.
     * @return  True if this Node's data is less than that of the right
     ** Node's, False otherwise
     */
    bool operator<(const Node& right) const;

    /**
     * Checks if the value of this Node's data is greater than that of
     ** another Node's.
     * @param right The node to compare to.
     * @return  True if this Node's data is greater than that of the right
     ** Node's, False otherwise
     */
    bool operator>(const Node& right) const;

    /**
     * Sets the data in this Node to the same values of the data of another
     ** Node.
     * @param right The node to copy the data from.
     * @return This node.
     */
    Node& operator=(const Node& right);

    /**
     * The empty constructor, initializes the node with empty data values
     * and NULL child pointers
     */
    Node();

    /**
     * A constructor that takes only a string
     * @param newToken
     */
    Node(string newToken);

    /**
     * An empty constructor
     * @param newToken
     * @param newFrequency
     */
    Node(string newToken, int newFrequency);

    /**
     * A full constructor, which accepts the full array of data that the node
     * can hold, which are subsequently stored in the node.
     * @param data          The NodeData to store in the node.
     * @param left          A pointer to this node's left child (may be NULL)
     * @param right         A pointer to this node's right child (may be NULL)
     * @param leftIsThread  True if node pointer is a thread.
     * @param rightIsThread True if node pointer is a thread.
     */
    Node(NodeData newNodeData, Node* left, Node* right, bool leftIsThread,
            bool rightIsThread);

    /**
     * Copy constructor. Copies the data over, leaving the pointers NULL.
     * @param nodeToCopy
     */
    Node(const Node& nodeToCopy);

    /**
     * Retrieves the data element stored in this Node.
     * @return The data stored in this node.
     */
    NodeData getData() const;

    /**
     * @return A pointer to this node's data.
     */
    NodeData* getDataReference();

    /**
     * Sets the data stored in this node.
     * @param data  The data to store in this node
     * @return True if successful.
     */
    bool setData(const NodeData& newData);

    /**
     * Checks if the left pointer is a "thread", ie. points to a node
     * that is not a child of this node.
     * @return True if the left pointer is a thread, false otherwise
     */
    bool isLeftPtrThread();

    /**
     * Checks if the right pointer is a "thread", ie. points to a node
     * that is not a child of this node.
     * @return True if the right pointer is a thread, false otherwise
     */
    bool isRightPtrThread();

    /**
     * Sets whether or not the left child is a "thread"
     * @param newValue The new value
     */
    void setLeftPtrIsThread(bool newValue);

    /**
     * Sets whether or not the right child is a "thread"
     * @param newValue The new value
     */
    void setRightPtrIsThread(bool newValue);

    Node* getLeftChildPtr() const;
    Node* getRightChildPtr() const;
    void setLeftPtr(Node* newRightNode);
    void setRightPtr(Node* newRightNode);

private:

    /// The information to store in this node
    NodeData data;

    /// A pointer to this node's left child
    Node* leftChildPtr;

    /// A pointer to this node's right child
    Node* rightChildPtr;

    /// Whether nor not the left pointer is a thread
    bool leftPtrIsThread;

    /// Whether or not the right pointer is a thread
    bool rightPtrIsThread;

};

//#include "node.cpp"
#endif /* NODEDATA_H */
