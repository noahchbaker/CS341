//Assignment #4: Hop Dawg
//Doubly Linked List Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

//Important note for data insertion: sort the data first then do insert

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : LinkedList()
{

}

DoublyLinkedList::~DoublyLinkedList()
{

}


int DoublyLinkedList::getLength()
{
	return size_;
}

void DoublyLinkedList::printList()
{
	LinkedNode * temp = getHead();
	do
	{
		std::cout << temp->getValue();
		temp = temp->getNextLinkedNode();

		if(temp!= nullptr)
		{
			std::cout <<"<-->";
		}

	} while(temp != nullptr);

	std::cout << std::endl;
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	node = LinkedList::getTail();
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);
	if(!isEmpty())
	{
		if(node == LinkedList::getTail())
		{
			node->setNextLinkedNode(newNode); //Forwards
			newNode->setPrevLinkedNode(node); //Backwards
			LinkedList::setTail(newNode); //Settting new tail
		}

		else if(node == LinkedList::getHead())
		{
			newNode->setPrevLinkedNode(node); //Backwards
			node->setNextLinkedNode(newNode); //Forwards
			LinkedList::setHead(node); //Setting new head isnt this if statment literally saying the node is head??
		}
		else
		{
			//places newnode inbetween node and whatever is after node
			node->getNextLinkedNode()->setPrevLinkedNode(newNode);
			//makes next linked node od newnode = node->nextLinkedNode
			newNode->setNextLinkedNode(node->getNextLinkedNode());
			node->setNextLinkedNode(newNode);
			newNode->setPrevLinkedNode(node);
		}
	}
	else
	{
		LinkedList::setHead(newNode);
		LinkedList::setTail(newNode);
	}
	//std::cout << "Inserting " << data << "..." << std::endl;
	size_++;
}

void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);
	if(getLength() == 0)
	{
		//node is now the head with the value of newnode
		node->setValue(newNode->getValue());
		LinkedList::setHead(node);
		LinkedList::setTail(node);
	}
	else
	{
		if(node == LinkedList::getTail())
		{
			node->setNextLinkedNode(newNode); //Forwards
			newNode->setPrevLinkedNode(node); //Backwards
			LinkedList::setTail(newNode); //Settting new tail
			newNode->setNextLinkedNode(nullptr);
		}
		else //if (node != LinkedList::getTail())
		{
			//places newnode inbetween node and whatever is after node
			node->getNextLinkedNode()->setPrevLinkedNode(newNode);
			//makes next linked node od newnode = node->nextLinkedNode
			newNode->setNextLinkedNode(node->getNextLinkedNode());
			node->setNextLinkedNode(newNode);
			newNode->setPrevLinkedNode(node);
		}
	}


	//std::cout << "Inserting " << data << "..." << std::endl;
	size_++;
}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);

	if(getLength() == 0)
	{
		//node is now the head with the value of newnode
		node->setValue(data);
		LinkedList::setHead(node);
		LinkedList::setTail(node);
	}

	if(node == LinkedList::getHead())
	{
		node->setPrevLinkedNode(newNode); //Backwards
		newNode->setNextLinkedNode(node); //Forwards
		LinkedList::setHead(newNode);
		newNode->setPrevLinkedNode(nullptr);
	}
	else //(node != LinkedList::getHead())
	{
		//newNode is pointing to the previous node (backwards)
		newNode->setPrevLinkedNode(node->getPrevLinkedNode());

		//The next node is pointing forwards at newNode (forward)
		node->getPrevLinkedNode()->setNextLinkedNode(newNode);

		//newNode points forward to the node (forward)
		newNode->setNextLinkedNode(node);

		//node points back to newNode (backwards)
		node->setPrevLinkedNode(newNode);
	}

	//std::cout << "Inserting " << data << "..." << std::endl;
	size_++;

}
