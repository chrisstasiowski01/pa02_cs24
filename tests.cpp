#include "tests.h"
#include "movies.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  test_create_tree();
  test_insert();
  test_contains();
  return 0;
}

void test_create_tree(){
  cout << endl << "BEGIN CREATE TREE TEST" << endl;
  Movies testTree;
  testTree.createTree("test1.csv");
  cout << "Expected (Pre-Order):" << endl << "goldeneye, 6.6" << endl
    << "dracula: dead and loving it, 5.7" << endl << "balto, 7.1" << endl
    << "cutthroat island, 5.7" << endl << "the american president, 6.5"
    << endl << "nixon, 7.1" << endl;
  cout << "Actual (Pre-Order):" << endl;
  testTree.printPreO();
  cout << "END CREATE TREE TEST" << endl << endl;
}

void test_insert(){
  cout << "BEGIN INSERT TEST" << endl;
  Movies testTree;
  cout << "Empty movie BST created." << endl;
  testTree.insert("avengers", 7.6);
  cout << "BST after inserting 'avengers, 7.6':" << endl;
  testTree.printPreO();
  cout << "New BST created with four movies." << endl;
  Movies testTree2;
  testTree2.createTree("test2.csv");
  cout << "BST before inserting 'schindler's list, 8.8':" << endl;
  testTree2.printPreO();
  testTree2.insert("schindler's list", 8.8);
  cout << "BST after inserting 'schindler's list, 8.8':" << endl;
  testTree2.printPreO();
  cout << "END INSERT TEST" << endl << endl;
}

void test_contains(){
  cout << "BEGIN CONTAINS TEST" << endl << "Test 1: ";
  Movies testTree;
  if(testTree.contains("balto") == false){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 2: ";
  testTree.createTree("test1.csv");
  if(testTree.contains("the american president") == true){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 3: ";
  if(testTree.contains("avengers") == false){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "END CONTAINS TEST" << endl << endl;
}