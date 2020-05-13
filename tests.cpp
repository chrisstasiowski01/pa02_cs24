#include "tests.h"
#include "movies.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  void test_create_tree();
  return 0;
}

void test_create_tree(){
  cout << endl << "BEGIN CREATE TREE TEST" << endl;
  Movies testTree;
  testTree.createTree("input_20_ordered.csv");
  cout << "Expected (Pre-Order):" << endl;
  cout << "Actual (Pre-Order):" << endl;
  testTree.printPreO();
  cout << "END CREATE TREE TEST" << endl << endl;
}