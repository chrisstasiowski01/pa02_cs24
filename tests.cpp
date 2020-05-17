#include "tests.h"
#include "movies.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
  test_create_tree();
  test_insert();
  test_contains();
  test_contains_prefix();
  test_highest_rating();
  test_depth();
  test_print_preorder_depth();
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

void test_contains_prefix(){
  cout << "BEGIN CONTAINS PREFIX TEST" << endl << "Test 1: ";
  Movies testTree;
  testTree.createTree("test3.csv");
  if(testTree.containsPrefix("the") == 3){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 2: ";
  if(testTree.containsPrefix("last") == 1){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 3: ";
  if(testTree.containsPrefix("th") == 4){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 4: ";
  if(testTree.containsPrefix("z") == 0){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "END CONTAINS PREFIX TEST" << endl << endl;
}

void test_highest_rating(){
  cout << "BEGIN HIGHEST RATING TEST" << endl;
  Movies testTree;
  testTree.createTree("test3.csv");
  cout << "Test 1:" << endl << "Expected: Best movie is the white balloon with rating 7.5"
    << endl << "Actual: ";
  testTree.highestRating("the");
  cout << endl << "Test 2:" << endl << "Expected: Best movie is bottle rocket with rating 6.8"
    << endl << "Actual: ";
    Movies testTree2;
    testTree2.createTree("test4.csv");
    testTree2.highestRating("b");
  cout << endl << "Test 3:" << endl << "Expected: Best movie is casino with rating 7.8"
    << endl << "Actual: ";
    Movies testTree3;
    testTree3.createTree("test5.csv");
    testTree3.highestRating("c");
    cout << "END HIGHEST RATING TEST" << endl << endl;
}

void test_depth(){
  cout << "BEGIN DEPTH TEST" << endl << "Test 1: ";
  Movies testTree;
  testTree.createTree("test3.csv");
  if(testTree.depth("the crossing guard") == 0){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 2: ";
  if(testTree.depth("once upon a time... when we were colored") == 2){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "Test 3: ";
  if(testTree.depth("last summer in the hamptons") == 3){
    cout << "PASSED" << endl;
  }else{
    cout << "FAILED" << endl;
  }
  cout << "END DEPTH TEST" << endl << endl;
}

void test_print_preorder_depth(){
  cout << "BEGIN PRINT PREORDER W/ DEPTH TEST" << endl << "Test 1:"
    << endl << "Expected:" << endl;
  Movies testTree;
  testTree.createTree("test3.csv");
  cout << "the crossing guard, 6.1, 0" << endl << "antonia'sline, 7.2, 1"
    << endl << "once upon a time... when we were colored, 4.5, 2" << endl
    << "last summer in the hamptons, 0, 3" << endl << "the juror, 5.5, 1"
    << endl << "the white balloon, 7.5, 2" << endl << "things to do in denver when you're dead, 6.7, 3"
    << endl << "Actual:" << endl;
  testTree.printPreODepth();
  Movies testTree2;
  testTree2.createTree("test2.csv");
  cout << "Test 2:" << endl << "Expected:" << endl << "dead presidents, 6.6, 0"
    << endl << "restoration, 6.3, 1" << endl << "mortal kombat, 5.4, 2" << endl
    << "to die for, 6.7, 2" << endl << "Actual:" << endl;
  testTree2.printPreODepth();
  cout << "END PRINT PREORDER W/ DEPTH TEST" << endl << endl;
}