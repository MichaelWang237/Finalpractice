#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    //char d = 'x';
    //object.findSuccessor(NULL, d);
    //cout << "2nd printout: " << s->data << endl;
    bool dir;
    int out = 0;
    node* s;
    //object.delete2Smallest(NULL, s, out);
    object.deleteGreaterThanRoot();
    object.display();	//displays again after!
    
    return 0;
}
