//Assignment #4: Hop Dawg
//Doubly Linked List Implementation
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList(); //Constructor
		virtual ~DoublyLinkedList(); //Destructor
		virtual void printList();
		void insertLinkedNode(LinkedNode * node, int data);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);

		//Phase 4
		int getLength();

	private:
		//LinkedNode * head_;
		//LinkedNode * tail_;
		int size_ = 0;
};

#endif
