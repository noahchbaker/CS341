//Assignment #4: Hop Dawg
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "LinkedNode.h"

LinkedNode::LinkedNode(int data, LinkedNode * nextLinkedNode,  LinkedNode *prevLinkedNode) :  Node(data), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{

}

//this is rybar pseudo code
/*LinkedNode::LinkedNode(int data) :  Node(data)
{
	Node newnode(data);
}*/

LinkedNode::~LinkedNode()
{
	if(nextLinkedNode_ != nullptr)
	{
		delete nextLinkedNode_;
	}
}

LinkedNode * LinkedNode::getNextLinkedNode()
{
	return nextLinkedNode_;
}

void LinkedNode::setNextLinkedNode(LinkedNode * nextLinkedNode)
{
	nextLinkedNode_ = nextLinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_ != nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

LinkedNode * LinkedNode::getPrevLinkedNode()
{
	return prevLinkedNode_;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasPrevLinkedNode()
{
	if(prevLinkedNode_ != nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
