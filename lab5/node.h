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
         * Checks if the value of this Node's data is equal to tha of another
         ** Node's
         * @param right The node to compare to
         * @return True if the two Node's data are equal, False otherwise.
         */
        Node& operator==(const Node& right) const;

        /**
         * Checks if the value of this Node's data is less than that of another
         ** Node's.
         * @param right The node to compare to.
         * @return  True if this Node's data is less than that of the right
         ** Node's, False otherwise
         */
        Node& operator<(const Node& right) const;

        /**
         * Checks if the value of this Node's data is greater than that of
         ** another Node's.
         * @param right The node to compare to.
         * @return  True if this Node's data is greater than that of the right
         ** Node's, False otherwise
         */
        Node& operator>(const Node& right) const;

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
         * A full constructor, which accepts the full array of data that the node
         * can hold, which are subsequently stored in the node.
         * @param data          The NodeData to store in the node.
         * @param left          A pointer to this node's left child (may be NULL)
         * @param right         A pointer to this node's right child (may be NULL)
         */
        Node(NodeData data, Node* left, Node* right);

        /**
         * Copy constructor. Copies the data over, leaving the pointers NULL.
         * @param nodeToCopy
         */
        Node(const NodeData& nodeToCopy);

        /**
         * Retreives the data element stored in this Node.
         * @return The data stored in this node.
         */
        NodeData getData();

        /**
         * Sets the data stored in this node.
         * @param data  The data to store in this node
         * @return True if successful.
         */
        bool setData(NodeData data);

    private:

        /// The information to store in this node
        NodeData data;

        /// A pointer to this node's left child
        NodeData* leftChildPtr;

        /// A pointer to this node's right child
        NodeData* rightChildPtr;

};

#include "node.cpp"
#endif /* NODEDATA_H */