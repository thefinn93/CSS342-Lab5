#ifndef THREADEDBST_H
#define	THREADEDBST_H

#include "nodeData.h"

/// A threaded binary search tree
class ThreadedBST {
public:

    /**
     * A standard constructor, initializes an empty TBST.
     */
    ThreadedBST();

    /**
     * A constructor that initializes the TBST from a specified root node
     * @param rootNode  The node to use as the root when initalizing the tree.
     */
    ThreadedBST(const NodeData& rootNode);

    /**
     * Initializes a TBST. At this point we have not determined the purpose of
     * this constructor, but it was in the book and we suspect it may come in
     * hand later
     * @param rootNode
     * @param leftTreePtr
     * @param rightTreePtr
     */
    ThreadedBST(const NodeData& rootNode,
                const ThreadedBST* leftTreePtr,
                const ThreadedBST* rightTreePtr);

    /**
     * Creates a deep copy of another TBST.
     * @param treeToCopy    The TBST to copy
     */
    ThreadedBST(const ThreadedBST& treeToCopy);

    /**
     * A destructor. Deletes all the nodes in this tree.
     */
    ~ThreadedBST();

    //-------Public Methods-------//
    /**
     * @returns True if the three is empty, False otherwise.
     */
    bool isEmpty();

    /**
     * Inserts a token into the tree, and optionaly frequency for that token
     * @param token The token to insert.
     * @param frequency (optional) The frequency of this token. Assumed 1 if
     ** not specified
     * @return True if successful, false otherwise
     */
    bool insert(char[] token, int frequency);

    /**
     * Inserts a token if it is not already there, otherwise incriments the
     ** frequency count for that token.
     * @param token The token to insert or incriment
     * @return True if successful, false otherwise
     */
    bool insertOrIncriment(char[] token);

    /**
     * Sets the frequency of the specified token, or incriments it if no value
     * is specified
     * @param token     The token to set the frequency for.
     * @param frequency (optional) The new frequency for the token. Incriments
     ** the value by 1 if not specified
     * @return True if successful, false otherwise
     */
    bool setFrequency(char[] token, int frequency);

    /**
     * Removes a node from the tree by token.
     * @param token The token to remove
     * @return True if successful, false otherwise
     */
    bool remove(char[] token);

    /**
     * Retrieves the frequency of a given token
     * @param token The token to search for
     * @return The frequency count of the specified token, or 0 if the token
     ** is not in this tree
     */
    int getFrequency(char[] token);


    /**
     * Checks if the specified token is in this tree
     * @param token The token to search for
     * @return True if the token is in this tree, false otherwise
     */
    bool exists(char[] token);

    /**
     * Returns the total number of tokens stored in this tree
     * @return The number of nodes in this tree.
     */
    int getSize();


    /**
     * Preforms an in-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param visit(nodeData&)  The function to execute on the node.
     */
    void inorder(void visit(nodeData&));

    /**
     * Preforms a pre-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param visit(nodeData&)  The function to execute on the node.
     */
    void preorder(void visit(nodeData&));

    /**
     * Preforms a post-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param visit(nodeData&)  The function to execute on the node.
     */
    void postorder(void visit(nodeData&));


private:
    /// The root node
    ThreadedBST* rootPtr;
};

#endif

