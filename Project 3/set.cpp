//Set Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "set.h"

Set::Set(int size) : data_(size) //Constructor, uses Initialize list
{

}

Set::~Set() //Destructor
{

}

void Set::initialize(char * word, int size) //Initialize underlying BitArray
{
	data_.initialize(word, size);
}

int Set::getCardinality() const //Gets cardinality of set, i.e., represented by number of 1's in BitArray
{
	int cardinality = 0;
	int bitType;

	for(int i = 0; i < data_.length(); i++)
	{
		bitType = data_.get(i);
		if(bitType == 1)
		{
			cardinality++;
		}
		else
		{
			//nothing happens.
		}
	}
	return cardinality;
}

BitArray & Set::getData() //Returns reference to underlying BitArray
{
	return data_;
}

bool Set::setUnion(Set & B) //Computes union of current set (A) with set B
{
	//Use the OR bitwise operator, Check that length is the same before unioning, Use get8 and set8
	if(data_.length() == B.getData().length())
	{
		unsigned char a;
		unsigned char b;

		for(int i = 0; i < data_.bytes(); i++)
		{
			a = data_.get8(i*BIT_IN_BYTE); 
		 	b = B.data_.get8(i*BIT_IN_BYTE);

			a = a | b;
			data_.set8(a, i);
		}

		return true;
	}
	else
	{
		return false;
	}
}

bool Set::setIntersection(Set & B) //Computes intersection of current set (A) with set B
{
	if(data_.length() == B.getData().length())
	{
		unsigned char a;
		unsigned char b;

		for(int i = 0; i < data_.bytes(); i++)
		{
			a = data_.get8(i*BIT_IN_BYTE);
		 	b = B.data_.get8(i*BIT_IN_BYTE);

			a = a & b;
			data_.set8(a, i);
		}

		return true;
	}
	else
	{
		return false;
	}

}
