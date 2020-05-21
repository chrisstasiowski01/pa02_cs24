// movies.h
// binary search tree header file for CS24 PA02

#ifndef MOVIES_H
#define MOVIES_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

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
    void containsData(int w); // collects data for absolute running time of contains function
    int insertData(std::string mName, double mRating);
    void createTreeData(std::string filename); // writes N and N-visited to csv file
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
    // helper functions (used to access nodes)
    bool containsPrefixHelper(std::string prefix, Node *check);
    void clear(Node* r);
    bool insertHelper(std::string mName, double mRating, Node* n);
    void printPreOHelper(Node* n) const;
    int containsPreHelper(std::string prefix, Node *n);
    void highestRatingHelper(std::string prefix, Node *n, std::vector<std::string> &names, std::vector<double> &ratings);
    void printPreODepthHelper(Node *n);
    void containsDataHelper(Node* n, std::vector<double> &t);
    int insertHelperData(std::string mName, double mRating, Node* n);
};

#endif