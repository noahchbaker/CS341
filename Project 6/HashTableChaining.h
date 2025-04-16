//Assignment #6 - The Last Can Of Who Hash
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include "HashTable.h"
#include "DoublyLinkedList.h"
#include "HashEntry.h"

class HashTableChaining : public HashTable
{
	public:
		//Constructor and destructor
		HashTableChaining(int size);
		~HashTableChaining();

		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();

		//Accessors
		void setSize(int size);
		int getSize();
		void setEntry(DoublyLinkedList * entry);
		DoublyLinkedList * getEntry();

	private:
		DoublyLinkedList * entry_;
		int size_;
};

#endif