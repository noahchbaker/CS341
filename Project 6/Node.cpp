//Assignment #4: Hop Dawg
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker
#include "Node.h"

Node::Node(HashEntry entry)
{
	entry_ = entry;
}

Node::~Node()
{

}

HashEntry Node::getValue()
{
	return entry_;
}

void Node::setValue(HashEntry entry)
{
	entry_ = entry;
}
