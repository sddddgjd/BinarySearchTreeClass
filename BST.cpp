//
//  BST.cpp
//  Binary Search Tree Class Implementation
//
//  Created by Zloteanu Anastasia on 25/03/2020.
//  Copyright © 2020 Zloteanu Anastasia. All rights reserved.
//

#include "BST.h"
#include <iostream>
using namespace std;

BST::BST() {
  _root = NULL;
}

BST::~BST() {
  deleteBST(_root);
}

void BST::deleteBST(Node * treeNode) {
  if (!treeNode)
    return;

  Node * curTreeNode = treeNode;
  Node * leftTreeNode = treeNode -> left;
  Node * rightTreeNode = treeNode -> right;
  delete(curTreeNode);
  deleteBST(leftTreeNode);
  deleteBST(rightTreeNode);
}

Node* BST::remove(Node * treeNode, int value) {
    if (!treeNode)
        return treeNode;

    if (value < treeNode -> data) {
        treeNode -> left = remove(treeNode -> left, value);
    } else if (value > treeNode -> data) {
        treeNode -> right = remove(treeNode -> right, value);
    } else {

        if (!treeNode -> left) {
            return treeNode -> right;
        } else if (!treeNode -> right)
            return treeNode -> left;
        
        int min = treeNode -> data;
        Node* nextNode = treeNode;
      
        while (nextNode -> left) {
          nextNode = nextNode -> left;
          min = nextNode -> data;
        }
        
      treeNode -> data = nextNode -> data;
      treeNode -> right = remove(treeNode -> right, treeNode -> data);
    }

    return treeNode;
}

void BST::leaves(Node* treeNode) {
  if (treeNode -> left)
    leaves(treeNode->left);
  if (treeNode -> right)
    leaves(treeNode->right);
  if (!treeNode -> left && !treeNode -> right)
    cout<< treeNode -> data<<" ";
}

void BST::operator +(int x){
  insert(_root, x);
}

void BST::insert(Node * treeNode, int data) {
  if (!treeNode) {
    treeNode = new Node(data);
    _root = treeNode;
  } else {
    if (data < treeNode -> data) {
      if (!treeNode -> left) {
        Node * treeTemp = new Node(data);
        treeNode -> left = treeTemp;
      } else
        insert(treeNode -> left, data);
    } else {
      if (!treeNode -> right) {
        Node * treeTemp = new Node(data);
        treeNode -> right = treeTemp;
      } else
        insert(treeNode -> right, data);
    }
  }
}

int BST::getHeight(Node * treeNode) {
  if (!treeNode)
    return 0;
  return 1 + max(getHeight(treeNode -> left), getHeight(treeNode -> right));
}

istream &operator >>(istream& in,BST& tree)
{
    int value;
    in>>value;
    tree+value;
    return in;
}

ostream &operator<<(ostream& out, BST& tree)
{
  cout<<"Preoder: "<<endl;
  tree.preOrder();
  
  cout<<endl<<"Inorder: "<<endl;
  tree.inOrder();
  
  cout<<endl<<"PostOrder: "<<endl;
  tree.postOrder();
  return out;
}

void BST::preOrder(Node * treeNode) {
  if (!treeNode)
    return;
  cout << treeNode -> data << " ";
  preOrder(treeNode -> left);
  preOrder(treeNode -> right);
}

void BST::inOrder(Node * treeNode) {
  if (!treeNode)
    return;
  inOrder(treeNode -> left);
  cout << treeNode -> data << " ";
  inOrder(treeNode -> right);
}

void BST::postOrder(Node * treeNode) {
  if (!treeNode)
    return;
  postOrder(treeNode -> left);
  postOrder(treeNode -> right);
  cout << treeNode -> data << " ";
}
