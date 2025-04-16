//Assignment #6 - The Last Can Of Who Hash
////HashTableArray Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

//cuckoo and array is both arrays
//chaining is array of douubly linked lists of entry_;

#include "HashTableArray.h"

HashTableArray::HashTableArray(int size) : HashTable(), size_(0)
{
	size_ = size;
	entry_ = new HashEntry[size];

	for (int i = 0; i < size; i++)
	{
		//making everything empty
		entry_[i].setStatus(0);
	}
}

HashTableArray::~HashTableArray()
{
	if(entry_ != nullptr)
	{
		delete [] entry_;
	}
}

void HashTableArray::insert(int key, int value)
{
	int hashProbing = key % size_;
	HashEntry newEntry(key, value);
	int n = 0;

	if(getMethod() == true) //Linear Probing
	{
		if(entry_[hashProbing].getStatus() == 0) //0 = Empty
		{
			entry_[hashProbing] = newEntry;
			entry_[hashProbing].setStatus(1);
		}
		else
		{
			for(int i = 0; i < getSize(); i++)
			{
				int hashCollision = (hashProbing+i) % size_;
				if(entry_[hashCollision].getStatus() == 0)
				{
					entry_[hashCollision] = newEntry;
					entry_[hashCollision].setStatus(1);
					break;
				}
			}

		}
	}
	else
	{
		if(entry_[hashProbing].getStatus() == 0) //0 = Empty
		{
			entry_[hashProbing] = newEntry;
			entry_[hashProbing].setStatus(1);
		}
		else
		{
			for(int i = 0; i < getSize(); i++)
			{
				int hashCollision = (hashProbing + (i*i)) % size_;
				if(entry_[hashCollision].getStatus() == 0)
				{
					entry_[hashCollision] = newEntry;
					entry_[hashCollision].setStatus(1);
					break;
				}
			}
		}
	}

}

int HashTableArray::search(int key)
{
	//does not work if we remove for linear probing case
	int hashProbing = key % size_;
	int n = 0;

	// 1 is occupied, 0 is empty, 2 is removed
	if(getMethod() == true)
	{
		if(entry_[hashProbing].getKey() == key && entry_[hashProbing].getStatus() == 1)
		{
			return entry_[hashProbing].getValue();
		}
		else
		{
			for(int i = 0; i<getSize(); i++)
			{
				int hashCollision = (hashProbing+i) % size_;
				if(entry_[hashCollision].getKey() == key && entry_[hashCollision].getStatus() == 1)
				{
					return entry_[hashCollision].getValue();
				}
			}
			return -1;
		}
	}
	else
	{
		if(entry_[hashProbing].getKey() == key && entry_[hashProbing].getStatus() == 1)
		{
			return entry_[hashProbing].getValue();
		}
		else
		{
			for(int i = 0; i<getSize(); i++)
			{
				int hashCollision = (hashProbing + (i*i)) % size_;
				if(entry_[hashCollision].getKey() == key && entry_[hashCollision].getStatus() == 1)
				{
					return entry_[hashCollision].getValue();
				}
			}
			return -1;
		}
	}
}

void HashTableArray::remove(int key)
{
	int hashProbing = key % size_;
	int n = 0;

	if(getMethod() == true)
	{
		if(entry_[hashProbing].getKey() == key)
		{
			entry_[hashProbing].setStatus(2); //2 = removed
			std::cout << "Key " << key << " removed." << std::endl;
		}
		else
		{
			for(int i = 0; i < getSize(); i++)
			{
				int hashCollision = (hashProbing + i) % size_;
				if(entry_[hashCollision].getKey() == key && entry_[hashCollision].getStatus() == 1)
				{
					entry_[hashCollision].setStatus(2);
					std::cout << "Key " << key << " removed." << std::endl;
					return;
				}
			}
			std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
		}
	}
	else
	{
		if(entry_[hashProbing].getKey() == key)
		{
			entry_[hashProbing].setStatus(2); //2 = removed
			std::cout << "Key " << key << " removed." << std::endl;
		}
		else
		{
			for(int i = 0; i < getSize(); i++)
			{
				int hashCollision = (hashProbing + (i * i)) % size_;
				if(entry_[hashCollision].getKey() == key && entry_[hashCollision].getStatus() == 1)
				{
					entry_[hashCollision].setStatus(2);
					std::cout << "Key " << key << " removed." << std::endl;
					return;
				}
			}
			std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
		}
	}
}

void HashTableArray::print()
{
	std::cout << "***********************************" << std::endl;

	for(int i = 0; i < getSize(); i++)
	{
		if(entry_[i].getStatus() != 1)
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
		else
		{
			std::cout << "[" << i << "]: " << entry_[i].getKey() << std::endl;
		}
	}

	std::cout << "***********************************" << std::endl;
}

void HashTableArray::setSize(int size)
{
	size_ = size;
}

int HashTableArray::getSize()
{
	return size_;
}

void HashTableArray::setEntry(HashEntry * entry)
{
	entry_ = entry;
}

HashEntry * HashTableArray::getEntry()
{
	return entry_;
}

void HashTableArray::setMethod(bool method)
{
	method_ = method;
}

bool HashTableArray::getMethod()
{
	return method_;
}
