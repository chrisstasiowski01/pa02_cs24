#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>

#include "movies.h"
using namespace std;

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file
  Movies tree;
  // Read each file and store the name and rating
  tree.createTree(argv[2]);
  tree.printPreODepth();
  cout << endl;
  tree.highestRating(argv[3]);
  movieFile.close();

  return 0;
}

