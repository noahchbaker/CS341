//Assignment #5: Color Me Dawgs
//Driver File
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"


int main()
{
	//Phase 1 and 2
	//Open text file
	std::ifstream readFile("data.txt");
	std::string insertData;
	int stringData;

	RedBlackTree tree; //New instance of Binary Search Tree

	while(readFile >> insertData || !readFile.eof())
	{
		stringData = stoi(insertData);
		tree.insert(stringData);
	}

	//Closes text file
	readFile.close();

	std::cout<<"Red Nodes: ";
	tree.printRedNodes(tree.getRoot());
	std::cout << std::endl;
	std::cout<<"Black Nodes: ";
	tree.printBlackNodes(tree.getRoot());
	std::cout << std::endl;
	std::cout << "Root: " << tree.getRoot()->getData() << std::endl;

	return 0;
}
