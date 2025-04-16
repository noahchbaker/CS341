//Assignment #6 - The Last Can Of Who Hash
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef HASHENTRY_H
#define HASHENTRY_H

class HashEntry 
{
	public:
        //Constructors and destructor
        HashEntry(int key, int value); 
		HashEntry(); //Default constructor
		~HashEntry();
		
		//Getters
		int getKey();
		int getValue();
		int getStatus();
		
		//Setters
		void setKey(int key);
		void setValue(int value);
		void setStatus(int status);
       
	private:
		int key_;
		int value_;
		int status_;
}; 

#endif