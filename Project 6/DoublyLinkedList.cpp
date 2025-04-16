//Assignment #6 - The Last Can Of Who Hash
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
	LinkedNode * print = getHead();
	while(print != nullptr)
	{

		std::cout << print->getValue().getKey();
		print = print->getNextLinkedNode();

		if(print!= nullptr)
		{
			std::cout <<"<-->";
		}

	};
	std::cout << std::endl;
	delete print;
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry entry)
{
	node = LinkedList::getTail();
	LinkedNode * newNode = new LinkedNode(entry, nullptr, nullptr);
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
	size_++;
}

void DoublyLinkedList::removeLinkedNode(int key)
{
	if(key == getHead()->getValue().getKey() && getHead() == getTail())
    {
        setHead(nullptr);
    	setTail(nullptr);
        delete getHead();
        std::cout << "Key " << key << " removed." << std::endl;
    }
    else if(key == getHead()->getValue().getKey())
    {
        LinkedNode * currentHead = getHead();
        LinkedNode * nextNode = currentHead->getNextLinkedNode();
        setHead(nextNode);
        nextNode->setPrevLinkedNode(nullptr);
        currentHead->setNextLinkedNode(nullptr);
        delete currentHead;
        std::cout << "Key " << key << " removed." << std::endl;
    }
    else if(key == getTail()->getValue().getKey())
    {
        LinkedNode * currentTail = getTail();
        LinkedNode * prevNode = currentTail->getPrevLinkedNode();
        setTail(prevNode);
        prevNode->setNextLinkedNode(nullptr);
        currentTail->setPrevLinkedNode(nullptr);
        delete currentTail;
        std::cout << "Key " << key << " removed." << std::endl;
    }
    else
    {
        LinkedNode * currentNode = getHead();
        bool isFound(false);
    	while(currentNode->hasNextLinkedNode())
        {
            currentNode = currentNode->getNextLinkedNode();
            if(currentNode->getValue().getKey() == key)
            {
            	isFound = true;
                break;
            }
        }
        if(isFound)
        {
            if(currentNode->getNextLinkedNode() == nullptr)
        	{
                currentNode->setPrevLinkedNode(nullptr);
                currentNode->setNextLinkedNode(nullptr);
                delete currentNode;
            }

            currentNode->getPrevLinkedNode()->setNextLinkedNode(currentNode->getNextLinkedNode());
            currentNode->getNextLinkedNode()->setPrevLinkedNode(currentNode->getPrevLinkedNode());
            currentNode->setPrevLinkedNode(nullptr);
            currentNode->setNextLinkedNode(nullptr);

            delete currentNode;
            std::cout << "Key " << key << " removed." << std::endl;
        }
        else
        {

        }
    }
}

int DoublyLinkedList::find(int key)
{
	LinkedNode * find = getHead();
	while(find != nullptr)
	{
		if(find->getValue().getKey() == key)
		{
			//need to dereference in some way
			return find->getValue().getValue();
		}
		find = find->getNextLinkedNode();
	}
	return -1;
	delete find;
}

/*void DoublyLinkedList::insertAfterLinkedNode(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data, nullptr, nullptr);
	if(!isEmpty())
	{
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

}

void DoublyLinkedList::insertBeforeLinkedNode(LinkedNode * node, int data)
{
	if(!isEmpty())
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
}*/
