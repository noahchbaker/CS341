//Assignment #5: Color Me Dawgs
//Binary Search Tree Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	if (root_ != nullptr)
	{
		delete root_;
	}
}

TreeNode * BinarySearchTree::getRoot()
{
	return root_;
}

void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	root_ = insertNode(root_, newNode);
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
	//Note that "root" refers to the root of a sub-tree, not the root of the whole entire tree
	// If the BST is empty - go ahead and make the node the root.

	if (root == nullptr)
	{
		return node;
	}
	else
	{
		// Determining which subtree to insert the node into
		if (node->getData() < root->getData())
		{
			//Belongs in left Subtree
			root->setLeftChild(insertNode(root->getLeftChild(), node));
			root->getLeftChild()->setParent(root);
		}
		else
		{
			//Belongs in right Subtree
			root->setRightChild(insertNode(root->getRightChild(), node));
			root->getRightChild()->setParent(root);
		}

		return root;
	}
}

void BinarySearchTree::inorder(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}

	inorder(root->getLeftChild());
	std::cout << root->getData() << " ";
	inorder(root->getRightChild());
}

void BinarySearchTree::preorder(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->getData() << " ";
	preorder(root->getLeftChild());
	preorder(root->getRightChild());

}

void BinarySearchTree::postorder(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}

	postorder(root->getLeftChild());
	postorder(root->getRightChild());
	std::cout << root->getData() << " ";
}

void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}
