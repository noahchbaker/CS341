//Assignment #6 - The Last Can Of Who Hash
//Driver File
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker

#include <iostream>
#include <fstream>
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include "HashTableCuckoo.h"

#define textFile "data3.txt"

int main()
{
	int key = 0;
	int value = 0;
	int firstMenuOption = 0;
	int secondMenuOption = 0;
	int userSize = 0;
	int enterKey = 0;
	int length = 0;
	bool tooSmall = false;


	std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
	do
	{
		std::cout << "1) Linear Probing" << std::endl;
		std::cout << "2) Quadratic Probing" << std::endl;
		std::cout << "3) Separate Chaining" << std::endl;
		std::cout << "4) Cuckoo Hashing" << std::endl;
		std::cout << "5) Quit Program" << std::endl;

		std::cout << "Please enter your choice: ";
		std::cin >> firstMenuOption;
		std::cout << std::endl;

		if(firstMenuOption == 1)
		{
			//HashTableArray - Linear
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> userSize;
			std::cout << std::endl;
			HashTableArray * Hash1 = new HashTableArray(userSize);
			Hash1->setMethod(true);

			std::ifstream readFile(textFile);
			if(readFile.is_open())
			{
				while(!readFile.eof())
				{
					if(length > userSize)
					{
						length = 0;
						break;
					}
					else
					{
						readFile >> key;
						readFile >> value;
						Hash1->insert(key, value);
						length++;
					}
				}
			}
			else
			{
				std::cout << "Invalid file name!" << std::endl;
			}

			length = 0;
			Hash1->print();
			readFile.close();
			readFile.clear();

			do
			{
				std::cout<<std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				std::cout << "Please enter your choice: ";

				std::cin >> secondMenuOption;
				std::cout << std::endl;

				if(secondMenuOption == 1)
				{
					//need case for if key is not in table
					std::cout << "Search (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					value = Hash1->search(enterKey);
					if(value == -1)
					{
						std::cout << "Invalid key! Key " << enterKey << " not found in table! " << std::endl;
					}
					else
					{
						std::cout << "Key: " << enterKey << "	Value: " << value << std::endl;
					}
				}
				else if(secondMenuOption == 2)
				{
					//need case where not in table
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					Hash1->remove(enterKey);
				}
				else if(secondMenuOption == 3)
				{
					Hash1->print();
				}
				else if(secondMenuOption == 4)
				{
					delete Hash1;
				}
				else
				{
					std::cout << "Invalid Entry!" << std::endl;
				}
			} while(secondMenuOption != 4);
		}
		else if(firstMenuOption == 2)
		{
			//HashTableArray - Quadratic
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> userSize;
			std::cout << std::endl;
			HashTableArray * Hash2 = new HashTableArray(userSize);
			Hash2->setMethod(false);


			std::ifstream readFile(textFile);
			if(readFile.is_open())
			{
				while(!readFile.eof())
				{
					if(length > userSize)
					{
						length = 0;
						break;
					}
					else
					{
						readFile >> key;
						readFile >> value;
						Hash2->insert(key, value);
						length++;
					}
				}
			}
			else
			{
				std::cout << "Invalid file name!" << std::endl;
			}

			length = 0;
			Hash2->print();
			readFile.close();
			readFile.clear();

			do
			{
				std::cout<<std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				std::cout << "Please enter your choice: ";

				std::cin >> secondMenuOption;
				std::cout << std::endl;

				if(secondMenuOption == 1)
				{
					//need case for if key is not in table
					std::cout << "Search (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					value = Hash2->search(enterKey);
					if(value == -1)
					{
						std::cout << "Invalid key! Key " << enterKey << " not found in table! " << std::endl;
					}
					else
					{
						std::cout << "Key: " << enterKey << "	Value: " << value << std::endl;
					}
				}
				else if(secondMenuOption == 2)
				{
					//need case where not in table
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					Hash2->remove(enterKey);
				}
				else if(secondMenuOption == 3)
				{
					Hash2->print();
				}
				else if(secondMenuOption == 4)
				{
					delete Hash2;
				}
				else
				{
					std::cout << "Invalid Entry!" << std::endl;
				}
			} while(secondMenuOption != 4);
		}
		else if(firstMenuOption == 3)
		{
			//HashTableChaining
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> userSize;
			std::cout << std::endl;
			HashTableChaining * HashChaining = new HashTableChaining(userSize);

			std::ifstream readFile(textFile);
			if(readFile.is_open())
			{
				while(!readFile.eof())
				{
					readFile >> key;
					readFile >> value;
					HashChaining->insert(key, value);
				}
			}
			else
			{
				std::cout << "Invalid file name!" << std::endl;
			}
			HashChaining->print();
			readFile.close();
			readFile.clear();

			do
			{
				std::cout<<std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				std::cout << "Please enter your choice: ";

				std::cin >> secondMenuOption;
				std::cout << std::endl;

				if(secondMenuOption == 1)
				{
					//need case for if key is not in table
					std::cout << "Search (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					value = HashChaining->search(enterKey);
					if(value == -1)
					{
						std::cout << "Invalid key! Key " << enterKey << " not found in table! " << std::endl;
					}
					else
					{
						std::cout << "Key: " << enterKey << "	Value: " << value << std::endl;
					}
				}
				else if(secondMenuOption == 2)
				{
					//need case where not in table
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					HashChaining->remove(enterKey);
				}
				else if(secondMenuOption == 3)
				{
					HashChaining->print();
				}
				else if(secondMenuOption == 4)
				{
					delete HashChaining;
				}
				else
				{
					std::cout << "Invalid Entry!" << std::endl;
				}
			} while(secondMenuOption != 4);
		}
		else if(firstMenuOption == 4)
		{
			//HashTableCuckoo
			std::cout << "Please enter the size of the Hash Table you wish to create: ";
			std::cin >> userSize;
			std::cout << std::endl;
			HashTableCuckoo * HashCuckoo = new HashTableCuckoo(userSize);

			std::ifstream readFile(textFile);
			if(readFile.is_open())
			{
				while(!readFile.eof())
				{
					readFile >> key;
					readFile >> value;

					length++;

					if(length > (userSize * 2) || userSize == 0)
					{
						std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
						HashCuckoo->setPlacement(false);
						break;
					}
					else
					{
						HashCuckoo->insert(key, value);
						if(HashCuckoo->getPlacement() == false)
						{
							std::cout << "Cycle Present - Rehash!" << std::endl;
							std::cout << "Key unpositioned: " << key << std::endl;
							std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
							break;
						}
					}
				}
			}
			else
			{
				std::cout << "Invalid file name!" << std::endl;
			}

			length = 0;
			readFile.close();
			readFile.clear();

			if(HashCuckoo->getPlacement() == true)
			{
				HashCuckoo->print();
			}
			else
			{
				std::cout<<std::endl;
				delete HashCuckoo;
				continue;
			}

			do
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				std::cout << "Please enter your choice: ";

				std::cin >> secondMenuOption;
				std::cout << std::endl;

				if(secondMenuOption == 1)
				{
					//need case for if key is not in table
					std::cout << "Search (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					value = HashCuckoo->search(enterKey);
					if(value == -1)
					{
						std::cout << "Invalid key! Key " << enterKey << " not found in table! " << std::endl;
					}
					else
					{
						std::cout << "Key: " << enterKey << "	Value: " << value << std::endl;
					}
				}
				else if(secondMenuOption == 2)
				{
					//need case where not in table
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> enterKey;
					std::cout << std::endl;
					HashCuckoo->remove(enterKey);

				}
				else if(secondMenuOption == 3)
				{
					HashCuckoo->print();
				}
				else if(secondMenuOption == 4)
				{
					delete HashCuckoo;
				}
				else
				{
					std::cout << "Invalid Entry!" << std::endl;
				}
			} while(secondMenuOption != 4);

		}
		else if(firstMenuOption == 5)
		{
			//nothing here
		}
		else
		{
			std::cout << "Invalid input, please try again!" << std::endl;
			std::cout << " " << std::endl;
		}
	} while(firstMenuOption != 5);

	std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;

	return 0;
}
