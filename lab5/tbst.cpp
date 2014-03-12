/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 * 
 */

#ifndef THREADEDBST_CPP
#define	THREADEDBST_CPP

#include "tbst.h"
#include "node.h"
#include "nodeData.h"

using namespace std;

/// A threaded binary search tree

/*---------CONTSTRUCTORS----------*/

/**
 * A standard constructor, initializes an empty TBST.
 */
ThreadedBST::ThreadedBST() {
    rootPtr = NULL;
}

/**
 * A constructor that initializes the TBST from a specified root node
 * @param rootNode  The node to use as the root when initializing the tree.
 */
ThreadedBST::ThreadedBST(const Node& rootNode) {
    rootPtr = rootNode;
}

///TODO - DELETE?
/**
 * Initializes a TBST. At this point we have not determined the purpose of
 * this constructor, but it was in the book and we suspect it may come in
 * hand later
 * @param rootNode
 * @param leftTreePtr
 * @param rightTreePtr
 */
ThreadedBST::ThreadedBST(const Node& rootNode,
        const ThreadedBST* leftTreePtr,
        const ThreadedBST* rightTreePtr) {
    /// Why would we use this?
}

/**
 * Creates a deep copy of another TBST.
 * @param treeToCopy    The TBST to copy
 */
ThreadedBST::ThreadedBST(const ThreadedBST& treeToCopy) {
    rootPtr = copyTree(treeToCopy.rootPtr);
}

/**
 * A destructor. Deletes all the nodes in this tree.
 */
ThreadedBST::~ThreadedBST() {
    destroyTree(rootPtr);
}

/*-------PUBLIC METHODS-------*/

/*isEmpty*/

/**
 * Checks to see if the tree is empty.
 * @returns True if the three is empty, False otherwise.
 */
bool ThreadedBST::isEmpty() {
    return rootPtr == NULL;
}

/*getHeight*/

/**
 * Returns the height of the tree.
 * @return int The height of the tree.
 */
int ThreadedBST::getHeight() const {
    return getHeightHelper(rootPtr);
}

/*getNumberofNodes*/

/**
 * Returns the total number of tokens stored in this tree
 * @return The number of nodes in this tree.
 */
int ThreadedBST::getNumberOfNodes() const {

}

/*insert*/

/**
 * Inserts a token into the tree, or increments the token frequency if the token already exists in the node.
 * @param token The token to insert.
 * @return True if successful, false otherwise
 */
bool ThreadedBST::insert(string token) {
    if (threadedIsTokenInTree(token)) {
        return threadedIncrementHelper(token);
    }
    else {
        Node* newNode = new Node(token);
        rootPtr = balancedInsertHelper(rootPtr, newNode);        
    }
    return true;
}

/**
 * Sets the frequency of the specified token, or increments it if no value is specified.
 * @param token     The token to set the frequency for.
 * @param frequency (optional) The new frequency for the token. Increments
 * the value by 1 if not specified
 * @return True if successful, false otherwise
 */
bool ThreadedBST::setFrequency(string token, int frequency = 1) {
    Node* current = rootPtr;
    if (findInTree(token, current)) {
        return current->setFrequency(frequency);
    } else { // Token is not in tree
        return false;
    }
}

/**
 * Removes a node from the tree by token.
 * @param token The token to remove
 * @return True if successful, false otherwise
 */
bool ThreadedBST::remove(string token) {
    Node* removed = removeHelper(token, rootPtr);
    if (removed != NULL) { // Token was found and removed
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
int ThreadedBST::getFrequency(string token) {
}

void ThreadedBST::iterativeInorder(void visit(NodeData*)) {
    Node* current = rootPtr;
    // Once we've visited every node, this will be set to true
    bool done = false;

    // Some times (ie. after following a thread) we need to go right
    // instead of left. This keeps track of that for us.
    bool goright = false;

    bool hasSeenAtLeastOne = false;
    while (done) {
        /**
         * A couple of times we may need to go right. These are also the
         * times that we need to visit it.
         */
        if (goright || current->isRightPtrThread() ||
                current->getLeftChildPtr() == NULL) {
            (*visit)(current&);
            /// If this is a right leaf, the next node needs to be visited
            goright = current->isRightPtrThread();
            current = current->getRightChildPtr();
        } else { /// Otherwise go left
            current = current->getLeftChildPtr();
        }
        if (current == rootPtr && hasSeenAtLeastOne) {
            done = true;
        } else {
            hasSeenAtLeastOne = true;
        }
    }
}

/**
 * Preforms a pre-order traversal of the tree, executing the passed method
 *  on each node as it is visited. This method is recursive
 * @param (*visit)(nodeData&)  The function to execute on the node.
 * @param treePtr           The root of the tree to traverse
 */
void ThreadedBST::preorder(void visit(NodeData*), Node* treePtr) const {
    if (treePtr != NULL) {
        Node* theNode = treePtr->getData();
        (*visit)(theNode);
        preorder(visit, treePtr->getLeftChildPtr());
        preorder(visit, treePtr->getRightChildPtr());
    }
}

///TODO - Recursive inorder

/**
 * Preforms a post-order traversal of the tree, executing the passed method
 *  on each node as it is visited.
 * @param (*visit)(nodeData&)  The function to execute on the node.
 * @param treePtr           The root of the tree to traverse
 */
void ThreadedBST::postorder(void visit(NodeData*), Node* treePtr) const {
    if (treePtr != NULL) {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
        NodeData* theData = treePtr->getData();
        (*visit)(theData);
    }
}


/*---------PROTECTED METHODS----------*/

/*HELPTER FUNCTIONS*/

/*copyTree*/

/**
 * 
 */
Node* ThreadedBST::copyTree(const Node* treeRootPrt) const {
    Node* newRootPtr = NULL;
    if (treeRootPrt != NULL) {

        ///the top root ptr is a new node with the copied data
        newRootPtr = new Node(treeRootPrt->getData(), NULL, NULL);

        ///Recursively call the copy tree for each child ptr
        newRootPtr.setLeftPtr(copyTree(treeRootPrt->getLeftChildPtr()));
        newRootPtr.setRightPtr(copyTree(treeRootPrt->getRightChildPtr()));
    }

    //
    return newRootPtr;
}


/*destroyTree*/

///TODO - Make sure it doesn't break for threaded.

/**
 * 
 */
void ThreadedBST::destroyTree(const Node* treeRootPtr) {
    if (treeRootPtr != NULL) {

        /// Recursively destroy each sub tree
        destroyTree(treeRootPtr->getLeftChildPtr());
        destroyTree(treeRootPtr->getRightChildPtr());

        /// Delete the root node
        delete treeRootPtr;
    }
}

/*getHeightHelper*/

/**
 * A helper function to determine the height of a binary tree. Based
 * heavily on Frank Carrano's sample code.
 * @param subTreePtr A pointer to the root of the tree to measure
 * @return The height of the specified tree
 */
int ThreadedBST::getHeightHelper(Node* subTreePtr) const {
    if (subTreePtr == NULL) {
        return 0; //Height of zero
    } else {
        ///TODO - Max is a function in STD
        return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                getHeightHelper(subTreePtr->getRightChildPtr()));
    }
}



/*balancedInsertHelper*/

/**
 * A private function to insert a new node into the tree. Based heavily on Frank Carrano's sample code
 * @param subTreePtr    A pointer to the root of the tree the insert is being preformed on.
 * @param newNodePtr    A pointer to the new node that's being inserted.
 * @return The root pointer.
 */
Node* ThreadedBST::balancedInsertHelper(Node* subTreePtr, Node* leftTail,
        Node* rightTail, Node* newNodePtr) {
    if (subTreePtr == NULL) {
        newNodePtr->setLeftPtr(leftTail);
        newNodePtr->setLeftPtrIsThread(true);
        newNodePtr->setRightPtr(rightTail);
        newNodePtr->setRightPtrIsThread(true);
        return newNodePtr;
    } else {
        Node* leftPtr = subTreePtr->getLeftChildPtr();
        Node* rightPtr = subTreePtr->getRightChildPtr();
        if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)) {
            // Go right, set the left tail to the current node.
            rightPtr = balancedInsertHelper(rightPtr, subTreePtr, rightTail,
                    newNodePtr);
            subTreePtr->setRightPtr(rightPtr);
            subTreePtr->setRightPtrIsThread(false);
        } else {
            // Go left, set the right tail to the current node.
            leftPtr = balancedInsertHelper(leftPtr, leftTail, subTreePtr,
                    newNodePtr);
            subTreePtr->setLeftPtr(leftPtr);
            subTreePtr->setLeftPtrIsThread(false);
        }
        return subTreePtr;
    }
}
/*removeHelper*/

/**
 * Finds and removes a node from the tree by token. Returns NULL if no
 * nodes have that token, otherwise returns a pointer to the removed node.
 * @param token     The token to search for
 * @param root      The root node in the tree
 * @return          The pointer to the removed node, or NULL if it was not
 * found.
 */
Node* ThreadedBST::removeHelper(string token, Node* root) {
    if (root != NULL) {
        Node* current = root;
        Node* parent = NULL;

        /// Used in findInTree to report whether the current was taken from
        /// the parent's left or right child. It is of course passed by
        /// reference
        bool isLeft = false;
        if (findInTree(token, current, parent, isLeft)) {
            if (current->rightLeafIsThread() && current->leftLeafIsThread()) {
                /// We're a leaf node, no children to worry about!
                if (isLeft) {
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

                if (current->leftChild != NULL) {
                    replacement->leftChild = current->leftChild;
                    replacement->leftPtrIsThread(current->isLeftPtrThread());
                }

                if (current->rightChild != NULL) {
                    replacement->rightChild = current->rightChild;
                    replacement->rightPtrIsThread(current->isRightPtrThread());
                }

                if (isLeft) {
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
}

#endif

