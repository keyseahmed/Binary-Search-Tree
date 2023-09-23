#include "BSTree.h"
#include<iostream>
using namespace std;

BSTree::BSTree() : root(nullptr) {

}

TreeNode* BSTree::insert(TreeNode* root, int value) {
    TreeNode* newNode = new TreeNode(value);
    if (root == nullptr) {
        root = newNode;
        return root;
    }

    TreeNode* curr = root;

    while (true)
    {
        if (value < curr->data) {
            if (curr->leftChild == nullptr) {
                curr->leftChild = newNode;
                break;
            }
            curr = curr->leftChild;
        }
        else if (value > curr->data) {
            if (curr->rightChild == nullptr) {
                curr->rightChild = newNode;
                break;
            }
            curr = curr->rightChild;
        }
        else {
            break;
        }
    }
    return root;
}

bool BSTree::search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    TreeNode* curr = root;
    while (curr != nullptr)
    {
        if (value < curr->data) {
            curr = curr->leftChild;
        }
        else if (value > curr->data) {
            curr = curr->rightChild;
        }
        else {
            return true;
        }
    }
    return false;
}

void BSTree::inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->leftChild);
    cout << root->data << " ";
    inOrderTraversal(root->rightChild);
}

void BSTree::insert(int value) {
    root = insert(root, value);
}

void BSTree::remove(int value) {
    root = remove(root, value);
}


bool BSTree::search(int value) {
    return search(root, value);
}

void BSTree::inOrderTraversal() {
    inOrderTraversal(root);
}

TreeNode* BSTree::remove(TreeNode* root, int value) {
   // Base case
        if (root == NULL)
            return root;

        // Recursive calls for ancestors of
        // node to be deleted
        if (root->data > value) {
            root->leftChild = remove(root->leftChild, value);
            return root;
        }
        else if (root->data < value) {
            root->rightChild = remove(root->rightChild, value);
            return root;
        }

        // We reach here when root is the node
        // to be deleted.

        // If one of the children is empty
        if (root->leftChild == NULL) {
            TreeNode* temp = root->rightChild;
            delete root;
            return temp;
        }
        else if (root->rightChild == NULL) {
            TreeNode* temp = root->leftChild;
            delete root;
            return temp;
        }

        // If both children exist
        else {

            TreeNode* succParent = root;

            // Find successor
            TreeNode* succ = root->rightChild;
            while (succ->leftChild != NULL) {
                succParent = succ;
                succ = succ->leftChild;
            }

            // Delete successor.  Since successor
            // is always leftChild child of its parent
            // we can safely make successor's rightChild
            // rightChild child as leftChild of its parent.
            // If there is no succ, then assign
            // succ->rightChild to succParent->rightChild
            if (succParent != root)
                succParent->leftChild = succ->rightChild;
            else
                succParent->rightChild = succ->rightChild;

            // Copy Successor Data to root
            root->data = succ->data;

            // Delete Successor and return root
            delete succ;
            return root;
        }
    }