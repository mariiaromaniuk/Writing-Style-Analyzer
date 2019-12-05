//
//  BSTree.hpp
//  Tree Project
//
//  Created by Mariia Romaniuk
//

#ifndef BSTree_hpp
#define BSTree_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


template <class T>
struct Node {
    T info;
    Node* left;
    Node* right;
    int count = 0;
};

template <class T>
class BSTree{
    
protected:
    Node<T>* root;
    
public:
    BSTree();
    ~BSTree();
    void preOrderDummy();
    void postOrderDummy();
    void inOrderDummy();
    bool searchDummy(T);
    void preOrder(Node<T>*);
    void postOrder(Node<T>*);
    void inOrder(Node<T>*);
    bool search(T, Node<T>*);
    void insert(T);
    void deleteTree(Node<T>*);
};

#endif /* BSTree_hpp */
