//
//  BSTree.cpp
//  Tree Project
//
//  Created by Mariia Romaniuk
//

#include "BSTree.hpp"

// Constructor
template <class T>
BSTree<T>::BSTree(){
    root = nullptr;
}

// Destructor
template <class T>
BSTree<T>::~BSTree(){
    deleteTree(root);
}

// Copy Constructor
template <class T>
BSTree<T>::BSTree(const BSTree<T> & otherRoot){
    if (otherRoot == nullptr)
        root = nullptr;
    else
        copyTree(root, otherRoot);
}

// Overloading assignment operator
template <class T>
BSTree<T>& BSTree<T>::operator=(const BSTree<T>& otherRoot){
    if (this != & otherRoot) {
        if (root != nullptr)
            deleteTree(root);
        if (otherRoot == nullptr)
            root = nullptr;
        else
            copyTree(root, otherRoot);
    }
    return *this;
}

// Dummy function to pass the root to preOrder
template <class T>
void BSTree<T>::preOrderDummy(){
    preOrder(root);
}

// Dummy function to pass the root to inOrder
template <class T>
void BSTree<T>::inOrderDummy(){
    inOrder(root);
}

// Dummy function to pass the root to postOrder
template <class T>
void BSTree<T>::postOrderDummy(){
    postOrder(root);
}

// Dummy function to pass the root to search
template <class T>
bool BSTree<T>::searchDummy(T item){
    search(item,root);
}

// Function that inserts item to the tree
template <class T>
void BSTree<T>::insert(T item){
    
    Node<T>* temp = new Node<T>;
    temp->info = item;
    temp->left = temp->right = nullptr;
    
    
    if (root == nullptr)
        root = temp;
    else{
        Node<T>* p = root;
        Node<T>* r = nullptr;
        
        while (p != nullptr){
            r = p;
            if (p->info == item){
                p->counter += 1;
                return;
            }
            else if (p->info > item)
                p = p->left;
            else
                p = p->right;
        }
        
        if (r -> info < item)
            r->right = temp;
        else
            r->left = temp;
    }
}

// Function that return the height of the tree
template <class T>
int BSTree<T>::treeHeight(){
    return height(root);
}

// Function to check if tree is empty
template <class T>
bool BSTree<T>::isEmpty(){
    return (root == nullptr);
}

// Dummy function to pass the root to deleteTree
template <class T>
void BSTree<T>::deleteTreeDummy(){
    return deleteTree(root);
}

// Copy Tree
template <class T>
void BSTree<T>::copyTree(Node<T>* &root, Node<T>* otherRoot){
    if (otherRoot == nullptr)
        root = nullptr;
    else {
        root = new Node<T>;
        root->info = otherRoot->info;
        copyTree(root->left, otherRoot->left);
        copyTree(root->right, otherRoot->right);
    }
}

// Function that prints out each node's data in preorder
template <class T>
void BSTree<T>::preOrder(Node<T>* p){
    if (p != nullptr){
        cout << p->info << endl;
        preOrder(p->left);
        preOrder(p->right);
    }
}

// Function that prints out each node's data in order
template <class T>
void BSTree<T>::inOrder(Node<T>* p){
    if (p != nullptr){
        inOrder(p->left);
        cout << p->info << endl;
        inOrder(p->right);
    }
}

// Function that prints out each node's data in postorder
template <class T>
void BSTree<T>::postOrder(Node<T>* p){
    if (p != nullptr){
        postOrder(p->left);
        postOrder(p->right);
        cout << p->info << endl;
    }
}

// Function that search item in the tree
template <class T>
bool BSTree<T>::search(T item, Node<T>* p) {
    if (p == nullptr)
        return false;
    if (p->info == item)
        return true;
    if (p->info < item)
        search(item, p->right);
    if (p->info > item)
        search(item, p->right);
}

// Function that deletes tree
template <class T>
void BSTree<T>::deleteTree(Node<T>* p){
    if (p != nullptr){
        if (p->left != nullptr)
            deleteTree(p->left);
        if (p->right != nullptr)
            deleteTree(p->right);
        delete p;
    }
}
