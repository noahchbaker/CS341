//Bit Array Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "bitarray.h"

//Phase 1
BitArray::BitArray(int size) //Constructor
{
	data_ = new char[BYTES];
	BYTES = size;
	LENGTH = BYTES * BIT_IN_BYTE;
}

BitArray::BitArray(const BitArray & array) : LENGTH(array.LENGTH), BYTES(array.BYTES) //Copy Constructor using Initialization List
{
	//data_ = new char[BYTES]; //Previous Copy Constructor Idea

	data_ = new char[LENGTH/BYTES]; //This creates a new char array of the SIZE of the other char array being copied in
	for(int i = 0; i < LENGTH/BYTES; i++)
	{
		data_[i] = array.data_[i];
	}
}

BitArray::~BitArray() //Destructor
{
	if (data_ != nullptr)
	{
		delete [] data_;
	}
}

bool BitArray::get(int position) const
{
	int bitarrayIndex = (position)/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;

	if ((data_[bitarrayIndex] & (1 << ((BIT_IN_BYTE-1) - position))) != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Phase 2
void BitArray::initialize(char * word, int size)
{
	BYTES = size;
	LENGTH = size * BIT_IN_BYTE;

	delete [] data_;
	data_ = new char[size];

	for(int i = 0; i < size; i++)
	{
		data_[i] = word[i];
	}
}

bool BitArray::flip(int position)
{
	int bitarrayIndex = (position)/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;

	data_[bitarrayIndex] ^= (1 << ((BIT_IN_BYTE-1) - position));

	return 1;
}

bool BitArray::set(int position, int bit)
{
	int bitarrayIndex = (position)/BIT_IN_BYTE;
	position = position%BIT_IN_BYTE;

	if(bit == 1)
	{
		data_[bitarrayIndex] |= (1 << ((BIT_IN_BYTE-1) - position));
	}
	else
	{
		data_[bitarrayIndex] &= ~(1 << ((BIT_IN_BYTE-1) - position));
	}

	return 1;
}

char BitArray::get8(int position) const
{
	int bitarrayIndex = (position)/BIT_IN_BYTE;
	return data_[bitarrayIndex];
}

void BitArray::complement()
{
	for(int i = 0; i < BYTES; i++)
	{
		data_[i] = ~data_[i];
	}
}

void BitArray::clear()
{
	for(int i = 0; i < BYTES; i++)
	{
		data_[i] = 0;
	}
}

void BitArray::print()
{
	std::cout << "|";

	for (int i = 0; i < BYTES; i++)
	{
		std::bitset<BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}

	std::cout << std::endl;
}

//Phase 3
void BitArray::set8(char c, int index)
{
	data_[index] = c;
}
