// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#include "card.h"
#include "standardDeck.h"

#define DECK_SIZE 52

/// Default constructor.
StandardDeck::StandardDeck()
{
	deck_ = new Card[DECK_SIZE];
}

/*StandardDeck::StandardDeck(const StandardDeck & sd)
{
		numCards_ = sd.numCards_
		deck_ = new StandardDeck[numCards_];
		for (int i = 0; i<numCards_; i++)
		{
				deck_[i] = sd.deck_[i];
		}
}*/

// Default destructor.
StandardDeck::~StandardDeck()
{
	delete [] deck_;
}



bool StandardDeck::isEmpty()
{
	if(deck_ == nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int StandardDeck::getNumCards()
{
	return numCards_;
}

void StandardDeck::displayCard(int i)
{
	Card tester = deck_[i];
	std::cout << i << "th Card: " << tester.Card::print() << std::endl;
}

void StandardDeck::printDeck()
{
	for (int k=0; k<DECK_SIZE; k++)
	{
		Card test = deck_[k];
		std::cout<< test.Card::getFace() + " of " + test.Card::getSuit() << std::endl;
	}
}

bool StandardDeck::addCard(Card c)
{
	if(numCards_ <= DECK_SIZE)
	{
		deck_[numCards_++] = c;
		//std::cout<<"added card"<<std::endl;
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
}

void StandardDeck::shuffle()
{
	srand(time(0));
	for(int i = 0; i<3 ; i++)
	{
		for (int j = 0; j<numCards_; j++)
		{
			int random = (rand() % numCards_-1) + 1;
			Card cardRandom = deck_[random];
			Card cardReal = deck_[j];

			deck_[random] = cardReal;
			deck_[j] = cardRandom;
		}
	}
}

void StandardDeck::emptyDeck(StandardDeck & newDeck)
{
	for (int i = 0; i<DECK_SIZE ; i++)
	{
		newDeck.deck_[i] = Card(0,0);
		newDeck.numCards_ = 0;
	}
}

bool StandardDeck::mergeDecks(StandardDeck & newDeck, bool shuffle)
{
	int mergesize = newDeck.getNumCards() + numCards_;
	int counter = 0;
	if (mergesize <= DECK_SIZE)
	{
		for (int i = 0; i<newDeck.getNumCards(); i++)
		{
			deck_[i + numCards_] = newDeck.deck_[i];
			counter++;
		}
	}
	else
	{
		for (int i = 0; i<DECK_SIZE; i++)
		{
			deck_[i + numCards_] = newDeck.deck_[i];
			numCards_ = DECK_SIZE -1;
		}
	}
	numCards_ = (numCards_ + counter) -1;
	emptyDeck(newDeck);
	if(shuffle == 1)
	{
		//how to shuffle deck_?
		return 1;
	}
	else
	{
		return 1;
	}
	return 0;
}

void StandardDeck::initializeDeck()
{
	for(int i = 1; i<5; i++)
	{
		for(int j = 1; j<14; j++)
		{
			Card newcard (i,j);
			deck_ [numCards_++] = newcard;
		}
	}
}

Card StandardDeck::dealCard()
{
	Card battleCard;
	battleCard = deck_[numCards_--];
	//std::cout << battleCard.print() << "  Dealt Card"<<std::endl;
	return battleCard;
}


void StandardDeck::halfDeck(StandardDeck & Player1_, StandardDeck & Player2_)
{
	for (int i = 0; i<DECK_SIZE/2; i++)
	{
		Player1_.deck_[i]=deck_[i];
	}
	Player1_.numCards_=25;
	//std::cout<<std::endl;
	//Player1_.printDeck();

	int j = 0;
	//std::cout<<std::endl;

	for (int i = DECK_SIZE/2; i<DECK_SIZE; i++)
	{
		Player2_.deck_[j++]=deck_[i];
	}
	//Player2_.printDeck();
	Player2_.numCards_=25;
}

//special case for battleGround_
std::string StandardDeck::getTopBattle()
{
	Card topCardPlayer;
	topCardPlayer = deck_[numCards_-1];
	//std::cout<< topCardPlayer.print() << " Battle card top" <<std::endl;
	return topCardPlayer.getFace();
}

std::string StandardDeck::getTopPlayer()
{
	Card topCardBattle;
	topCardBattle = deck_[numCards_];
	//std::cout<< topCardBattle.print() << " Player card top"<<std::endl;
	return topCardBattle.getFace();
}


int StandardDeck::alternatePlay(StandardDeck & Player1_, StandardDeck & Player2_, StandardDeck & battleGround_)
{
	bool War1 = false;
	bool War2 = false;
	int win = 0;

	do
	{
		/*std::cout<<"New Round!"<<std::endl;
		std::cout<<Player1_.getNumCards()<<std::endl;
		std::cout<<Player2_.getNumCards()<<std::endl;
		std::cout<<battleGround_.getNumCards()<<std::endl;*/

		//checks if war will happen before it actually happens
		if (battleGround_.getTopBattle() == Player1_.getTopPlayer())
		{
			War1 = true;
			/*std::cout<<std::endl;
			std::cout<< " Player 1 Before War Win " << std::endl;
			Player1_.printDeck();*/
			Player1_.mergeDecks(battleGround_, 0);
			/*std::cout<< " Player 1 After War Win " << std::endl;
			Player1_.printDeck();
			std::cout<< " Player 1 After Shuffle War Win " << std::endl;*/
			Player1_.shuffle();
			//Player1_.printDeck();
			//std::cout<<std::endl;
			//std::cout<<Player1_.getNumCards()<<std::endl;
			//std::cout<<Player2_.getNumCards()<<std::endl;
			//std::cout<<battleGround_.getNumCards()<<std::endl;
		}
		else
		{
			battleGround_.addCard(Player1_.dealCard());
			//work around for game with no wars
			if(Player1_.getNumCards() == 0)
			{
				break;
			}
		}
		//War conditions for playing after getting reinforcements
		if (War1 == true)
		{
			battleGround_.addCard(Player1_.dealCard());
			War1 = false;
		}
		else
		{

		}

		if (battleGround_.getTopBattle() == Player2_.getTopPlayer())
		{
			War2 = true;
			/*std::cout<<std::endl;
			std::cout<< " Player 2 Before War Win " << std::endl;
			Player2_.printDeck();*/
			Player2_.mergeDecks(battleGround_, 0);
			/*std::cout<< " Player 2 After War Win " << std::endl;
			Player2_.printDeck();
			std::cout<< " Player 2 After Shuffle War Win " << std::endl;*/
			Player2_.shuffle();
			//Player2_.printDeck();
			//std::cout<<std::endl;
			//std::cout<<Player1_.getNumCards()<<std::endl;
			//std::cout<<Player2_.getNumCards()<<std::endl;
			//std::cout<<battleGround_.getNumCards()<<std::endl;
		}
		else
		{
			battleGround_.addCard(Player2_.dealCard());
			if(Player2_.getNumCards() == 0)
			{
				break;
			}
		}
		//War condiitons again
		if (War2 == true)
		{
			battleGround_.addCard(Player2_.dealCard());
			War2=false;
		}
		else
		{

		}


		//std::cout<<std::endl;
		//std::cout<< " Current Battleground end of turn " << std::endl;
		//battleGround_.printDeck();


	}while(Player1_.getNumCards() > 0 && Player2_.getNumCards() > 0);
	if(Player1_.getNumCards() > 0)
	{
		win = 1;
	}
	else if (Player2_.getNumCards() > 0)
	{
		 win = 2;
	}

	return win;
}
