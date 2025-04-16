//Assignment #3: P'Bit'ty
//Driver File
//Honor Pledge:
//I pledge that I have neither given nor received any help on this assignment.
//avadella and ncbaker
#include "bitarray.h"
#include "dictionary.h"

int main()
{
	//Phase 1
	BitArray newBit(4);
	//std::cout << "Number of Bits: " << newBit.length() << std::endl;
	//std::cout << newBit.get(5) << std::endl;

	//Phase 2
	newBit.initialize("test", 4);
	newBit.print();

	//std::cout << newBit.get8(30) << std::endl;

	/*std::cout << "0th Bit Set: " << newBit.get(0) << std::endl;
	std::cout << "10th Bit Set: " << newBit.get(10) << std::endl;

	std::cout << " " << std::endl;

	std::cout << "Setting 0th position to 1..." << std::endl;
	newBit.set(0, 1);
	newBit.print();

	std::cout << "Setting 10th position to 0..." << std::endl;
	newBit.set(10, 0);
	newBit.print();

	std::cout << " " << std::endl;

	std::cout << "Complement: " << std::endl;
	newBit.complement();
	newBit.print();

	std::cout << "Flip: " << std::endl;
	newBit.flip(0);
	newBit.print();

	std::cout << " " << std::endl;

	std::cout << "Clear BitArray: " << std::endl;
	newBit.clear();
	newBit.print();*/

	//Phase 3
	//std::cout << " " << std::endl;

	//Initialize Set A and Set B
	/*Set A(4);
	A.initialize("Anna", 4);

	Set A2(4);
	A2.initialize("Anna", 4);

	Set B(4);
	B.initialize("Noah", 4);

	(A.getData()).print();
	(B.getData()).print();

	std::cout << " " << std::endl;

	//std::cout << A.getData().length() << std::endl; //Checking length of one set

	//Get Cardinality of Set A and Set B
	std::cout << "Cardinality of A: " << A.getCardinality() << std::endl;
	std::cout << "Cardinality of B: " << B.getCardinality() << std::endl;

	std::cout << " " << std::endl;

	//Get Union between Set A and Set B
	std::cout << "Set Union (A U B): " << std::endl;
	A.setUnion(B);
	(A.getData()).print();


	std::cout << " " << std::endl;

	//Get Intersection between Set A and Set B
	std::cout << "Set Intersection (A X B): " << std::endl;
	A2.setIntersection(B);
	(A2.getData()).print();*/

	Dictionary newDictionary;
	newDictionary.initialize("test", 4);

	std::cout<<"Rank: "<< newDictionary.rank(31,1) << std::endl;
	std::cout<<"Rank Range (15-31): "<< newDictionary.rank_range(15,31) << std::endl;
	std::cout<<"Select(5,1):  "<< newDictionary.select(5,1) << std::endl;
	std::cout<<"Select Range(0,15,2,1): "<< newDictionary.select_range(0,15,2,1) << std::endl;


	return 0;
}
