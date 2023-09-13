#include "BST.h"

int main() {
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(8);

    bst.inorderTraversal();
    bst.postorderTraversal();
    bst.preorderTraversal();
    return 0;
}
