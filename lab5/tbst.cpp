/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 * 
 */

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
        return rootPtr == NULL;
    }


    /**
     * A helper function to determine the height of a binary tree. Based
     * heavily on Frank Carrano's sample code.
     * @param subTreePtr A pointer to the root of the tree to measure
     * @return The height of the specified tree
     */
    int getHeightHelper(Node* subTreePtr) const {
        if (subTreePtr == nullptr) {
            return 0;
        } else {
            return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                     getHeightHelper(subTreePtr->getRightChildPtr()));
        }
    }

    /**
     * A private function to insert a new node into the tree. Based heavily on
     * Frank Carrano's sample code
     * @param subTreePtr    A pointer to the root of the tree the insert is
     * being preformed on.
     * @param newNodePtr    A pointer to the new node that's being inserted.
     * @return The root pointer.
     */
    Node* balancedAdd(Node* subTreePtr, Node* leftTail, Node* rightTail,
            Node* newNodePtr) {
        if (subTreePtr == NULL) {
            newNodePtr->setLeftChildPtr(leftTail);
            newNodePtr->setLeftPtrIsthread(true);

            newNodePtr->setRightChildPtr(rightTail);
            newNodePtr->setRightPtrIsThread(true);
            return newNodePtr;
        } else {
            Node* leftPtr = subTreePtr->getLeftChildPtr();
            Node* rightPtr = subTreePtr->getRightChildPtr();
            if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
                // Go right, set the left tail to the current node.
                rightPtr = balancedAdd(rightPtr, subTreePtr, rightTail,
                        newNodePtr);
                subTreePtr->setRightChildPtr(rightPtr);
                subTreePtr->setRightPtrIsThread(false);
            } else {
                // Go left, set the right tail to the current node.
                leftPtr = balancedAdd(leftPtr, leftTail, subTreePtr,
                        newNodePtr);
                subTreePtr->setLeftChildPtr(leftPtr);
                subTreePtr->setLeftPtrIsThread(false);
            }
            return subTreePtr;
        }
    }

    /**
     * Inserts a token into the tree, and optionaly frequency for that token
     * @param token The token to insert.
     * @param frequency (optional) The frequency of this token. Assumed 1 if
     * not specified
     * @return True if successful, false otherwise
     */
    bool insert(char[] token, int frequency) {
        Node* newNode = new Node(token, frequency);
        rootPtr = balancedAdd(rootPtr, newNode);
        return true;
    }


    /**
     * Inserts a token if it is not already there, otherwise incriments the
     * frequency count for that token.
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
     * the value by 1 if not specified
     * @return True if successful, false otherwise
     */
    bool setFrequency(char[] token, int frequency = 1) {
        current = root;
        if(findInTree(token, current)) {
            return current->setFrequency(frequency);
        } else { // Token is not in tree
            return false;
        }
    }


    /**
     * Finds and removes a node from the tree by token. Returns NULL if no
     * nodes have that token, otherwise returns a pointer to the removed node.
     * @param token     The token to search for
     * @param root      The root node in the tree
     * @return          The pointer to the removed node, or NULL if it was not
     * found.
     */
    Node* removeHelper(char[] token, Node* root) {
        if(root != NULL) {
            Node* current = root;
            Node* parent = NULL;

            /// Used in findInTree to report whether the current was taken from
            /// the parent's left or right child. It is of course passed by
            /// reference
            bool isLeft = false;
            if(findInTree(token, current, parent, isLeft)) {
                if(current->rightLeafIsThread() && current->leftLeafIsThread()) {
                    /// We're a leaf node, no children to worry about!
                    if(isLeft) {
                        parent->leftChild = NULL;
                    } else {
                        parent->rightChild = NULL;
                    }
                    /// Fixes the threads on the parent that now has a NULL
                    /// child. Knowledge of current's threads will help.
                    fixThreads(parent, current);
                    return current;
                } else {
                    // Finds the largest leaf given the root of a tree and removes
                    // it
                    replacementToken = findLargestTokenInTree(current);
                    replacement = remove(replacementToken);

                    if(current->leftChild != NULL) {
                        replacement->leftChild = current->leftChild;
                        replacement->leftPtrIsThread(current->isLeftPtrThread());
                    }

                    if(current->rightChild != NULL) {
                        replacement->rightChild = current->rightChild;
                        replacement->rightPtrIsThread(current->isRightPtrThread());
                    }

                    if(isLeft) {
                        parent->leftChild = replacement;
                    } else {
                        parent->rightChild = replacement;
                    }
                    return current;
                }
            } else { // token is not in this tree
                return NULL;
            }

        } else { // Tree is empty, nothing to remove
            return NULL;
        }

    /**
     * Removes a node from the tree by token.
     * @param token The token to remove
     * @return True if successful, false otherwise
     */
    bool remove(char[] token) {
        Node* removed = removeHelper(token, rootPtr);
        if(removed != NULL) { // Token was found and removed
            delete removed;
            return true;
        } else { // Token not found
            return false;
        }
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

    void iterativeInorder(void visit(NodeData&)) {
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
            if(current == rootPtr && hasSeenAtLeastOne) {
                done = true;
            } else {
                hasSeenAtLeastOne = true;
            }
        }
    }


    /**
     * Preforms a pre-order traversal of the tree, executing the passed method
     *  on each node as it is visited. This method is recursive
     * @param visit(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void preorder(void visit(NodeData&), Node* treePtr) const {
        if (treePtr != nullptr) {
            ItemType theItem = treePtr->getItem();
            visit(theItem);
            preorder(visit, treePtr->getLeftChildPtr());
            preorder(visit, treePtr->getRightChildPtr());
        }
    }

    /**
     * Preforms a post-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param visit(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void postorder(void visit(NodeData&), Node* treePtr) const {
        if (treePtr != nullptr) {
            postorder(visit, treePtr->getLeftChildPtr());
            postorder(visit, treePtr->getRightChildPtr());
            ItemType theItem = treePtr->getItem();
            visit(theItem);
        }
    }
#endif

