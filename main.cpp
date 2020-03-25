//
//  main.cpp
//  Binary Search Tree Class Implementation
//
//  Created by Zloteanu Anastasia on 25/03/2020.
//

#include <iostream>
#include "BST.h"

using namespace std;

int main() {
  BST myBST;
  
  myBST + 1;
  myBST + 8;
  myBST + 50;
  myBST + 7;
  myBST + 12;

  int h = myBST.getHeight();
  cout << "BST height: " << h << endl;
  
  cout << myBST;
 
  cout << endl<< "Leaves: "<< endl;
  
  myBST.leaves();
  
  cout<<endl;
  return 0;
}
