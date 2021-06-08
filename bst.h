//bst.h
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class bst
{
    public:
    	//These functions are supplied already
    	bst();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied

/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
    /*
    Write a recursive function in C++ to find the root’s in-order predecessor.
    Write a recursive function in C++ to remove the smallest two items in a binary search tree.
    Write a recursive function to delete everything (individually) in the binary tree larger than the root. (No memory leaks!)
    */
        node* findSuccessor(node* n, bool&dir);
        void delete2Smallest(node* n, node* prev, int&count);
        void counter(node*n, int&count);
        void deleteGreaterThanRoot();
        
 	private:
 		node * root;
		void display_tree(node*, int);
};
  

