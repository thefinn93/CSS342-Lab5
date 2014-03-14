/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 *
 */

#ifndef THREADEDBST_H
#define	THREADEDBST_H

#include "nodeData.h"
#include "node.h"

using namespace std;

/**
 * A ThreadedBST
 */
class ThreadedBST {
public:


    /*---------CONTSTRUCTORS----------*/

    /**
     * A standard constructor, initializes an empty TBST.
     */
    ThreadedBST();

    /**
     * A constructor that initializes the TBST from a specified root node
     * @param rootNode  The node to use as the root
     * when intitializing the tree.
     */
    ThreadedBST(Node* rootNode);

    /**
     * Initializes a TBST. At this point we have not determined the purpose of
     * this constructor, but it was in the book and we suspect it may come in
     * hand later
     * @param rootNode  The root node
     * @param leftTreePtr
     * @param rightTreePtr
     */
    ThreadedBST(const Node& rootNode,
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



    /*-------PUBLIC METHODS-------*/

    /**
     * Checks to see if the tree is empty.
     * @returns True if the three is empty, False otherwise.
     */
    bool isEmpty() const;

    /**
     * Returns the height of the tree.
     * @return int The height of the tree.
     */
    int getHeight() const;

    /**
     * Returns the total number of tokens stored in this tree
     * @return The number of nodes in this tree.
     */
    int getNumberOfNodes();

    /**
     * Inserts a token into the tree, or increments the token frequency if the
     * token already exists in the node.
     * @param token The token to insert.
     * @return True if successful, false otherwise
     */
    bool insert(string token);

    bool isTokenInTree(string searchToken);

    bool remove(string token);

    /**
     * Retrieves the frequency of a given token
     * @param token The token to search for
     * @return The frequency count of the specified token, or 0 if the token
     ** is not in this tree
     */
    int getFrequencyOfToken(string token);

    /**
     * Preforms an in-order traversal of the tree,
     * executing the passed method
     *  on each node as it is visited. This version uses an iterative algorithm
     * @param (*visit)(nodeData&)  The function to execute on the node.
     */
    void iterativeInorder(void visit(NodeData*));

    /**
     * Preforms an in-order traversal of the tree,
     * executing the passed method
     *  on each node as it is visited.
     * @param (*visit)(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
//    void inorder(void visit(NodeData*), Node* newRootPtr);

    /**
     * Preforms a pre-order traversal of the tree,
     * executing the passed method
     *  on each node as it is visited.
     * @param (*visit)(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void preorder(void (&)(NodeData)) const;

    /**
     * Preforms a post-order traversal of the tree,
     * executing the passed method
     *  on each node as it is visited.
     * @param (*visit)(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void postorder(void visit(NodeData*), Node* newRootPtr);

    void preorderStart(void visit(NodeData*));
    void inorderStart(void visit(NodeData*));
    void postorderStart(void vist(NodeData*));

protected:

    /*Copy Tree Helper*/
    Node* copyTree(const Node* treeRootPrt) const;

    /*Destructor Helper*/
    void destroyTree(const Node* treeRootPtr);

    /*Get Tree Height Helper*/
    int getHeightHelper(Node* subTreePtr) const;

    /*Is Token In Tree*/
    bool isTokenInTreeHelper(Node* currentNode, string searchToken);

    bool isNodeALeaf(Node* currentNode);

    Node* nodeWithToken(Node* currentNode, string searchToken);

    Node* previousNodeInThread(Node* subTreePtr, Node* pointsToThisNode);

    /*Add Node Helper*/
    /**
     * A private function to insert a new node into the tree.
     * Based heavily on Frank Carrano's sample code
     * @param subTreePtr    A pointer to the root of the tree
     * the insert is being preformed on.
     * @param newNodePtr    A pointer to the new node that's being inserted.
     * @return The root pointer.
     */
    Node* balancedInsertHelper(Node* subTreePtr, Node* leftTail,
            Node* rightTail, Node* newNodePtr, int leftOrRight);

    /*Increment Frequency Helper*/
    /**
     * Sets the frequency of the specified token, or increments
     * it if no value is specified.
     * @param token     The token to set the frequency for.
     * @param frequency (optional) The new frequency for the token.
     * Increments
     ** the value by 1 if not specified
     * @return True if successful, false otherwise
     */
    bool setFrequency(string token, int frequency);

    void preorderHelper(void (&visit)(NodeData), Node* treePtr) const;

    /*Remove Node Helper*/
    Node* removeHelper(string token, Node* treeRootPtr);

    Node* removeLeafAndRelink(Node* leafToRemove);

    Node* findLeftSidePredecessor(Node* targetNodePtr, Node* subTreePtr);

private:
    /// The root node
    Node* rootPtr;

};

#include "tbst.cpp"
#endif

