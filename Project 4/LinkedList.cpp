//Assignment #4: Hop Dawg
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "Node.h"
#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) //Constructor
{

}

LinkedList::~LinkedList() //Destructor
{
	//Only checking head b/c if there is no head, there is no tail
	if(head_ != nullptr)
	{
		delete head_;
	}
}

//Getters and setters for head and tail
LinkedNode * LinkedList::getHead()
{
	return head_;
}

void LinkedList::setHead(LinkedNode * node)
{
	head_ = node;
}

LinkedNode * LinkedList::getTail()
{
	return tail_;
}

void LinkedList::setTail(LinkedNode * node)
{
	tail_ = node;
}

bool LinkedList::isEmpty()
{
	if(head_ == nullptr && tail_ == nullptr)
	{
		return true;
	}

	return false;
}

int LinkedList::getLength()
{
	return size_;
}

void LinkedList::insert(int element)
{
	LinkedNode * insert = new LinkedNode(element, head_, tail_);
	insert->setNextLinkedNode(nullptr);

	if(head_ == nullptr) //A list starts with zero nodes
	{
		size_++;
		head_ = insert;
		tail_ = insert;
	}
	else
	{
		size_++;
		tail_->setNextLinkedNode(insert);
		tail_ = insert;
	}

	std::cout << "Inserting " << element << "..." << std::endl;
}

void LinkedList::printList()
{
	LinkedNode * temp = head_;

	do
	{
		std::cout << temp->getValue();
		temp = temp->getNextLinkedNode();

		if(temp != nullptr)
		{
			std::cout <<"-->";
		}

	} while(temp != nullptr);

	std::cout << std::endl;
}

bool LinkedList::findElement(int data)
{
	bool found(false);
	int i(0);

	LinkedNode * node = head_;

	while (found != true && i != size_)
	{
		if (node->getValue() == data)
		{
			found = true;
		}

		if (node->hasNextLinkedNode())
		{
			node = node->getNextLinkedNode();
		}

		i++;
	}

	return found;
}

void LinkedList::removeNode(int data)
{
	LinkedNode * node = head_;

	if (node->hasNextLinkedNode())
	{
		if (node->getNextLinkedNode()->getValue() == data)
		{
			node->setNextLinkedNode(node->getNextLinkedNode()->getNextLinkedNode());
		}
	}
	else
	{
		head_ = nullptr;
		tail_ = nullptr;
	}
}
