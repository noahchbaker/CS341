// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#ifndef STANDARD_DECK_H
#define STANDARD_DECK_H

#include "card.h"

#define DECK_SIZE 52

/**
 * @class StandardDeck
 *
 * The StandardDeck class represents a standard deck of 52 cards.
 *
 */
class StandardDeck
{
	public:
		/// Default constructor.
		StandardDeck();

		//StandardDeck(const StandardDeck & sd);

		/// Default destructor.
		~StandardDeck();
		/**
	     * Returns True/False (1/0) whether or not the Deck is empty.
	     *
	     * @return          Boolean
	    */
		bool isEmpty();

		/**
	     * Returns the number of cards remaining in the deck.
	     *
	     * @return          Integer		value
	    */
		int getNumCards();

		/**
	     * Displays the i'th card in the Deck.
	     *
		 * @param[in]      Index
	    */
		void displayCard(int i);

		/**
	     * Prints the contents of the Deck. This method should call the
		 * print() method on each Card.
	    */
		void printDeck();

		bool addCard(Card c);
		void shuffle();
		bool mergeDecks(StandardDeck & newDeck, bool shuffle);
		void initializeDeck();

		Card dealCard();
		void halfDeck(StandardDeck & Player1, StandardDeck & Player2);
		int alternatePlay(StandardDeck & Player1_, StandardDeck & Player2_, StandardDeck & battleGround_);
		std::string getTopBattle();
		std::string getTopPlayer();
		void emptyDeck(StandardDeck & newDeck);

	protected:
		Card * deck_;	// Pointer to record the location of the array of Cards in memory.
		int numCards_;	// Stores the number of Cards currently in the deck.
};

#endif
