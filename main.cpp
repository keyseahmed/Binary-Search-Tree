#include<iostream>
#include "BSTree.h"
using namespace std; 


int main() {
    BSTree bst;
   
    bst.insert(50);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(30);
    bst.insert(20);
    bst.insert(60);
    bst.insert(80);

    // Test case 1: Remove a leaf node (20)
    std::cout << "Remove 20: ";
    bst.remove(20);
    bst.inOrderTraversal(); // Expected output: 30 40 50 60 70 80
    std::cout << std::endl;

    // Test case 2: Remove a node with one child (30)
    std::cout << "Remove 30: ";
    bst.remove(30);
    bst.inOrderTraversal(); // Expected output: 40 50 60 70 80
    std::cout << std::endl;

    // Test case 3: Remove a node with two children (50)
    std::cout << "Remove 50: ";
    bst.remove(50);
    bst.inOrderTraversal(); // Expected output: 40 60 70 80
    std::cout << std::endl;

    // Test case 4: Attempt to remove a node that doesn't exist (10)
    std::cout << "Remove 10 (non-existent): ";
    bst.remove(10);
    bst.inOrderTraversal(); // Expected output: 40 60 70 80
    std::cout << std::endl;

    // Test case 5: Remove the root node (60)
    std::cout << "Remove 60 (root): ";
    bst.remove(60);
    bst.inOrderTraversal(); // Expected output: 40 70 80
    std::cout << std::endl;

    // Test case 6: Remove the last remaining node (80)
    std::cout << "Remove 80 (last remaining): ";
    bst.remove(80);
    bst.inOrderTraversal(); // Expected output: 40 70
    std::cout << std::endl;

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

