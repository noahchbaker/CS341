//Assignment #6 - The Last Can Of Who Hash
//HashTableChaining Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "HashTableChaining.h"

HashTableChaining::HashTableChaining(int size) : HashTable(), size_(0)
{
	size_ = size;
	entry_ = new DoublyLinkedList[size_];

	for (int i = 0; i < size; i++)
	{
		//making everything empty
		entry_[i].getValue().setStatus(0);
	}
}

HashTableChaining::~HashTableChaining()
{
	delete [] entry_;
}

void HashTableChaining::insert(int key, int value)
{
	int hashProbing = key % size_;
	HashEntry newEntry (key,value);
	LinkedNode * newNode = new LinkedNode(newEntry, nullptr, nullptr);

	if(entry_[hashProbing].getHead() == nullptr)
	{
		entry_[hashProbing].insert(newEntry);
	}
	else
	{
		entry_[hashProbing].insertLinkedNode(entry_[hashProbing].getTail(), newEntry);
	}

	delete newNode;
}

int HashTableChaining::search(int key)
{
	int hashProbing = key % size_;
	if(entry_[hashProbing].getValue().getKey() == key)
	{
		return entry_[hashProbing].getValue().getValue();
	}
	else
	{
		entry_[hashProbing].find(key);
	}
}

void HashTableChaining::remove(int key)
{
	int hashProbing = key % size_;
	if(entry_[hashProbing].find(key) == -1)
	{
		std::cout << "Invalid key! " << key << " not found in table!" << std::endl;
	}
	else
	{
		entry_[hashProbing].removeLinkedNode(key);
	}
}

void HashTableChaining::print()
{
	std::cout << "***********************************" << std::endl;

	for(int i = 0; i < getSize(); i++)
	{
		std::cout << "[" << i << "]: ";
		entry_[i].printList();
	}

	std::cout << "***********************************" << std::endl;
}

void HashTableChaining::setSize(int size)
{
	size_ = size;
}

int HashTableChaining::getSize()
{
	return size_;
}

//this may not be needed but i could be wrong
void HashTableChaining::setEntry(DoublyLinkedList * entry)
{
	entry_ = entry;
}

DoublyLinkedList * HashTableChaining::getEntry()
{
	return entry_;
}
