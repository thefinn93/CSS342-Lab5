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
     * 
     */
    ThreadedBST();
    
    /**
     * 
     * @param rootNode
     */
    ThreadedBST(const NodeData& rootNode);
    
    /**
     * 
     * @param rootNode
     * @param leftTreePtr
     * @param rightTreePtr
     */
    ThreadedBST(const NodeData& rootNode,
                const ThreadedBST* leftTreePtr,
                const ThreadedBST* rightTreePtr);
    
    /**
     * 
     * @param treeToCopy
     */
    ThreadedBST(const ThreadedBST& treeToCopy);
    
    /**
     * 
     */
    ~ThreadedBST();
    
    //-------Public Methods-------//
    
    bool
    
private:
    
    /**
     */
    ThreadedBST* rootPtr;
    
};

#endif	/* THREADEDBST_H */

