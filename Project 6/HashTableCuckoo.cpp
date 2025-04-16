//Assignment #6 - The Last Can Of Who Hash
//HashTableCuckoo Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "HashTableCuckoo.h"

HashTableCuckoo::HashTableCuckoo(int size) : HashTable(), size_(0)
{
	size_ = size;
	entry_ = new HashEntry[size_];
	entry2_ = new HashEntry[size_];

	for (int i = 0; i < size; i++)
	{
		//making everything empty
		entry_[i].setStatus(0);
		entry2_[i].setStatus(0);
	}
}

HashTableCuckoo::~HashTableCuckoo()
{
	delete [] entry_;
	delete [] entry2_;
}

void HashTableCuckoo::insert(int key, int value)
{
	int hashProbing1 = key % size_;
	int hashProbing2 = (key/size_) % size_;
	HashEntry newEntry(key, value);
	setPlacement(true);

	if(entry_[hashProbing1].getStatus() == 0) //empty
	{
		newEntry.setStatus(1);
		entry_[hashProbing1] = newEntry;
	}
	else if(entry_[hashProbing1].getStatus() == 1) //occupied
	{
		if(entry2_[hashProbing2].getStatus() == 1)
		{
			setPlacement(false);
			return;
		}
		else
		{
			HashEntry oldEntry(entry_[hashProbing1].getKey(), entry_[hashProbing1].getValue());
			entry_[hashProbing1].setStatus(2);

			entry_[hashProbing1] = newEntry;
			entry_[hashProbing1].setStatus(1);

			int oldEntryKey = oldEntry.getKey();
			hashProbing2 = (oldEntryKey/size_) % size_;

			entry2_[hashProbing2] = oldEntry;
			entry2_[hashProbing2].setStatus(1);
		}
	}
}

//will need to make a private helper to see if a cycle is present

int HashTableCuckoo::search(int key)
{
	int hashProbing1 = key % size_;
	int hashProbing2 = (key/size_) % size_;
	if(entry_[hashProbing1].getKey() == key)
	{
		return entry_[hashProbing1].getValue();
	}
	else if(entry2_[hashProbing2].getKey() == key)
	{
		return entry2_[hashProbing2].getValue();
	}
	else
	{
		return -1;
	}
}

void HashTableCuckoo::remove(int key)
{
	int hashProbing1 = key % size_;
	int hashProbing2 = (key/size_) % size_;
	if(entry_[hashProbing1].getKey() == key)
	{
		entry_[hashProbing1].setStatus(2);
		std::cout << "Key " << key << " removed." << std::endl;
	}
	else if(entry2_[hashProbing2].getKey() == key)
	{
		entry2_[hashProbing2].setStatus(2);
		std::cout << "Key " << key << " removed." << std::endl;
	}
	else
	{
		std::cout << "Invalid key! Key " << key << "not found in table!" << std::endl;
	}

}

void HashTableCuckoo::print()
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

	std::cout << "***********************************" << std::endl;
	for(int i = 0; i < getSize(); i++)
	{
		if(entry2_[i].getStatus() != 1)
		{
			std::cout << "[" << i << "]: " << std::endl;
		}
		else
		{
			std::cout << "[" << i << "]: " << entry2_[i].getKey() << std::endl;
		}
	}
	std::cout << "***********************************" << std::endl;
}

void HashTableCuckoo::setSize(int size)
{
	size_ = size;
}

int HashTableCuckoo::getSize()
{
	return size_;
}

void HashTableCuckoo::setEntry1(HashEntry * entry1)
{
	entry_ = entry1;
}

HashEntry * HashTableCuckoo::getEntry1()
{
	return entry_;
}

void HashTableCuckoo::setEntry2(HashEntry * entry2)
{
	entry2_ = entry2;
}

HashEntry * HashTableCuckoo::getEntry2()
{
	return entry2_;
}

void HashTableCuckoo::setPlacement(bool placement)
{
	placement_ = placement;
}

bool HashTableCuckoo::getPlacement()
{
	return placement_;
}
