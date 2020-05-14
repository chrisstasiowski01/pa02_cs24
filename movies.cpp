// movies.cpp
// implements class Movies

#include "movies.h"

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
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

void Movies::createTree(string filename){
  ifstream file;
  string line;
  file.open(filename);
  while(1){
    getline(file, line);
    if(!file){
      break;
    }
    string mName = "";
    int comma = 0;
    for(int i = 0; line[i] != ','; i++){
      mName = mName + line[i];
      comma++;
    }
    comma++;
    string mRatingString = "";
    for(int i = comma; i < line.length(); i++){
      mRatingString = mRatingString + line[i];
    }
    double mRating = stod(mRatingString);
    insert(mName, mRating);
  }
  file.close();
  return;
}

int Movies::containsPrefix(string prefix){
  return containsPreHelper(prefix, root);
}

bool Movies::containsPrefixHelper(string prefix, Node *check){
  for(int i = 0; i < prefix.length(); i++){
    if(prefix[i] != check->name[i]){
      return false;
    }
  }
  return true;
}

int Movies::containsPreHelper(string prefix, Node* n){
  if(!n){
    return 0;
  }else if(containsPrefixHelper(prefix, n) == true){
    return (1 + containsPreHelper(prefix, n->left) + containsPreHelper(prefix, n->right));
  }else{
    return (0 + containsPreHelper(prefix, n->left) + containsPreHelper(prefix, n->right));
  }
}

void Movies::highestRating(string prefix){
  vector<string> vec;
  vector<double> rat;
  highestRatingHelper(prefix, root, vec, rat);
  int maxRating = 0;
  string maxName = "";
  for(int i = 0; i < rat.size(); i++){
    cout << rat[i] << " ";
    if(maxRating < rat[i]){
      maxRating = rat[i];
      maxName = vec[i];
    }
  }
  cout << "Best movie is " << maxName << " with rating " << maxRating << endl;
}

void Movies::highestRatingHelper(string prefix, Node* n, vector<string> names, vector<double> ratings){
  if(!n){
    return;
  }
  if(containsPrefixHelper(prefix, n) == true){
    names.push_back(n->name);
    ratings.push_back(n->rating);
  }
  highestRatingHelper(prefix, n->left, names, ratings);
  highestRatingHelper(prefix, n->right, names, ratings);
}