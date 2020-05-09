// movies.cpp
// implements class Movies

#include "movies.h"

#include <string>
#include <iostream>
using namespace std;

// constructor sets up empty BST
Movies::Movies() : root(NULL) {}

// destructor deletes all nodes
Movies::~Movies(){
  clear(root);
}

// helper for destructor
void Movies::clear(Node* r){
  if(r){
    clear(r->left);
    clear(r->right);
    delete r;
  }
}

bool Movies::insert(string mName, double mRating){
  if(!root){
    root = new Node(mName, mRating);
    return true;
  }else{
    return insertHelper(mName, mRating, root);
  }
}

bool Movies::insertHelper(string mName, double mRating, Node* n){
  if(mName == n->name){
    return false;
  }
  if(mName < n->name){
    if(n->left){
      return insertHelper(mName, mRating, n->left);
    }else{
      n->left = new Node(mName, mRating);
      n->left->parent = n;
      return true;
    }
  }else{
    if(n->right){
      return insertHelper(mName, mRating, n->right);
    }else{
      n->right = new Node(mName, mRating);
      n->right->parent = n;
      return true;
    }
  }
}

void Movies::printPreO() const{
  printPreOHelper(root);
}

void Movies::printPreOHelper(Node* n) const{
  if(n){
    cout << n->name << ", " << n->rating << endl;
    printPreOHelper(n->left);
    printPreOHelper(n->right);
  }
}

bool Movies::contains(string name) const{
  Node *n = root;
  while(n){
    if(n->name == name){
      return true;
    }else if(n->name < name){
      n = n->right;
    }else{
      n = n->left;
    }
  }
  return false;
}