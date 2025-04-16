//Assignment #6 - The Last Can Of Who Hash
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include "HashTable.h"
#include "HashEntry.h"

class HashTableCuckoo : public HashTable
{
	public:
		//Constructor and destructor
		HashTableCuckoo(int size);
		~HashTableCuckoo();
		
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		
		//Accessors
		void setSize(int size); 
		int getSize(); 
		void setEntry1(HashEntry * entry1); 
		HashEntry * getEntry1(); 
		void setEntry2(HashEntry * entry2); 
		HashEntry * getEntry2(); 
		void setPlacement(bool placement);
		bool getPlacement();
	
	private: 
		HashEntry * entry_; //Table #1
		HashEntry * entry2_; //Table #2
		int size_;
		bool placement_;
};

#endif