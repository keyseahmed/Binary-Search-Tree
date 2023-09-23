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
	
}