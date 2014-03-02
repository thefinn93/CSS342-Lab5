#ifndef THREADEDBST
#define	THREADEDBST

#include "tbst.h"

/// A threaded binary search tree
class ThreadedBST {
    /**
     * A standard constructor, initializes an empty TBST.
     */
    ThreadedBST() {
    }

    /**
     * A constructor that initializes the TBST from a specified root node
     * @param rootNode  The node to use as the root when initalizing the tree.
     */
    ThreadedBST(const NodeData& rootNode) {
    }

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
                const ThreadedBST* rightTreePtr) {
        /// Why would we use this?
    }

    /**
     * Creates a deep copy of another TBST.
     * @param treeToCopy    The TBST to copy
     */
    ThreadedBST(const ThreadedBST& treeToCopy) {
    }

    /**
     * A destructor. Deletes all the nodes in this tree.
     */
    ~ThreadedBST() {
    }

    /**
     * @returns True if the three is empty, False otherwise.
     */
    bool isEmpty() {
    }

    /**
     * Inserts a token into the tree, and optionaly frequency for that token
     * @param token The token to insert.
     * @param frequency (optional) The frequency of this token. Assumed 1 if
     ** not specified
     * @return True if successful, false otherwise
     */
    bool insert(char[] token, int frequency) {
    }

    /**
     * Inserts a token if it is not already there, otherwise incriments the
     ** frequency count for that token.
     * @param token The token to insert or incriment
     * @return True if successful, false otherwise
     */
    bool insertOrIncriment(char[] token) {
    }

    /**
     * Sets the frequency of the specified token, or incriments it if no value
     * is specified
     * @param token     The token to set the frequency for.
     * @param frequency (optional) The new frequency for the token. Incriments
     ** the value by 1 if not specified
     * @return True if successful, false otherwise
     */
    bool setFrequency(char[] token, int frequency) {
    }

    /**
     * Removes a node from the tree by token.
     * @param token The token to remove
     * @return True if successful, false otherwise
     */
    bool remove(char[] token) {
    }

    /**
     * Retrieves the frequency of a given token
     * @param token The token to search for
     * @return The frequency count of the specified token, or 0 if the token
     ** is not in this tree
     */
    int getFrequency(char[] token) {
    }


    /**
     * Checks if the specified token is in this tree
     * @param token The token to search for
     * @return True if the token is in this tree, false otherwise
     */
    bool exists(char[] token) {
    }

    /**
     * Returns the total number of tokens stored in this tree
     * @return The number of nodes in this tree.
     */
    int getSize() {
        return 0;
    }

    void inorder(void visit(nodeData&)) {
        Node* current = rootPtr;
        // Once we've visited every node, this will be set to true
        bool done = false;

        // Some times (ie. after following a thread) we need to go right
        // instead of left. This keeps track of that for us.
        bool goright = false;

        bool hasSeenAtLeastOne = false;
        while(done) {
            /**
             * A couple of times we may need to go right. These are also the
             * times that we need to visit it.
             */
            if(goright || current->isRightPtrThread() || current->leftChild == NULL) {
                visit(current&);
                /// If this is a right leaf, the next node needs to be visited
                goright = current->isRightPtrThread();
                current = current->rightChild;
            } else { /// Otherwise go left
                current = current->leftChild;
            }
            if(currnet == rootPtr && hasSeenAtLeastOne) {
                done = true;
            } else {
                hasSeenAtLeastOne = true;
            }
        }
    }


    /**
     * Preforms a pre-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param visit(nodeData&)  The function to execute on the node.
     */
    void preorder(void visit(nodeData&)) {
        Node* current = rootPtr;
        // Once we've visited every node, this will be set to true
        bool done = false;

        // Some times (ie. after following a thread) we need to go right
        // instead of left. This keeps track of that for us.
        bool goright = false;

        bool hasSeenAtLeastOne = false;
        while(done) {
            /**
             * A couple of times we may need to go right. These are also the
             * times that we need to visit it.
             */
            if(goright || current->isRightPtrThread() || current->leftChild == NULL) {
                if(current->isLeftPtrThread()) {
                    visit(current&);
                }
                goright = current->isRightPtrThread();
                current = current->rightChild;
            } else { /// Otherwise go left
                visit(current&);
                current = current->leftChild;
            }
            if(currnet == rootPtr && hasSeenAtLeastOne) {
                done = true;
            } else {
                hasSeenAtLeastOne = true;
            }
        }

    }

    /**
     * Preforms a post-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param visit(nodeData&)  The function to execute on the node.
     */
    void postorder(void visit(nodeData&)) {
        throw 2; /// exception #2: not yet implimented.
    }

};

#endif

