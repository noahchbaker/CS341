//Assignment #5: Color Me Dawgs
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_HTREE_H

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree //Inherits from BinarySearchTree
{
	public:
		RedBlackTree(); //Constructor
		virtual ~RedBlackTree(); //Destructor

		//Phase 3 + 4
		virtual void insert(int data);

		//Phase 5
		void printRedNodes(TreeNode * root);
		void printBlackNodes(TreeNode * root);

	//Phase 4
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
};

#endif
