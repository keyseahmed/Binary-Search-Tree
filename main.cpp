#include<iostream>
#include "BSTree.h"
using namespace std; 


int main() {
    BSTree bst;
   
     bst.insert(50);
     bst.insert(30);
     bst.insert(70);
     bst.insert(20);
     bst.insert(40);

    int searchValue = 30;
    if (bst.search( searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    }
    else {
        cout << searchValue << " not found in the tree." << endl;
    }

    searchValue = 60;
    if (bst.search(searchValue)) {
        cout << searchValue << " found in the tree." << endl;
    }
    else {
        cout << searchValue << " not found in the tree." << endl;
    }

    cout << "Elements in the tree: ";
    bst.inOrderTraversal();
    cout << endl;

    return 0;
}
