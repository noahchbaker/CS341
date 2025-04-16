//Assignment #6 - The Last Can Of Who Hash
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include "HashTable.h"
#include "HashEntry.h"

class HashTableArray : public HashTable
{
	public:
		//Constructor and Destructor
		HashTableArray(int size);
		~HashTableArray();

		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();

		//Accessors
		void setSize(int size);
		int getSize();
		void setEntry(HashEntry * entry);
		HashEntry * getEntry();
		void setMethod(bool method);
		bool getMethod();

	private:
		HashEntry * entry_;
		int size_;
		bool method_;
};

#endif