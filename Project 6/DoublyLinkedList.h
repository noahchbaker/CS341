//Assignment #6 - The Last Can Of Who Hash
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
		void insertLinkedNode(LinkedNode * node, HashEntry entry);
		void insertAfterLinkedNode(LinkedNode * node, int data);
		void insertBeforeLinkedNode(LinkedNode * node, int data);

		//Phase 4
		int getLength();

		//Assignment #6 addition
		void removeLinkedNode(int key);
		int find(int key);

	private:
		int size_ = 0;
};

#endif