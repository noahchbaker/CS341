//Assignment #4: Hop Dawg
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode(int data, LinkedNode * nextLinkedNode, LinkedNode *prevLinkedNode);
		//LinkedNode(int data); //this is rybars linkednode Constructor
		virtual ~LinkedNode();
		LinkedNode * getNextLinkedNode();
		void setNextLinkedNode(LinkedNode * nextLinkedNode);
		bool hasNextLinkedNode();
		LinkedNode * getPrevLinkedNode();
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		bool hasPrevLinkedNode();
	private:
		LinkedNode * nextLinkedNode_;
		LinkedNode * prevLinkedNode_;
};

#endif
