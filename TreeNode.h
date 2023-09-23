#ifndef TREENODE_H
#define	TREENODE_H
class TreeNode
{
public:
	int data; 
	TreeNode* leftChild; 
	TreeNode* rightChild; 
public:
	TreeNode(); 
	TreeNode(int value);
};

#endif

