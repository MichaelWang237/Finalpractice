#include "bst.h"
#include <time.h>

bst::bst(){root = NULL;}

void bst::build() {
  srand((unsigned)time(0));
  int arrayLength = rand()%5+10;
  int values[arrayLength];
  for (int a = 0; a < arrayLength; a++){values[a] = -1;}
  for (int a = 0; a < arrayLength; a++) {
    bool duplicate = false;
    do {
      duplicate = false;
      values[a] = rand()%30+1;
      for (int b = 0; b < arrayLength; b++) {
        if ((a != b) && (values[a] == values[b])) {duplicate = true;}
      }
    } while (duplicate == true);
  }
  for (int a = 0; a < arrayLength; a++) {
    node* newnode = new node();
    newnode->data = values[a];
    node* current = root;
    if (root == NULL) {
      root = newnode;
    }
    else {
      while(current != NULL) {
        if (newnode->data < current->data) {
          if (current->left == NULL) {
            current->left = newnode;
	    break;
	  }
	  else {
            current = current->left;
	  }
	}
	else {
          if (current->right == NULL) {
            current->right = newnode;
	    break;
	  }
	  else {
            current = current->right;
	  }
	}
      }
    }
  }
}

void bst::display_tree(node* current, int level) {
  if (current->right != NULL) {display_tree(current->right, level+1);}
  for (int a = 0; a < level; a++) {cout << "\t";}
  cout << current->data << " (";
  if (current->left != NULL) cout << current->left->data << ",";
  else cout << ",";
  if (current->right != NULL) cout << current->right->data << ")" << endl;
  else cout << ")" << endl;
  if (current->left != NULL) {display_tree(current->left, level+1);}
}

void bst::display() {
  cout << "---------Tree Printout----------" << endl;
  display_tree(root, 0);
  cout << "--------------------------------" << endl;
}

node* bst::findSuccessor(node* n, bool&dir){
  if(n == NULL){
    if(root->left != NULL){
      n = root->left;
      dir = false;
    }
    else if(root->right != NULL){
      n = root->right;
      dir = true;
    }
    else{
      cout << "root is the only node in the tree, it has no successor" << endl;
      return root;
    }
  }
  if(dir){
    if(n != NULL && n->left == NULL){
      cout << n->data;
      return n;
    }
    else if(n->left != NULL){
      findSuccessor(n->left, dir);
    }
  }
  else if(!dir){
    if(n != NULL && n->right == NULL){
      cout << n->data;
      return n;
    }
    else if(n->right != NULL){
      n = n->right;
      findSuccessor(n->right, dir);
    }
  }
  return n;
}

void bst::counter(node* n, int&count){
if(n == NULL){
  n = root;
}
 if(n->left == NULL && n->right == NULL){
  count++;  
 return;
 } 
  if(n->left !=NULL){
   counter(n->left, count);
  }
  if(n->right != NULL){
  counter(n->left, count);   
  }
}

void bst::delete2Smallest(node*n, node* prev, int&count){
  if(n == NULL){
    n = root;
  }
  if(n->left == NULL){
    if(n->right != NULL){
      if(n == root){
        root = n->right;
        delete n;
        n = root;
        count+=1;
      }
      else{
        cout << n->data << " has a right child" << endl;
        prev->left = n->right;
        delete n;
        n = root;
        count+=1;
      }
    }
    else if(n->right == NULL){
      cout << n->data << " is a leaf node" << endl;
      prev->left = NULL;
      delete n;
      n = root;
      count+=1;
    }
  }
  if(n->left != NULL && count < 2){
    delete2Smallest(n->left, n, count);
  }
  return;
}

void bst::deleteGreaterThanRoot(){
  node* prev = root;
  if(root->right == NULL){
    cout << "nothing greater than root" << endl;
    return;
  }
  else{
    node* n = root->right;
    if(n->left != NULL && n->right != NULL){
      node* successor = root->right;
      while(successor->left != NULL){
        prev = successor;
        successor = successor->left;
      }
      n->data = successor->data;
      n = successor;
    }
    if(n->left != NULL){
      if(n == prev->right){
        prev->right = n->left;
        delete n;
      }
      else{
        prev->left = n->left;
        delete n;
      }
    }
    else if(n->right != NULL){
      if(n == prev->right){
        prev->right = n->right;
        delete n;
      }
      else{
        prev->left = n->right;
        delete n;
      }
    }
    else if(n->right == NULL && n->left == NULL){
      if(n == prev->left){
        prev->left = NULL;
        delete n;
      }
      else{
        prev->right = NULL;
        delete n;
      }
    }
  deleteGreaterThanRoot();
  }
  return;
}