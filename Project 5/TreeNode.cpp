//Assignment #5: Color Me Dawgs
//Tree node Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "TreeNode.h"
#include <iostream>

TreeNode::TreeNode(int data)
{
	//We could also use the initialization list here...
	data_ = data;
	leftChild_ = nullptr;
	rightChild_ = nullptr;
	parent_ = nullptr;
	grandparent_ = nullptr;
	color_ = 0;
}

TreeNode::~TreeNode()
{
	//Recursive Delete
	if (leftChild_ != nullptr)
	{
		delete leftChild_;
	}

	if (rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

int TreeNode::getData()
{
	return data_;
}

TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}

void TreeNode::setLeftChild(TreeNode * child)
{
	leftChild_ = child;
}

void TreeNode::setRightChild(TreeNode * child)
{
	rightChild_ = child;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

void TreeNode::setGrandparent(TreeNode * grandparent)
{
	grandparent_ = grandparent;
}

TreeNode * TreeNode::getGrandparent()
{
	return grandparent_;
}
//Phase 3
bool TreeNode::getColor()
{
	if(color_ == 0) //RED
	{
		return 0;
	}
	else //BLACK
	{
		return 1;
	}
}

void TreeNode::setColor(bool color)
{
	color_ = color;
}

void TreeNode::printColor(TreeNode * node)
{
	if(node->getColor() == 0)
	{
		std::cout << "RED" << std::endl;
	}
	else if(node->getColor() == 1)
	{
		std::cout << "BLACK" << std::endl;
	}
}
