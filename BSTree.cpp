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

bool BSTree::search(int value) {
	return search(root, value);
}

void BSTree::inOrderTraversal() {
	inOrderTraversal(root);
}

TreeNode* BSTree::remove(TreeNode* root, int value) {
    TreeNode* parent = nullptr;
    TreeNode* current = root;
    // Traverse the tree to find the node with the specified value
    while (current != nullptr) {
        if (value == current->data) {
            // Case 1: Node to remove has no children (a leaf node)
            if (current->leftChild == nullptr && current->rightChild  == nullptr) {
                if (parent == nullptr) {
                    root = nullptr; // Node is the root; set root to nullptr
                } else if (parent->leftChild == current) {
                    parent->leftChild = nullptr; // Node is the leftChild child of the parent
                } else {
                    parent->rightChild  = nullptr; // Node is the rightChild  child of the parent
                }
                delete current; // Delete the node
            }
            // Case 2: Node to remove has only a rightChild  child
            else if (current->leftChild == nullptr) {
                if (parent == nullptr) {
                    root = current->rightChild ; // Node is the root; update root
                } else if (parent->leftChild == current) {
                    parent->leftChild = current->rightChild ;
                } else {
                    parent->rightChild  = current->rightChild ;
                }
                delete current;
            }
            // Case 3: Node to remove has only a leftChild child
            else if (current->rightChild  == nullptr) {
                if (parent == nullptr) {
                    root = current->leftChild ; // Node is the root; update root
                } else if (parent->leftChild == current) {
                    parent->leftChild = current->leftChild ;
                } else {
                    parent->rightChild  = current->leftChild ;
                }
                delete current;
            }
            // Case 4: Node to remove has both leftChild and rightChild  children
            else {
                TreeNode* successor = current->rightChild ;
                while (successor->leftChild != nullptr) {
                    successor = successor->leftChild ;
                }
                current->data = successor->data;
                parent = current;
                current = current->rightChild ;
                value = successor->data;
            }
        } else if (value < current->data) {
            parent = current;
            current = current->leftChild ; // Move to the leftChild subtree
        } else {
            parent = current;
            current = current->rightChild ; // Move to the rightChild  subtree
        }
    }
}
