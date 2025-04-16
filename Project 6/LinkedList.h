//Assignment #4: Hop Dawg
//Linked List Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"
#include <iostream>

class LinkedList : public Node
{
	public:
		LinkedList(); //Constructor
		virtual ~LinkedList(); //Destructor
		bool isEmpty();
		int getLength();
		void insert(HashEntry element);
		void printList();
		bool findElement(int element);
		void removeNode(int element);

		LinkedNode * getHead();
		void setHead(LinkedNode * node);
		LinkedNode * getTail();
		void setTail(LinkedNode * node);

	private:
		LinkedNode * head_; //Must make getter and setter for this b/c it is private!
		LinkedNode * tail_;
		int size_;
};

#endif