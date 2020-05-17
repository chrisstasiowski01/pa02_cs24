// movies.h
// binary search tree header file for CS24 PA02

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <vector>


class Movies{

  public:
    Movies(); // constructor
    ~Movies(); // destructor
    bool insert(std::string mName, double mRating); // inserts movie and rating into BST
    void printPreO() const; // prints BST pre-order
    void highestRating(std::string prefix); // prints movie name and rating for best movie with given prefix
    bool contains(std::string name) const; // returns true if BST contains given movie name
    int containsPrefix(std::string prefix); // returns number of movies in BST with given prefix
    void createTree(std::string filename); // reads lines from file and inputs into BST
    int depth(std::string movie); // returns depth of node with given movie
    void printPreODepth(); // prints BST pre-order with node depth
  private:
    struct Node{
      std::string name;
      double rating;
      Node *left, *right, *parent;
      Node(std::string s = "", double r = 0) : name(s), rating(r), left(NULL), right(NULL), parent(NULL) {}
    };
    Node *root;
    Node* getNodeFor(std::string search); // returns pointer to node of BST with given movie name
    int nodeDepth(Node* getDepth); // returns depth of given node
    bool containsPrefixHelper(std::string prefix, Node *check); // returns true if node contains movie name with given prefix
    void clear(Node* r); // helper for public destructor
    bool insertHelper(std::string mName, double mRating, Node* n); // helper for insert function
    void printPreOHelper(Node* n) const; // helper for printPreO function
    int containsPreHelper(std::string prefix, Node *n);
    void highestRatingHelper(std::string prefix, Node *n, std::vector<std::string> &names, std::vector<double> &ratings);
    void printPreODepthHelper(Node *n);
};

#endif