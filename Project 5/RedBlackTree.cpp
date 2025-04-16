//Assignment #5: Color Me Dawgs
//Red Black Tree Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() : BinarySearchTree() //Rule #1: Red Black Tree is type of Binary Search Tree
{

}

RedBlackTree::~RedBlackTree() //Destructor
{

}

//Rule #4: Every node is either red or black, 0 == RED and 1 == BLACK
//Just inserts red nodes, and then the color of these nodes will be adjusted in the balanceColor function
void RedBlackTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	if(newNode->getColor() == 0)
	{
		BinarySearchTree::setRoot(BinarySearchTree::insertNode(BinarySearchTree::getRoot(), newNode));
		TreeNode * root = BinarySearchTree::getRoot();
		balanceColor(root, newNode);
	}
}

//Pseudo Code of balanceColor
//Have to have a condition to check if root is black after being rotated, if it is not, make it black
//Condition to check the colors of the now black root's children
	//If both nodes are black or both nodes are red, no changes necessary

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * parent = newNode->getParent();
	TreeNode * grandparent = nullptr;
	TreeNode * aunt = nullptr;

	BinarySearchTree::getRoot()->setColor(1);

	//std::cout<<"Newnode value: " << newNode->getData() << std::endl;

	//ending recursive nature using if statments
	//The parent of root is null, end of recursion
	if(newNode->getParent() == nullptr)
	{
		//std::cout<<"We are at end of recursion : root = nullptr"<<std::endl;
		BinarySearchTree::setRoot(newNode);
		return;
	}

	//Checking if parent of newNode is black, if the parent is black, no need to change color
	if(parent->getColor() == 1)
	{
		//std::cout<<"We are at end of recursion : parent is black"<<std::endl;
		return;
	}

	//The parent node of newNode is red since ot goes past above if statment, and also the root, meaning no grandparent relation exists
	if(parent->getParent() == nullptr)
	{
		//std::cout<<"We are at end of recursion : no grandparent relation"<<std::endl;
		root = newNode->getParent();
		root->setColor(1);
		return;
	}
	else
	{
		//At this point, enough nodes for grandparent! parent can be earlier but isnt needed untill here
		//std::cout<<"Making Grandparent relation"<<std::endl;
		grandparent = parent->getParent();
		//std::cout<<"This is Grandparent :" << grandparent->getData()<<std::endl;
		//std::cout<<"Parent Value:  "<< parent->getData() << std::endl;
	}

	//Getting the aunt and establishing if left or right child of grandparent
	if(parent == grandparent->getRightChild())
	{
		//std::cout<<"Aunt is Left"<<std::endl;
		aunt = newNode->getParent()->getParent()->getLeftChild();
		//aunt exists and is red
		if(aunt != nullptr && aunt->getColor() == 0)
		{
			parent->setColor(1);
			grandparent->setColor(0);
			aunt->setColor(1);
			//std::cout<<"Calling Balance color again"<<std::endl;
			balanceColor(root, grandparent);
		}
		//aunt is black, and recoloring/rotating must be done to keep balanced black nodes
		else
		{
			if(newNode == parent->getRightChild())
			{
				//std::cout<<"Calling Left Rotate then balance color"<<std::endl;
				rotateLeft(grandparent, parent);
				parent->setColor(1);
				grandparent->setColor(0);
			}
			else
			{
				//std::cout<<"Calling Right Rotate then balance color"<<std::endl;
				rotateRight(parent, newNode);
				balanceColor(root, parent);
			}
		}
	}
	else if(parent == grandparent->getLeftChild())
	{
		aunt = newNode->getParent()->getParent()->getRightChild();
		//std::cout<<"aunt is on the right side"<<std::endl;
		//aunt exists and is red
		if(aunt != nullptr && aunt->getColor() == 0)
		{
			parent->setColor(1);
			grandparent->setColor(0);
			aunt->setColor(1);
			balanceColor(root, grandparent);
		}
		//aunt is black, and recoloring/rotating must be done to keep balanced black nodes
		else
		{
			if(newNode == parent->getRightChild())
			{
				//std::cout<<"Calling Right Rotate then balance color Raunt"<<std::endl;
				rotateRight(parent, newNode);
				balanceColor(root, parent);
			}
			else
			{
				//std::cout<<"Calling Left Rotate then balance color"<<std::endl;
				rotateLeft(grandparent, parent);
				parent->setColor(1);
				grandparent->setColor(0);
			}
		}
	}
	else
	{
		//std::cout<<":("<<std::endl;
	}
}

//Pseudo Code of rotateLeft
//Left rotate with value x and y where y is initially child and x is initially parent
//right child of y stays the same with rotate
//y becomes the parent of x, and now x is the left child of y
//left child of x stays the same
//left child of y becomes right child of x

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)//3, 7
{
	root->setRightChild(newNode->getLeftChild());
	if(root->getParent() == nullptr)
	{
		BinarySearchTree::setRoot(newNode);
	}
	else
	{
		if(root == root->getParent()->getLeftChild())
		{
			root->getParent()->setLeftChild(newNode);
			newNode->setParent(root->getParent());
		}
		else
		{
			root->getParent()->setRightChild(newNode);
			newNode->setParent(root->getParent());
		}
	}
	root->setGrandparent(newNode->getParent());
	newNode->setLeftChild(root);
	root->setParent(newNode);
}

//Pseudo Code of rotateRight
//Right rotate with value x and y where x is initially child and y is initially parent
//left child of x stays the same
//x becomes parent of y, y is now right child of x
//right child of y stays the same
//right child of x becomes left child of y

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode) //y is root, x is child
{
	root->setLeftChild(newNode->getRightChild());
	if(root->getParent() == nullptr)
	{
		newNode->setParent(nullptr);
		BinarySearchTree::setRoot(newNode);
	}
	else
	{
		if(root == root->getParent()->getRightChild())
		{
			root->getParent()->setRightChild(newNode);
			newNode->setParent(root->getParent());
		}
		else
		{
			root->getParent()->setLeftChild(newNode);
			newNode->setParent(root->getParent());
		}
	}
	root->setGrandparent(newNode->getParent());
	newNode->setRightChild(root);
	root->setParent(newNode);
}

//phase 5
void RedBlackTree::printRedNodes(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}
	printRedNodes(root->getLeftChild());
	if (root->getColor() == 0)
	{
		std::cout << root->getData() << " ";
	}
	printRedNodes(root->getRightChild());
}

void RedBlackTree::printBlackNodes(TreeNode * root)
{
	if (root == nullptr)
	{
		return;
	}

	if(root->getColor() == 1)
	{
		std::cout << root->getData() << " ";
	}
	printBlackNodes(root->getLeftChild());
	printBlackNodes(root->getRightChild());
}
