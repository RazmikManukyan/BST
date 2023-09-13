#ifndef BST_NODE_H
#define BST_NODE_H

template<typename T>
struct Node {
    explicit Node(const T& v, Node<T>* l = nullptr, Node<T>* r = nullptr)
        :val(v), left(l), right(r) {}

    T val;
    Node<T>* left;
    Node<T>* right;
};

#endif //BST_NODE_H
