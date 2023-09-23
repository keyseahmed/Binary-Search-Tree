#ifndef BSTREE_H
#define BSTREE_H
#include "TreeNode.h"
class BSTree
{
private:
	TreeNode* root;

	TreeNode* insert(TreeNode* root, int value);

	TreeNode* remove(TreeNode* root, int value);

	bool search(TreeNode* root, int value);

	void inOrderTraversal(TreeNode* root);

public:
	BSTree();

	void insert(int value);

	bool search(int value);

	void inOrderTraversal();
};

#endif
