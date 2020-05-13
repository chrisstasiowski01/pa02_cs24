// movies.h
// binary search tree header file for CS24 PA02

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
using namespace std;

class Movies{

  public:
    Movies(); // constructor
    ~Movies(); // destructor
    bool insert(string mName, double mRating); // inserts movie and rating into BST
    void printPreO() const; // prints BST pre-order
    void highestRating(string prefix); // prints movie name and rating for best movie with given prefix
    bool contains(string name) const; // returns true if BST contains given movie name
    int containsPrefix(string prefix); // returns number of movies with given prefixes
    void createTree(string filename); // reads lines from file and inputs into BST
  private:
    struct Node{
      string name;
      double rating;
      Node *left, *right, *parent;
      Node(string s = "", double r = 0) : name(s), rating(r), left(NULL), right(NULL), parent(NULL) {}
    };
    Node *root;
    Node* getNodeFor(string search); // returns pointer to node of BST with given movie name
    int nodeDepth(Node* getDepth); // returns depth of given node
    bool containsPrefix(string prefix, Node *check); // returns true if node contains movie name with given prefix
    void clear(Node* r); // helper for public destructor
    bool insertHelper(string mName, double mRating, Node* n); // helper for insert function
    void printPreOHelper(Node* n) const; // helper for printPreO function
};

#endif