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

/// A threaded binary search tree

class ThreadedBST {
public:


    /*---------CONTSTRUCTORS----------*/

    /**
     * A standard constructor, initializes an empty TBST.
     */
    ThreadedBST();

    /**
     * A constructor that initializes the TBST from a specified root node
     * @param rootNode  The node to use as the root when intitializing the tree.
     */
    ThreadedBST(const Node& rootNode);

    /**
     * Initializes a TBST. At this point we have not determined the purpose of
     * this constructor, but it was in the book and we suspect it may come in
     * hand later
     * @param rootNode
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
    bool isEmpty();

    /**
     * Returns the height of the tree.
     * @return int The height of the tree.
     */
    int getHeight() const;

    /**
     * Returns the total number of tokens stored in this tree
     * @return The number of nodes in this tree.
     */
    int getNumberOfNodes() const;

    /**
     * Inserts a token into the tree, and optionally frequency for that token
     * @param token The token to insert.
     * @param frequency (optional) The frequency of this token. Assumed 1 if
     ** not specified
     * @return True if successful, false otherwise
     */
    bool insert(string token, int frequency);

    /**
     * Inserts a token if it is not already there, otherwise increments the
     ** frequency count for that token.
     * @param token The token to insert or increment
     * @return True if successful, false otherwise
     */
    bool insertOrIncrement(string token);

    /**
     * Sets the frequency of the specified token, or increments it if no value is specified.
     * @param token     The token to set the frequency for.
     * @param frequency (optional) The new frequency for the token. Increments
     ** the value by 1 if not specified
     * @return True if successful, false otherwise
     */
    bool setFrequency(string token, int frequency);

    /**
     * Removes a node from the tree by token.
     * @param token The token to remove
     * @return True if successful, false otherwise
     */
    bool remove(string token);

    /**
     * Retrieves the frequency of a given token
     * @param token The token to search for
     * @return The frequency count of the specified token, or 0 if the token
     ** is not in this tree
     */
    int getFrequency(string token);


    /**
     * Checks if the specified token is in this tree
     * @param token The token to search for
     * @return True if the token is in this tree, false otherwise
     */
    bool exists(string token);


    /**
     * Preforms an in-order traversal of the tree, executing the passed method
     *  on each node as it is visited. This version uses an iterative algorithm
     * @param (*visit)(nodeData&)  The function to execute on the node.
     */
    void iterativeInorder(void visit(NodeData*));

    /**
     * Preforms an in-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param (*visit)(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void inorder(void visit(NodeData*), Node* newRootPtr);

    /**
     * Preforms a pre-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param (*visit)(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void preorder(void vist(NodeData*), Node* newRootPtr);

    /**
     * Preforms a post-order traversal of the tree, executing the passed method
     *  on each node as it is visited.
     * @param (*visit)(nodeData&)  The function to execute on the node.
     * @param treePtr           The root of the tree to traverse
     */
    void postorder(void visit(NodeData*), Node* newRootPtr);

    void preorderStart(void visit(NodeData*) const);
    void inorderStart(void visit(NodeData*) const);
    void postorderStart(void vist(NodeData*) const);

protected:
    
    /*Is Token In Tree*/
    bool isTokenInTree(string token);

    /*Copy Tree Helper*/
    Node* copyTree(const Node* treeRootPrt) const;

    /*Get Tree Height Helper*/
    int getHeightHelper(Node* subTreePtr) const;

    /*Destructor Helper*/
    void destroyTree(const Node* treeRootPtr);


    /*Add Node Helper*/

    /**
     * A private function to insert a new node into the tree. Based heavily on Frank Carrano's sample code
     * @param subTreePtr    A pointer to the root of the tree the insert is
     * being preformed on.
     * @param newNodePtr    A pointer to the new node that's being inserted.
     * @return The root pointer.
     */
    Node* balancedAddHelper(Node* subTreePtr, Node* newNodePtr);

    /*Remove Node Helper*/
    Node* removeHelper(string token, Node* root);


    ///TODO - findEntry()
    
    
private:
    /// The root node
    Node* rootPtr;

};

//#include "tbst.cpp"
#endif

