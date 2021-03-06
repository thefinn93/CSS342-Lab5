/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 *
 */

#ifndef THREADEDBST_CPP
#define	THREADEDBST_CPP

#include "tbst.h"

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
ThreadedBST::ThreadedBST(Node* rootNode) {
    rootPtr = rootNode;
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
bool ThreadedBST::isEmpty() const {
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
int ThreadedBST::getNumberOfNodes() {
    int nodeCount = 0;
    if (isEmpty()) {
        return nodeCount;
    } else {

    }
}

/*insert*/

/**
 * Inserts a token into the tree, or increments the token frequency if the
 * token already exists in the node.
 * @param token The token to insert.
 * @return True if successful, false otherwise
 */
bool ThreadedBST::insert(string token) {

    if (this->isTokenInTree(token)) {
        ///iterates the frequency by 1
        nodeWithToken(rootPtr, token)->getDataReference()->
                increaseFrequency(1);

    } else {
        Node* newNode = new Node(token);
        rootPtr = balancedInsertHelper(rootPtr, NULL, NULL, newNode, 0);
    }
    return true;
}

/*isTokenInTree*/

/**
 * Checks if a token is in a tree
 * @param Looks for this string token
 * @return True if token is in string, false otherwise
 */
bool ThreadedBST::isTokenInTree(string searchForThisToken) {
    if (this->isEmpty()) {
        return false;
    } else {
        return isTokenInTreeHelper(rootPtr, searchForThisToken);
    }
}

/*remove*/

/**
 * Removes a node from the tree by token.
 * @param token The token to remove
 * @return True if successful, false otherwise
 */
bool ThreadedBST::remove(string token) {
    if (isTokenInTree(token)) {
        Node* removed = removeHelper(token, rootPtr);
        delete removed;
        return true;
    } else {
        return false; /// No matching node to remove
    }

}

/*getFrequencyOfToken*/

/**
 * Retrieves the frequency of a given token
 * @param token The token to search for
 * @return The frequency count of the specified token, or 0 if the token
 ** is not in this tree
 */
int ThreadedBST::getFrequencyOfToken(string token) {
    if (isTokenInTree(token)) {
        return nodeWithToken(rootPtr, token)->getData().getFrequency();
    } else {
        return 0; /// NOT MAGIC, IS THE NUMBER 0
    }
}

/*iterativeInOrder*/

/**
 * Preforms an in-order traversal of the tree,
 * executing the passed method
 *  on each node as it is visited. This version uses an iterative algorithm
 * @param (*visit)(nodeData&)  The function to execute on the node.
 */
void ThreadedBST::iterativeInorder(void (&visit)(NodeData)) {
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
            visit(current->getData());
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

/*inorder*/

/**
 * Preforms an in-order traversal of the tree,
 * executing the passed method on each node as it is visited.
 * @param visit(nodeData&)  The function to execute on the node.
 * @param treePtr           The root of the tree to traverse
 */
//void ThreadedBST::inorder(void (visit)(NodeData*), Node* treePtr) {
//    if (treePtr != NULL) {
//        Node* theNode = treePtr;
//        preorder(visit, treePtr->getLeftChildPtr());
//        visit(theNode->getDataReference());
//        preorder(visit, treePtr->getRightChildPtr());
//    }
//}

/**
 * Preforms a pre-order traversal of the tree, executing the passed method
 *  on each node as it is visited. This method is recursive
 * @param (*visit)(nodeData&)  The function to execute on the node.
 * @param treePtr           The root of the tree to traverse
 */
void ThreadedBST::preorder(void (&visit)(NodeData)) const {
    preorderHelper(visit, rootPtr);
}

void ThreadedBST::preorderHelper(void (&visit)(NodeData), Node* treePtr) const {
    if (treePtr != NULL) {
        visit(treePtr->getData());
        preorderHelper(visit, treePtr->getLeftChildPtr());
        preorderHelper(visit, treePtr->getRightChildPtr());
    }
}



void ThreadedBST::inorder(void (&visit)(NodeData), Node* treePtr) {
    if (treePtr != NULL) {
        Node* theNode = treePtr;
        inorder(visit, treePtr->getLeftChildPtr());
        visit(theNode->getData());
        inorder(visit, treePtr->getRightChildPtr());
    }
}


/**
 * Preforms a post-order traversal of the tree, executing the passed method
 *  on each node as it is visited.
 * @param (*visit)(nodeData&)  The function to execute on the node.
 * @param treePtr           The root of the tree to traverse
 */
void ThreadedBST::postorder(void (&visit)(NodeData), Node* treePtr) {
    if (treePtr != NULL) {
        postorder(visit, treePtr->getLeftChildPtr());
        postorder(visit, treePtr->getRightChildPtr());
//        NodeData* theData = treePtr->getData();
        visit(treePtr->getData());
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
        newRootPtr = new Node(treeRootPrt->getData(), NULL, NULL, true, true);

        ///Recursively call the copy tree for each child ptr
        newRootPtr->setLeftPtr(copyTree(treeRootPrt->getLeftChildPtr()));
        newRootPtr->setRightPtr(copyTree(treeRootPrt->getRightChildPtr()));
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
 *  heavily on Frank Carrano's sample code.
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

/*isTokenInTreeHelper*/

bool ThreadedBST::isTokenInTreeHelper(Node* currentNode,
        string searchToken) {
    if (currentNode->getData().getToken() == searchToken) {
        return true;
    } else {
        if ((currentNode->getLeftChildPtr() != NULL) && !(currentNode->isLeftPtrThread())) {
            isTokenInTreeHelper(currentNode->getLeftChildPtr(), searchToken);
        }
        if ((currentNode->getRightChildPtr() != NULL) && !(currentNode->isRightPtrThread())) {
            isTokenInTreeHelper(currentNode->getRightChildPtr(), searchToken);
        }
        return false; /// searchToken is never found
    }
}

bool ThreadedBST::isNodeALeaf(Node* currentNode) {
    if ((currentNode->isLeftPtrThread() || NULL) &&
            (currentNode->isRightPtrThread() || NULL)) {
        return true;
    } else {
        return false;
    }
}

Node* ThreadedBST::nodeWithToken(Node* currentNode, string searchToken) {
    if (currentNode->getData().getToken() == searchToken) {
        return currentNode;
    } else {
        if (currentNode->getLeftChildPtr() != NULL && !currentNode->isLeftPtrThread()) {
            isTokenInTreeHelper(currentNode->getLeftChildPtr(), searchToken);
        }
        if (currentNode->getLeftChildPtr() != NULL && !currentNode->isRightPtrThread()) {
            isTokenInTreeHelper(currentNode->getRightChildPtr(), searchToken);
        }
        /// We already know the node is in the tree. No need to have an
        /// alternate return.
    }
}

/*balancedInsertHelper*/

/**
 * A private function to insert a new node into the tree. Based heavily on
 *  Frank Carrano's sample code
 * @param subTreePtr    A pointer to the root of the tree the insert is
 *  being preformed on.
 * @param newNodePtr    A pointer to the new node that's being inserted.
 * @return The root pointer.
 */
Node* ThreadedBST::balancedInsertHelper(Node* subTreePtr, Node* leftTail,
        Node* rightTail, Node* newNodePtr, int leftOrRight) {
    if (subTreePtr == NULL) {
        cout << "INSERTING: FOUND: newNodePtr, token: " << newNodePtr->getData().getToken() << endl;
        cout << "INSERTING: FOUND: Found Null subTreePtr, setting newNodePtr leftChildPtr to leftTail, is leftTail NULL: " << (leftTail == NULL) << endl;
        newNodePtr->setLeftPtr(leftTail);
        if (newNodePtr->getLeftChildPtr() == rootPtr) {
            cout << "INSERTING: FOUND: On newNodePtr, leftChildPtr looks like rootPtr" << endl;
            if (leftOrRight == 1) {
                cout << "INSERTING: FOUND: Came from the left" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, leftChildPtr is a Thread" << endl;
                newNodePtr->setLeftPtrIsThread(true);
            } else if (leftOrRight == -1) {
                cout << "INSERTING: FOUND: But, came from the right" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, leftChildPtr is a Non-Thread" << endl;
                newNodePtr->setLeftPtrIsThread(false);
            } else {
                cout << "INSERTING: FOUND: This is the rootPtr" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, leftChildPtr is a Non-Thread" << endl;
                newNodePtr->setLeftPtrIsThread(false);
            }
        } else {
            if (leftTail == NULL) {
                cout << "INSERTING: FOUND: LeftTail is NULL" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, leftChildPtr is Non-Thread" << endl;
                newNodePtr->setLeftPtrIsThread(false);
            } else {
                cout << "INSERTING: FOUND: LeftTail is not NULL" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, leftChildPtr is Thread" << endl;
                newNodePtr->setLeftPtrIsThread(true);
            }
            
        }
        cout << "INSERTING: FOUND: Found Null subTreePtr, setting newNodePtr rightChildPtr to rightTail, is NULL: " << (rightTail == NULL) << endl;
        newNodePtr->setRightPtr(rightTail);
        if (newNodePtr->getRightChildPtr() == rootPtr) {
            cout << "INSERTING: FOUND: On newNodePtr, rightChildPtr looks like rootPtr" << endl;
            if (leftOrRight == -1) {
                cout << "INSERTING: FOUND: Came from the right" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, rightChildPtr is a Thread" << endl;
                newNodePtr->setRightPtrIsThread(true);
            } else if (leftOrRight == 1) {
                cout << "INSERTING: FOUND: But, came from the left" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, rightChildPtr is a Non-Thread" << endl;   
                newNodePtr->setRightPtrIsThread(false);
            } else {
                cout << "INSERTING: FOUND: Is rootPtr" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, rightChildPtr is a Non-Thread" << endl; 
                newNodePtr->setRightPtrIsThread(false);
            }
        } else {
            if (rightTail == NULL) {
                cout << "INSERTING: FOUND: RightTail is NULL" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, rightChildPtr is Non-Thread" << endl;
                newNodePtr->setRightPtrIsThread(false);
            } else {
                cout << "INSERTING: FOUND: RightTail is not NULL" << endl;
                cout << "INSERTING: FOUND: On newNodePtr, rightChildPtr is Thread" << endl;
                newNodePtr->setRightPtrIsThread(true);
            }
        }
        cout << "INSERTING: FOUND: Done, returning newNodePtr, token: " << newNodePtr->getData().getToken() << endl;
        return newNodePtr;
    } else {
        cout << "INSERTING: LOOKING: Current Node not NULL, subTreePtr, token: " << subTreePtr->getData().getToken() << endl;
        cout << "INSERTING: LOOKING: Setting leftPtr to leftChildPtr, token: " << endl;
        Node* leftPtr = subTreePtr->getLeftChildPtr();
        cout << "INSERTING: LOOKING: Setting rightPtr to rightChildPtr, token: " << endl;
        Node* rightPtr = subTreePtr->getRightChildPtr();
        if (newNodePtr->getData() > subTreePtr->getData()) {
            cout << "INSERTING: LOOKING: newNode is greater than currentNode, go Right" << endl;
            
            // Go right, set the left tail to the current node.
            if (subTreePtr->isRightPtrThread()) {
                cout << "INSERTING: LOOKING: rightPtr = balancedInsertHelper(NULL, subTreePtr, rightTail, newNodePtr, 1)" << endl;
                rightPtr = balancedInsertHelper(NULL, subTreePtr, rightTail, newNodePtr, 1);
            } else {
                cout << "INSERTING: LOOKING: rightPtr = balancedInsertHelper(rightPtr, subTreePtr, rightTail, newNodePtr, 1)" << endl;
                rightPtr = balancedInsertHelper(rightPtr, subTreePtr, rightTail,
                        newNodePtr, 1);
            }
            cout << "INSERTING: LOOKING: rightPtr returned, current subTreePtr rightChildPtr is set to rightPtr" << endl;
            subTreePtr->setRightPtr(rightPtr);
            cout << "INSERTING: LOOKING: current subTreePtr rightChildPtr is a non-thread" << endl;
            subTreePtr->setRightPtrIsThread(false);
        } else {
            cout << "INSERTING: LOOKING: newNode is less than than currentNode, go left" << endl;
            
            // Go left, set the right tail to the current node.
            if (subTreePtr->isLeftPtrThread()) {
                cout << "INSERTING: LOOKING: leftPtr = balancedInsertHelper(NULL, leftTail, subTreePtr, newNodePtr, -1)" << endl;
                leftPtr = balancedInsertHelper(NULL, leftTail, subTreePtr, newNodePtr, -1);
            } else {
                cout << "INSERTING: LOOKING: leftPtr = balancedInsertHelper(leftPtr, leftTail, subTreePtr, newNodePtr, -1)" << endl;
                leftPtr = balancedInsertHelper(leftPtr, leftTail, subTreePtr,
                        newNodePtr, -1);
            }

            cout << "INSERTING: LOOKING: leftPtr returned, current subTreePtr leftChildPtr is set to leftPtr" << endl;
            subTreePtr->setLeftPtr(leftPtr);
            cout << "INSERTING: LOOKING: current subTreePtr leftChildPtr is a non-thread" << endl;
            subTreePtr->setLeftPtrIsThread(false);
        }
        return subTreePtr;
    }
}

/**
 * Sets the frequency of the specified token, or increments it if no value is
 * specified.
 * @param token     The token to set the frequency for.
 * @param frequency (optional) The new frequency for the token. Increments
 * the value by 1 if not specified
 * @return True if successful, false otherwise
 */
//bool ThreadedBST::setFrequency(string token, int frequency = 1) {
//    Node* current = rootPtr;
//
//    if (isTokenInTree(token)) {
//            return current->getDataReference()->setFrequency(1);
//        } else { // Token is not in tree
//
//        return false;
//    }
//}

/*removeHelper*/

/**
 * Finds and removes a node from the tree by token. Returns NULL if no
 * nodes have that token, otherwise returns a pointer to the removed node.
 * @param token     The token to search for
 * @param root      The root node in the tree
 * @return          The pointer to the removed node, or NULL if it was not
 * found.
 */
Node* ThreadedBST::removeHelper(string token, Node* treeRootPtr) {

    /// Used in isTokenInTree to report whether the current was taken from
    /// the parent's left or right child. It is of course passed by
    /// reference
    Node* nodeToRemove = nodeWithToken(treeRootPtr, token);
    Node* leftSideThreadPredecessor = NULL;

    if (isNodeALeaf(nodeToRemove)) {
        /// We're a leaf node, no children to worry about!
        /// unlink the node from the tree, relink the tree
        return removeLeafAndRelink(nodeToRemove);
    } else {
        leftSideThreadPredecessor =
                findLeftSidePredecessor(nodeToRemove, treeRootPtr);
    }
    //    if (!(leftThreadPredecessor->isLeftPtrThread())) {
    ///just in case the line below doesn't work
    if (!isNodeALeaf(leftSideThreadPredecessor)) {
        //        if (leftThreadPredecessor->getLeftChildPtr() != NULL) {
        ///just in case
        findLeftSidePredecessor(leftSideThreadPredecessor, treeRootPtr)->
                setLeftPtr(leftSideThreadPredecessor->getRightChildPtr());
        //        }
    }
    if (nodeToRemove->isLeftPtrThread()) {
        leftSideThreadPredecessor->setLeftPtrIsThread(true);
    }
    leftSideThreadPredecessor->setLeftPtr(nodeToRemove->getLeftChildPtr());
    if (nodeToRemove->isRightPtrThread()) {
        leftSideThreadPredecessor->setRightPtrIsThread(true);
    }
    leftSideThreadPredecessor->setRightPtr(nodeToRemove->getRightChildPtr());

    return nodeToRemove;

    //    if (current->isLeftPtrThread() && current->isLeftPtrThread()) {
    //
    //        if (isLeft) {
    //            parent->leftChild = NULL;
    //        } else {
    //            parent->rightChild = NULL;
    //        }
    //        /// Fixes the threads on the parent that now has a NULL
    //        /// child. Knowledge of current's threads will help.
    //        fixThreads(parent, current);
    //        return current;
    //    }
    //    else {
    //        // Finds the largest leaf given the root of a tree and removes it
    //        replacementToken = findLargestTokenInTree(current);
    //                replacement = remove(replacementToken);
    //
    //        if (current->leftChild != NULL) {
    //            replacement->leftChild = current->leftChild;
    //                    replacement->leftPtrIsThread(current->
    //isLeftPtrThread());
    //        }
    //
    //        if (current->rightChild != NULL) {
    //            replacement->rightChild = current->rightChild;
    //                    replacement->rightPtrIsThread(current->
    //isRightPtrThread());
    //        }
    //
    //        if (isLeft) {
    //            parent->leftChild = replacement;
    //        } else {
    //            parent->rightChild = replacement;
    //        }
    //        return current;
    //    }
}

Node* ThreadedBST::removeLeafAndRelink(Node* leafToRemove) {
    if (leafToRemove->isLeftPtrThread() && leafToRemove->
            isRightPtrThread()) {
        if (leafToRemove->getLeftChildPtr()->getRightChildPtr() ==
                leafToRemove) {
            leafToRemove->getLeftChildPtr()->setRightPtrIsThread(true);
            leafToRemove->getLeftChildPtr()->setRightPtr(leafToRemove->
                    getRightChildPtr());
            return leafToRemove;
        } else {
            leafToRemove->getRightChildPtr()->setLeftPtrIsThread(true);
            leafToRemove->getRightChildPtr()->setLeftPtr(leafToRemove->
                    getLeftChildPtr());
            return leafToRemove;
        }
    } else if (!leafToRemove->isLeftPtrThread() && leafToRemove->
            isRightPtrThread()) {
        leafToRemove->getRightChildPtr()->setLeftPtr(NULL);
        return leafToRemove;
    } else if (leafToRemove->isLeftPtrThread() && !leafToRemove->
            isRightPtrThread()) {
        leafToRemove->getLeftChildPtr()->setRightPtr(NULL);
        return leafToRemove;
    }
}

Node* ThreadedBST::findLeftSidePredecessor(Node* targetNodePtr,
        Node* subTreePtr) {
    if (subTreePtr->getLeftChildPtr() != NULL) {
        if (*(subTreePtr->getLeftChildPtr()) == *targetNodePtr) {
            return subTreePtr;
        } else {
            findLeftSidePredecessor(targetNodePtr,
                    subTreePtr->getLeftChildPtr());
        }
    }
    if (subTreePtr->getRightChildPtr() != NULL) {
        if (*(subTreePtr->getRightChildPtr()) == *targetNodePtr) {
            return subTreePtr;
        } else {
            findLeftSidePredecessor(targetNodePtr,
                    subTreePtr->getRightChildPtr());
        }
    }
}

#endif

