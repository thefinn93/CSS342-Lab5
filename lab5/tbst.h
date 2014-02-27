/* 
 * File:   tbst.h
 * Author: Nick
 *
 * Created on February 26, 2014, 8:11 PM
 */

#ifndef THREADEDBST_H
#define	THREADEDBST_H

#include "nodeData.h"

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
     * Initializes a TBST
     * @param rootNode
     * @param leftTreePtr
     * @param rightTreePtr
     */
    ThreadedBST(const NodeData& rootNode,
                const ThreadedBST* leftTreePtr,
                const ThreadedBST* rightTreePtr);

    /**
     * Creates a copy of another TBST
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

private:
    /// The root node
    ThreadedBST* rootPtr;

};

#endif	/* THREADEDBST_H */

