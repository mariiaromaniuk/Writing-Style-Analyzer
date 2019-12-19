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
    BSTree(const BSTree<T>&);
    BSTree<T>& operator=(const BSTree<T>&);
    void preOrderDummy();
    void inOrderDummy();
    void postOrderDummy();
    bool searchDummy(T);
    void insert(T);
    int treeHeight();
    bool isEmpty();
    void deleteTreeDummy();
    
private:
    void copyTree(Node<T>* &, Node<T>*);
    void preOrder(Node<T>*);
    void inOrder(Node<T>*);
    void postOrder(Node<T>*);
    bool search(T,Node<T>*);
    void deleteTree(Node<T>*);
    
};

#endif /* BSTree_hpp */

