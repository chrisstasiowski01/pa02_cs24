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

// inserts node into BST
bool Movies::insert(string mName, double mRating){
  if(!root){
    root = new Node(mName, mRating);
    return true;
  }else{
    return insertHelper(mName, mRating, root);
  }
}

// helper function for insert()
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

// prints movies of BST in pre-order
void Movies::printPreO() const{
  printPreOHelper(root);
}

// helper for printPreO()
void Movies::printPreOHelper(Node* n) const{
  if(n){
    cout << n->name << ", " << n->rating << endl;
    printPreOHelper(n->left);
    printPreOHelper(n->right);
  }
}

// returns true if a movie with desired name is in BST, otherwise returns false
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

// takes input file and uses insert() to create BST
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
    bool flag = false;
    string tempRating = "";
    double mRating = 0.0;
    for(int i = 0; i < line.length(); i++){
      if(flag){
        tempRating += line[i];
      }else if((line[i] == ',') && (line[0] != '"')){
        flag = true;
      }else{
        if(i == 0 && line[0] == '"'){
          continue;
        }
        if(line[i] == '"'){
          i++;
          flag = true;
          continue;
        }
        mName += line[i];
      }
    }
    mRating = stod(tempRating);
    insert(mName, mRating);
  }
  file.close();
  return;
}

// returns number of movies in BST that contain desired prefix
int Movies::containsPrefix(string prefix){
  return containsPreHelper(prefix, root);
}

// returns true if node contains movie with desired prefix, else returns false
bool Movies::containsPrefixHelper(string prefix, Node *check){
  for(int i = 0; i < prefix.length(); i++){
    if(prefix[i] != check->name[i]){
      return false;
    }
  }
  return true;
}

// recursive helper for containsPrefix()
int Movies::containsPreHelper(string prefix, Node* n){
  if(!n){
    return 0;
  }else if(containsPrefixHelper(prefix, n) == true){
    return (1 + containsPreHelper(prefix, n->left) + containsPreHelper(prefix, n->right));
  }else{
    return (0 + containsPreHelper(prefix, n->left) + containsPreHelper(prefix, n->right));
  }
}

// prints best movie and rating with desired prefix
void Movies::highestRating(string prefix){
  if(containsPrefix(prefix) == 0){
    return;
  }
  vector<string> vec;
  vector<double> rat;

  highestRatingHelper(prefix, root, vec, rat);

  double maxRating = 0;
  string maxName = "";

  for(int i = 0; i < rat.size(); i++){
    if(maxRating < rat[i]){
      maxRating = rat[i];
      maxName = vec[i];
    }
  }

  cout << "Best movie is " << maxName << " with rating " << maxRating << endl;
}

// helper for highestRating()
void Movies::highestRatingHelper(string prefix, Node* n, vector<string> &names, vector<double> &ratings){
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

// returns depth of node with desired movie
int Movies::depth(string movie){
  Node *n = root;
  int depth = 0;
  while(n){
    if(n->name == movie){
      return depth;
    }else if(n->name < movie){
      n = n->right;
      depth++;
    }else{
      n = n->left;
      depth++;
    }
  }
  return 0;
}

// prints every movie in BST with rating and depth
void Movies::printPreODepth(){
  printPreODepthHelper(root);
}

// helper for printPreODepth()
void Movies::printPreODepthHelper(Node *n){
  if(n){
    cout << n->name << ", " << n->rating << ", " << depth(n->name) << endl;
    printPreODepthHelper(n->left);
    printPreODepthHelper(n->right);
  }
}

// prints run-time data in ms for contains()
void Movies::containsData(int w){
  vector<double> time;
  for(int i = 0; i < w; i++){
    containsDataHelper(root, time);
  }
  sort(time.begin(), time.end());
  cout << "Number of runs: " << w << endl;
  cout << "Minimum time (ms): " << *min_element(time.begin(), time.end()) << endl;
  cout << "Maximum time (ms): " << *max_element(time.begin(), time.end()) << endl;
  cout << "Median (ms): " << time[(time.size()-1)/2] << endl;
}

// helper for containsData()
void Movies::containsDataHelper(Node* n, vector<double> &t){
  if(!n){
    return;
  }
  clock_t start, end;
  start = clock();
  contains(n->name);
  end = clock();
  double time_taken = ((double(end - start)/double(CLOCKS_PER_SEC))*1000000);
  t.push_back(time_taken);
  containsDataHelper(n->left, t);
  containsDataHelper(n->right, t);
}
// returns number of nodes visited
int Movies::insertData(string mName, double mRating){
  if(!root){
    root = new Node(mName, mRating);
    return 0;
  }else{
    return insertHelperData(mName, mRating, root);
  }
}

// recursive helper for insertData()
int Movies::insertHelperData(string mName, double mRating, Node* n){
  if(mName == n->name){
    return 1;
  }
  if(mName < n->name){
    if(n->left){
      return (1+insertHelperData(mName, mRating, n->left));
    }else{
      n->left = new Node(mName, mRating);
      n->left->parent = n;
      return 1;
    }
  }else{
    if(n->right){
      return (1+insertHelperData(mName, mRating, n->right));
    }else{
      n->right = new Node(mName, mRating);
      n->right->parent = n;
      return 1;
    }
  }
}

// creates output file with two columns: N and N_visited when creating a BST
void Movies::createTreeData(string filename){
  ifstream file;
  ofstream output;
  output.open("createTreeData.csv");
  string line;
  file.open(filename);
  int n = 0;
  int n_visited = 0;
  while(1){
    getline(file, line);
    if(!file){
      break;
    }
    string mName = "";
    bool flag = false;
    string tempRating = "";
    double mRating = 0.0;
    for(int i = 0; i < line.length(); i++){
      if(flag){
        tempRating += line[i];
      }else if((line[i] == ',') && (line[0] != '"')){
        flag = true;
      }else{
        if(i == 0 && line[0] == '"'){
          continue;
        }
        if(line[i] == '"'){
          i++;
          flag = true;
          continue;
        }
        mName += line[i];
      }
    }
    mRating = stod(tempRating);
    n_visited = insertData(mName, mRating);
    output << n << "," << n_visited << endl;
    n++;
  }
  output.close();
  file.close();
  return;
}