/**  bst implementation file from Carrano 6ed.
  this version uses cout rather than exceptions

  @file BinarySearchTree.cpp
 */
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#ifndef _BINARY_SEARCH_TREE_CPP
#define _BINARY_SEARCH_TREE_CPP

#include <iostream>

#include "BinarySearchTree.h" 
#include "BinaryNode.h" 

//////////////////////////////////////////////////////////////
//
//      Protected Utility Methods Section
//
//////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                                                BinaryNode<ItemType>* newNodePtr) {
   if (subTreePtr == NULL)
      return newNodePtr;
   else {
      if (subTreePtr->getItem() > newNodePtr->getItem()){
         subTreePtr->setLeftChildPtr(insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr));
      } else {
         subTreePtr->setRightChildPtr(insertInorder(subTreePtr->getRightChildPtr(), newNodePtr));
      }
      return subTreePtr;
   }  // end else
}  // end insertInorder

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr,
                                                              const ItemType target, 
                                                              bool& success)
{
   if (subTreePtr == NULL)           
   {
      // Not found here
      success = false;
      return NULL;
   }
   if (subTreePtr->getItem() == target)
   {
      // Item is in the root of some subtree
      subTreePtr = removeNode(subTreePtr);
      success = true;
      return subTreePtr;
   }
   else 
   {
      if (subTreePtr->getItem() > target)
         // Search the left subtree
         subTreePtr->setLeftChildPtr(removeValue(subTreePtr->getLeftChildPtr(), target, success));
      else 
         // Search the right subtree
         subTreePtr->setRightChildPtr(removeValue(subTreePtr->getRightChildPtr(), target, success));
      
      return subTreePtr;
   }  // end if
}  // end removeValue

/** removes specfied child ponter. Improves modularity by removing duplicate code
 */
template<class ItemType>
BinaryNode<ItemType>* removeChildNode(BinaryNode<ItemType>* ChildNodePtr){
      BinaryNode<ItemType>* nodeToConnectPtr = ChildNodePtr->getRightChildPtr();
      delete ChildNodePtr;
      ChildNodePtr = NULL;
      return nodeToConnectPtr;
}

/* remove specified node
    Case 1) Node is a leaf - it is deleted
    Case 2) Node has one child - parent adopts child
    Case 3) Node has two children:
            Traditional implementation: Find successor node.
            Alternate implementation: Find successor value and replace node's value;
                    alternate does not need pass-by-reference
*/
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr){
   if (nodePtr->isLeaf()){
      delete nodePtr;
      return (nodePtr = NULL); // Assign and return (perhaps student should have separate statements)
   }
   else if (nodePtr->getLeftChildPtr() == NULL)  // Has rightChild only
   {
      //return removeChildNode(nodePtr->getRightChildPtr());
      BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getRightChildPtr();
      delete nodePtr;
      nodePtr = NULL;
      return nodeToConnectPtr; /**/
   }
   else if (nodePtr->getRightChildPtr() == NULL) // Has left child only
   {
      //return removeChildNode(nodePtr->getLeftChildPtr());
      /* */BinaryNode<ItemType>* nodeToConnectPtr = nodePtr->getLeftChildPtr();
      delete nodePtr;
      nodePtr = NULL;
      return nodeToConnectPtr;   /**/    
   }
   else                                             // Has two children
   {
      // Traditional way to remove a value in a node with two children
      ItemType newNodeValue;
      nodePtr->setRightChildPtr(removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue));
      nodePtr->setItem(newNodeValue);
      return nodePtr;
      
      // Alernative way to remove a value in a node with two children; does not require pass-by-reference.
      // We need to check whether this right child has a left child.
      // This is similar to the base case in "findSuccessorValue" but we need to remove the
      // special case where the right child *is* the inorder successor
/*
      BinaryNode<ItemType>* myRightChildPtr = nodePtr->getRightChildPtr();
      BinaryNode<ItemType>* myLeftGrandChildPtr = myRightChildPtr->getLeftChildPtr();
      
      // Special case - right child is successor
      if (myLeftGrandChildPtr == NULL) 
      {
         nodePtr->setItem(myRightChildPtr->getItem());
         nodePtr->setRightChildPtr(removeNode(myRightChildPtr));
         return nodePtr;
      } 
      else 
      {
         // Now we can recurse
         nodePtr->setItem(findSuccessorValue(nodePtr->getRightChildPtr()));
         return nodePtr;
      }  // end if
*/
   }  // end if
}  // end removeNode

template<class ItemType> 
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr,
                                                                     ItemType& inorderSuccessor)
{
   if (nodePtr->getLeftChildPtr() == NULL)
   {
      inorderSuccessor = nodePtr->getItem();
      return removeNode(nodePtr);
   }
   else 
   {
      nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
      return nodePtr;
   }  // end if      
}  // end removeLeftmostNode

/*
template<class ItemType>
ItemType BinarySearchTree<ItemType>::findSuccessorValue(BinaryNode<ItemType>* subTreePtr)
{
   BinaryNode<ItemType>* myLeftChildPtr = subTreePtr->getLeftChildPtr();
   if (myLeftChildPtr->getLeftChildPtr() == NULL) {
      ItemType nodeItemValue = myLeftChildPtr->getItem();
      subTreePtr->setLeftChildPtr(removeNode(myLeftChildPtr));
      return nodeItemValue;
   }
   else 
   {
      return findSuccessorValue(subTreePtr->getLeftChildPtr());
   }  // end if  
}  // end findSuccessorValue 
*/

// Override findNode because now we can use a binary search:
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr,
                                                           const ItemType& target) const 
{
   // Uses a binary search 
   if (subTreePtr == NULL)
      return NULL;                        // Not found 
   else if (subTreePtr->getItem() == target)  
      return subTreePtr;                     // Found
   else if (subTreePtr->getItem() > target)
      // Search left subtree
      return findNode(subTreePtr->getLeftChildPtr(), target);
   else
      // Search right subtree
      return findNode(subTreePtr->getRightChildPtr(), target);
}  // end findNode


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(NULL)
{
}  // end default constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem)
{
   rootPtr = new BinaryNode<ItemType>(rootItem, NULL, NULL);
}  // end constructor

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& treePtr)
{
   rootPtr = this->copyTree(treePtr.rootPtr); // Call inherited method
}  // end copy constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
   return rootPtr == NULL;
}  // end isEmpty

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
   return this->getHeightHelper(rootPtr); // Call inherited method
}  // end getHeight

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const
{
   return this->getNumberOfNodesHelper(rootPtr); // Call inherited method
}  // end getNumberOfNodes

template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
   this->destroyTree(rootPtr); // Call inherited method
   rootPtr = NULL;
}  // end clear

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const  // throw(PrecondViolatedExcep) 
{
      if (isEmpty())
         cout << "getRootData() called with empty tree." << endl;
         //throw PrecondViolatedExcep("getRootData() called with empty tree."); 

   return rootPtr->getItem();
}  // end getRootData

// Must override setRootData to disable its affect:
template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newItem) const  // throw(PrecondViolatedExcep) 
{
   cout << "Cannot change root value in a BST!" << endl;
   //throw PrecondViolatedExcep("Cannot change root value in a BST!");
}  // end setRootData

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newData)
{
   BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
   rootPtr = insertInorder(rootPtr, newNodePtr);
   
   return true;
}  // end add

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& target)
{
   bool isSuccessful = false;
   rootPtr = removeValue(rootPtr, target, isSuccessful);
   return isSuccessful; 
}  // end remove

// Override getEntry to use our improved findNode:
template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const  // throw(NotFoundException)
{
   BinaryNode<ItemType>* nodeWithEntry = findNode(rootPtr, anEntry);
   if (nodeWithEntry == NULL){
      cout << "Entry not found in tree." << endl;  
      //throw NotFoundException("Entry not found in tree.");
   } // else
      return nodeWithEntry->getItem();
}  // end getEntry

// Override contains to use our improved findNode:
template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const
{

   return findNode(rootPtr, anEntry);  // NULL is same as false
}  // end contains


//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const
{
   this->preorder(visit, rootPtr); // Call inherited method
}  // end preorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const
{
  this->inorder(visit, rootPtr); // Call inherited method
}  // end inorderTraverse

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const
{
   this->postorder(visit, rootPtr); // Call inherited method
}  // end postorderTraverse

/* template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverseIterative(void visit(ItemType&)) const{ // rcs 24 Nov 2013
   this->inorderIterative(visit, rootPtr); // Call inherited method
} 
*/


//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

template<class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::
                            operator=(const BinarySearchTree<ItemType>& rightHandSide)
{
   if (!isEmpty())
      clear();
   this = copyTree(&rightHandSide); // Call inherited method
   
   return *this;
}  // end operator=

#endif
