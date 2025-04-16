#include "dictionary.h"

Dictionary::Dictionary() : data_(DICTIONARY_SIZE)
{

}

//?
Dictionary::Dictionary (const Dictionary & dict) : data_(data_)
{

}

Dictionary::~Dictionary()
{
	if (lookupTable_ != nullptr)
	{
		delete [] lookupTable_;
	}
}
void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word, size);
}

int Dictionary::rank_range(int start, int end, int bit)
{
	int rank = 0;
	int bitType;

	//if rybar example is correct and we atsrt at 15th bit then do int i = (start+1)
	for(int i = start; i < end; i++)
	{
		bitType = data_.get(i);
		if(bitType == bit)
		{
			rank++;
		}
		else
		{
			//nothing happens.
		}
	}
	return rank;
}

int Dictionary::rank(int end, int bit)
{
	int rank = 0;
	int bitType;

	for(int i = 0; i < end; i++)
	{
		bitType = data_.get(i);
		if(bitType == bit)
		{
			rank++;
		}
		else
		{
			//nothing happens.
		}
	}
	return rank;
}

int Dictionary::select_range(int start, int end, int k, int bit)
{
	int positionOf = 0;
	int counter = 0;
	int bitType;

	for(int i = start; i<end; i++)
	{
		if(positionOf < k)
		{
			bitType = data_.get(i);
			if(bitType == bit)
			{
				counter++;
				positionOf++;
			}
			else
			{
				counter++;
				//nothing happens.
			}
		}
		else
		{
			return counter;
		}
	}
}

int Dictionary::select(int k, int bit)
{
	int positionOf = 0;
	int counter = 0;
	int bitType;

	for(int i = 0; i<data_.length(); i++)
	{
		if(positionOf < k)
		{
			bitType = data_.get(i);
			if(bitType == bit)
			{
				counter++;
				positionOf++;
			}
			else
			{
				counter++;
				//nothing happens.
			}
		}
		else
		{
			return counter;
		}
	}
}

//phase 5
void Dictionary::printLookupTable(std::ostream & output)
{

}
