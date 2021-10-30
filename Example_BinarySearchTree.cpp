// Example_BinarySearchTree.cpp
// Task: Given a Binary Search tree and an input key, find the next InOrder successor node.
// If the input key has no InOrder Successor, return NULL.
// Author: Matthew Breit (github.com/mattsprojects)

#include<iostream>
using namespace std;

//declaration for new bst node  
struct bstnode
{
	int data;
	struct bstnode *left, *right;
};

// Create a new node for the Binary Search Tree
struct bstnode *newNode(int key)
{
	struct bstnode *temp = new struct bstnode();
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}

// Insert a new node into the BST
struct bstnode* insert(struct bstnode* node, int key)
{
	//tree is empty;return a new node
	if (node == NULL) return newNode(key);

	//if tree is not empty find the proper place to insert new node
	if (key < node->data)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	//return the node pointer
	return node;
}

// find the inorder successor of an input node and return null if there is none
struct bstnode* FindInorderSuccessor(struct bstnode* root, struct bstnode* inputNode)
{
	bstnode* current = root;
	bstnode* inOrderSuccessor = NULL;

	if (inputNode == NULL)
		return NULL;

	while (current != NULL)
	{
		if (inputNode->data < current->data)
		{
			inOrderSuccessor = current;
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	return inOrderSuccessor;

	// time complexity:
	// 5(n) + 3, n = number of nodes traversed
}

// main program
int main()
{
	/*
	Create our Binary Search Tree:
			 20
			/	\
		   9	 25
		  / \
		 5   12
			/  \
		   11  14
	*/
	int keys[] = { 20, 9, 25, 5, 12, 11, 14 };
	struct bstnode *root = NULL;
	for (int key : keys)
	{
		root = insert(root, key);
	}

	for (int key : keys)
	{
		bstnode* inputNode = NULL;
		bstnode* inOrderSuccessor = NULL;

		inputNode = newNode(key);
		inOrderSuccessor = FindInorderSuccessor(root, inputNode);
		if (inOrderSuccessor != NULL)
			cout << "Key: " << key << " inordersuccessor: " << inOrderSuccessor->data << endl;
		else
			cout << "Key: " << key << " inordersuccessor: NULL" << endl;
	}

	return 0;
}