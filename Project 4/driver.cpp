//Assignment #4: Hop Dawg
//Driver File
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include "Node.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"

int checkTailInsert(DoublyLinkedList * DLL, LinkedNode *& head, LinkedNode *& tail, int data, int tHops)
{
	if(data > tail->getValue() || data == tail->getValue())
	{
		return tHops;
	}
	else
	{
		//smaller than tail
		if(tail->getPrevLinkedNode() == nullptr)
		{
			return tHops;
		}
		tail = tail->getPrevLinkedNode();
		tHops++;
		tHops = checkTailInsert(DLL, head, tail, data, tHops);
	}

}

int checkHeadInsert(DoublyLinkedList * DLL, LinkedNode *& head, LinkedNode *& tail, int data, int hHops)
{
	if(data < head->getValue() || data == head->getValue())
	{
		return hHops;
	}
	else
	{
		//smaller than tail
		if(head->getNextLinkedNode() == nullptr)
		{
			return hHops;
		}
		head = head->getNextLinkedNode();
		hHops++;
		hHops = checkHeadInsert(DLL, head, tail,  data, hHops);
	}
}

void printFile(std::ostream & output, DoublyLinkedList * DLL)
{
	LinkedNode * temp = DLL->LinkedList::getHead();
	do
	{
		output << temp->getValue();
		temp = temp->getNextLinkedNode();

		if(temp!= nullptr)
		{
			output <<"<-->";
		}

	} while(temp != nullptr);

	output << std::endl;
}


int main()
{
	//Phase 1
	/*Initalize the node with a value then test printing it
	Node test(5);
	std::cout << test.getValue() << std::endl;

	//Set the initalized node to a new value then print it
	test.setValue(3);
	std::cout << test.getValue() << std::endl;*/

	//Phase 2
	/*LinkedList newList; //Initalize new LinkedList

	//Inserting Value into List
	newList.insert(15);
	newList.insert(7);
	newList.insert(10);*/

	//Printing LinkedList
	//newList.printList();

	//Get Length of LinkedList
	//std::cout << "Length:" << newList.getLength() << std::endl;

	//Phase 4
	//is this an okay way to declare newNode for the code
	/*LinkedNode * nNode = new LinkedNode(0, nullptr, nullptr); //Initalize new LinkedNode, needs to be head, then later not
	DoublyLinkedList * DLL = new DoublyLinkedList(); //Initalize new DoublyLinkedList

	//Inserting Value into List
	DLL->insertLinkedNode(nNode, 15);
	DLL->insertLinkedNode(nNode, 7);
	DLL->insertLinkedNode(nNode, 10);
	DLL->insertLinkedNode(nNode, 44);
	DLL->insertLinkedNode(nNode, 54);

	//Get Length of DoublyLinkedList
	std::cout << "Length: " << DLL->getLength() << std::endl;

	//Printing DoublyLinkedList
	DLL->printList();*/

	//Phase 5

	//make a dll with data.txt
	DoublyLinkedList * sortedDLL = new DoublyLinkedList();
	LinkedNode * newNode = new LinkedNode(0, nullptr, nullptr);
	int data = 0;

	//tail and head hops
	int tHops = 0;
	int hHops = 0;

	//counting total hops for sorted and data
	int sHops = 0;
	int dHops = 0;
	int nHops = 0;

	std::ifstream input;
	input.open("sorted.txt");
	if(input.is_open())
	{
		while(!input.eof())
		{
			input>>data;
			sortedDLL->insertLinkedNode(newNode, data);
		}
		input.close();
		input.clear();
	}

	//std::cout << "Length: " << sortedDLL->getLength() << std::endl;
	//sortedDLL->printList();

	LinkedNode * sHead = sortedDLL->LinkedList::getHead();
	LinkedNode * sTail = sortedDLL->LinkedList::getTail();

	//add insert.txt into sortedDLL which will hopefully be sorted
	input.open("inserts.txt");
	if(input.is_open())
	{
		while(!input.eof())
		{
			input>>data;
			tHops = 0;
			hHops = 0;

			//std::cout<<data<<std::endl;
			//std::cout<<std::endl;

			//calculate hops i hope!
			tHops = checkTailInsert(sortedDLL, sHead, sTail, data, tHops);
			hHops = checkHeadInsert(sortedDLL, sHead, sTail, data, hHops);

			//if statments to insert before/after
			if(tHops < hHops)
			{
				if(data == sHead->getValue())
				{
					sortedDLL->insertAfterLinkedNode(sHead, data);
					dHops = dHops + tHops +1;
				}
				sortedDLL->insertAfterLinkedNode(sTail, data);
				sHops = sHops + tHops;
			}
			else if(hHops < tHops)
			{
				//if equal always insert after.
				if(data == sHead->getValue())
				{
					sortedDLL->insertAfterLinkedNode(sHead, data);
					sHops = sHops + hHops + 1;
				}
				else
				{
					sortedDLL->insertBeforeLinkedNode(sHead, data);
					sHops = sHops + hHops;
				}
			}
			else
			{
				//if thops and hhops are equal
				sortedDLL->insertAfterLinkedNode(sTail, data);
				sHops = sHops + tHops;
			}

			sTail = sortedDLL->getTail();
			sHead = sortedDLL->getHead();
			//sortedDLL->printList();

		}
	}
	input.close();
	input.clear();
	//std::cout << "Length: " << sortedDLL->getLength() << std::endl;
	//sortedDLL->printList();


	DoublyLinkedList * dataDLL = new DoublyLinkedList();
	LinkedNode * DNode = new LinkedNode(0, nullptr, nullptr);
	data = 0;

	input.open("data.txt");
	if(input.is_open())
	{
		while(!input.eof())
		{
			input>>data;
			dataDLL->insertLinkedNode(DNode, data);
		}
		input.close();
		input.clear();
	}

	//std::cout << "Length: " << sortedDLL->getLength() << std::endl;
	//sortedDLL->printList();

	LinkedNode * dHead = dataDLL->LinkedList::getHead();
	LinkedNode * dTail = dataDLL->LinkedList::getTail();

	//add insert.txt into sortedDLL which will hopefully be sorted
	input.open("inserts.txt");
	if(input.is_open())
	{
		while(!input.eof())
		{
			input>>data;
			tHops = 0;
			hHops = 0;

			//std::cout<<data<<std::endl;
			//std::cout<<std::endl;

			//calculate hops i hope!
			tHops = checkTailInsert(dataDLL, dHead, dTail, data, tHops);
			hHops = checkHeadInsert(dataDLL, dHead, dTail, data, hHops);

			//if statments to insert before/after
			if(tHops < hHops)
			{
				if(data == dHead->getValue())
				{
					dataDLL->insertAfterLinkedNode(dHead, data);
					dHops = dHops + tHops + 1;
				}
				dataDLL->insertAfterLinkedNode(dTail, data);
				dHops = dHops + tHops;
			}
			else if(hHops < tHops)
			{
				//if equal always insert after.
				if(data == dHead->getValue())
				{
					dataDLL->insertAfterLinkedNode(dHead, data);
					dHops = dHops + hHops + 1;
				}
				else
				{
					dataDLL->insertBeforeLinkedNode(dHead, data);
					dHops = dHops + hHops;
				}
			}
			else
			{
				//if thops and hhops are equal insert at tail
				dataDLL->insertAfterLinkedNode(dTail, data);

				dHops = dHops + tHops;
			}

			dTail = dataDLL->getTail();
			dHead = dataDLL->getHead();
			//dataDLL->printList();
		}
	}
	input.close();
	input.clear();
	//std::cout << "Length: " << sortedDLL->getLength() << std::endl;
	//dataDLL->printList();

	std::ofstream output;
	//output.txt writing
	output.open("output.txt");
	printFile(output, dataDLL);
	output.close();
	output.clear();

	//sorted output wriitng
	output.open("sortedOutput.txt");
	printFile(output, sortedDLL);
	output.close();
	output.clear();

	//Readme writing
	output.open("README.txt");
	output << "Total Number of Big Dawg Hops for Sorted: " << sHops << std::endl;
	output << "Total Number of Big Dawg Hops for Randomized: " << dHops << std::endl;
	output.close();





	delete newNode;
	delete sortedDLL;
	delete DNode;
	delete dataDLL;

	//delete DLL;
	//delete newNode;

	return 0;
}
