#include "BST.h"

template<typename T>
BST<T>::BST()
    :root(nullptr), size(0)
{
}

template<typename T>
BST<T>::BST(const BST<T> &oth)
    :root(nullptr), size(0)
{
    root = copyRecursive(oth.root);
    size = oth.size;
}

template<typename T>
BST<T>& BST<T>::operator=(const BST<T> &oth) {
    if(this != &oth) {// Check for self-assignment
        clear();// Clear the current tree

        copyRecursive(oth.root);
        size = oth.size;
    }
    return *this;
}

template<typename T>
BST<T>::~BST() {
    destroyTree(root);
}

template<typename T>
void BST<T>::insert(const T &val) {
    root = insertRecursive(root, val);
}

template<typename T>
bool BST<T>::search(const T &val) {
    return searchRecursive(root, val);
}

template<typename T>
int BST<T>::getHeight() {
    return getHeightRecursive(root);
}

template<typename T>
T BST<T>::getMax() {
    if (root == nullptr) {
        // Handle the case where the tree is empty
        throw std::logic_error("BST is empty");
    }
    return findMax(root)->data;
}

template<typename T>
T BST<T>::getMin() {
    if (root == nullptr) {
        // Handle the case where the tree is empty
        throw std::logic_error("BST is empty");
    }
    return findMin(root)->data;
}

template<typename T>
T BST<T>::getPredecessor(const T &val) {
    Node<T>* predecessor = nullptr;
    Node<T>* curr = root;

    while(curr) {
        if(val < curr->val) {
            curr = curr->left;
        } else if (val > curr->val){
            predecessor = curr;
            curr = curr->right;
        } else {
            if(curr->left) {
                // Case 1: If the left subtree is not empty
                predecessor = findMax(curr->left);
            }
            break;
        }
    }
    return predecessor ? predecessor->val : T();// Return the data of the predecessor
}

template<typename T>
T BST<T>::getSuccessor(const T &val) {
    Node<T>* successor = nullptr;
    Node<T>* curr = root;

    while(curr) {
        if(val < curr->val) {
            successor = curr;
            curr = curr->left;
        } else if(val > curr->val) {
            curr = curr->right;
        } else {
            if(curr->right) {
                // Case 1: If the right subtree is not empty
                successor = findMin(curr);
            }
            break;
        }
    }
    return successor ? successor->val : T();// Return the data of the successor
}

template<typename T>
void BST<T>::inorderTraversal() {
    inorderRecursive(root);
    std::cout << std::endl;
}

template<typename T>
void BST<T>::postorderTraversal() {
    postorderRecursive(root);
    std::cout << std::endl;
}

template<typename T>
void BST<T>::preorderTraversal() {
    preorderRecursive(root);
    std::cout << std::endl;
}

template<typename T>
Node<T>* BST<T>::copyRecursive(const Node<T> *node) {
    if(!node) return nullptr;

    auto* newNode = new Node<T>(node->val);
    newNode->left = copyRecursive(node->left);
    newNode->right = copyRecursive(node->right);

    return newNode;
}

template<typename T>
Node<T>* BST<T>::insertRecursive(Node<T> *node, const T &val) {
    if(!node) {
        size++;
        return new Node<T>(val);
    }
    if(node->val < val) {
        node->right = insertRecursive(node->right, val);
    } else {
        node->left = insertRecursive(node->left, val);
    }
    return node;
}

template<typename T>
bool BST<T>::searchRecursive(Node<T> *node, const T &val) {
    if(!node) return false;
    if(node->val == val) return true;
    if(node->val < val) {
        return searchRecursive(node->right, val);
    } else {
        return searchRecursive(node->left, val);
    }
}

template<typename T>
int BST<T>::getHeightRecursive(Node<T> *node) {
    if(!node) return -1;
    // Return the maximum of left and right subtree heights, plus 1 for the current node
    return std::max(getHeightRecursive(node->left), getHeightRecursive(node->right)) + 1;
}

template<typename T>
Node<T>* BST<T>::findMax(Node<T> *node) {
    while(node->right) {
        node = node->right;
    }
    return node;
}

template<typename T>
Node<T>* BST<T>::findMin(Node<T> *node) {
    while(node->left) {
        node = node->left;
    }
    return node;
}

template<typename T>
void BST<T>::inorderRecursive(Node<T> *node) {
    if(!node) return;
    inorderRecursive(node->left);
    std::cout << node->val << " ";
    inorderRecursive(node->right);
}

template<typename T>
void BST<T>::postorderRecursive(Node<T>* node){
    if(!node) return;
    inorderRecursive(node->left);
    inorderRecursive(node->right);
    std::cout << node->val << " ";
}

template<typename T>
void BST<T>::preorderRecursive(Node<T>* node){
    if(!node) return;
    std::cout << node->val << " ";
    inorderRecursive(node->left);
    inorderRecursive(node->right);
}

template<typename T>
void BST<T>::destroyTree(Node<T>* node) {
    if(!node) return;

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
}

template<typename T>
void BST<T>::clear() {
    destroyTree(root);
    root = nullptr;
    size = 0;
}