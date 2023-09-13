#ifndef BST_BST_H
#define BST_BST_H
#include <iostream>
#include "Node.h"

template<typename T>
class BST {
private:
    Node<T>* root;
    std::size_t size;
public:
    BST();// Constructor
    BST(const BST<T>&);// Copy-constructor
    BST<T>& operator=(const BST<T>&);// Assignment operator
    ~BST();// Destructor

    void insert(const T&);// Insert a value into the BST
    bool search(const T&);// Search for a value in the BST
    int getHeight();// Get the height of the BST
    T getMax();// Get the maximum value in the BST
    T getMin();// Get the minimum value in the BST
    T getPredecessor(const T&);// Get the predecessor of a given value
    T getSuccessor(const T&);// Get the successor of a given value

    void inorderTraversal();// Inorder traversal (recursive)
    void postorderTraversal();// Postorder traversal (recursive)
    void preorderTraversal();// Preorder traversal (recursive)
private:
    Node<T>* copyRecursive(const Node<T>*);// Recursive helper function to copy a tree

    Node<T>* insertRecursive(Node<T>*, const T&);// Recursive helper function for inserting a value
    bool searchRecursive(Node<T>*, const T&);// Recursive helper function for searching a value
    int getHeightRecursive(Node<T>*);// Recursive helper function to get the heigh
    Node<T>* findMax(Node<T>*);// Helper function to find the maximum value node in a subtree
    Node<T>* findMin(Node<T>*);// Helper function to find the minimum value node in a subtree

    void inorderRecursive(Node<T>*);// Recursive helper function for inorder traversal
    void postorderRecursive(Node<T>*);// Recursive helper function for postorder traversal
    void preorderRecursive(Node<T>*);// Recursive helper function for preorder traversal

    void destroyTree(Node<T>*);// Recursive helper function to delete the tree
    void clear();// Helper function to clear the current tree
};


#include "BST.tpp"
#endif //BST_BST_H
