//Assignment #6 - The Last Can Of Who Hash
//HashEntry Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "HashEntry.h"

HashEntry::HashEntry(int key, int value) //Constructor
{
	key_ = key;
	value_ = value;
	status_ = 0;
}

HashEntry::HashEntry() //Default Constructor, in case of setting key and value after construction
{
	status_ = 0;
} 

HashEntry::~HashEntry() //Destructor
{
	
}

int HashEntry::getKey()
{
	return key_;
} 
		
int HashEntry::getValue()
{
	return value_;
} 

int HashEntry::getStatus()
{
	return status_;
} 

void HashEntry::setKey(int key)
{
	key_ = key;
} 

void HashEntry::setValue(int value)
{
	value_ = value;
} 

void HashEntry::setStatus(int status)
{
	status_ = status;
} 