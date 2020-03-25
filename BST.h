//
//  BST.h
//  Binary Search Tree Class Implementation
//
//  Created by Zloteanu Anastasia on 25/03/2020.
//  Copyright © 2020 Zloteanu Anastasia. All rights reserved.
//
#include <cstddef>
#include <iostream>

#ifndef BST_h
#define BST_h

using namespace std;

struct Node {
  Node(int value): data(value), left(NULL), right(NULL) {}
  int data;
  Node * left;
  Node * right;
};

// BST class
class BST {
  private:
    Node * _root;
    void insert(Node * treeNode, int data);
    void leaves(Node * treeNode);
    int getHeight(Node * treeNode);
    void deleteBST(Node * treeNode);
    void inOrder(Node * treeNode);
    void preOrder(Node * treeNode);
    void postOrder(Node * treeNode);
    Node* remove(Node * treeNode, int value);
  
  
  public:
    BST(); // constructor
    ~BST(); // destructor
    
    void operator +(int);
    
    void remove(int value) {
      remove(_root, value);
    }
  
    void leaves() {
      leaves(_root);
    }
    
    void insert(int data) {
      insert(_root, data);
    }

    int getHeight() {
      return getHeight(_root);
    }
    
    void inOrder() {
      inOrder(_root);
    }
    void preOrder() {
      preOrder(_root);
    }
    void postOrder() {
      postOrder(_root);
    }
  
    friend ostream& operator<<(ostream&, BST&);
    friend istream & operator>>(istream &,BST&);
};

#endif
