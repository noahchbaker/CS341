// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#include "card.h"
#include "standardDeck.h"
#define DECK_SIZE 52;


int main ()
{

    StandardDeck * Deck = new StandardDeck();
    StandardDeck * ptrPlayer1 = new StandardDeck();
    StandardDeck * ptrPlayer2 = new StandardDeck();
    StandardDeck * ptrBattleGround = new StandardDeck();

    int Player1Wins = 0;
    int Player2Wins = 0;

    int Player1Avg = 0;
    int Player2Avg = 0;

    Deck->initializeDeck();

    for (int i=0; i<50; i++)
    {
        Deck->shuffle();
        Deck->halfDeck(*ptrPlayer1, *ptrPlayer2);
        int winplaceholder = Deck->alternatePlay(*ptrPlayer1, *ptrPlayer2, *ptrBattleGround);
        if (winplaceholder == 1)
        {
            Player1Wins++;
        }
        else if (winplaceholder == 2)
        {
            Player2Wins++;
        }
        else
        {
            //space for rare ties
        }

        Player1Avg = Player1Avg + ptrPlayer1->getNumCards();
        Player2Avg = Player2Avg + ptrPlayer2->getNumCards();


        ptrPlayer1->emptyDeck(*ptrPlayer1);
        ptrPlayer2->emptyDeck(*ptrPlayer2);
        ptrBattleGround->emptyDeck(*ptrBattleGround);

    }
    if(Player1Wins > Player2Wins)
    {
        std::cout<< "Player 1 was the champion with " << Player1Wins << " victories versus Player 2." <<std::endl;
    }
    else if (Player2Wins > Player1Wins)
    {
        std::cout<< "Player 2 was the champion with " << Player2Wins << " victories versus Player 1." <<std::endl;
    }
    else
    {
        std::cout<< "Player 1 and 2 are both champions with " << Player1Wins << " Victories"<<std::endl;
    }
    std::cout << "Player 1 average score:   " << Player1Avg/50 << std::endl;
    std::cout << "Player 2 average score:   " << Player2Avg/50 << std::endl;

    std::cout << Player1Wins << " " << Player2Wins <<std::endl;

    // Phase 2 early test
    /*Card newcard = Card(1,1);

    std::cout << "Is the deck empty? ";
    std::cout << Deck->isEmpty() << std::endl;

    std::cout << "Number of Cards: ";
    std::cout << Deck->getNumCards() << std::endl;
    Deck->displayCard(14);*/

    //phase 3 early tests
    //test for addcard
    // Deck->initializeDeck();
    // Deck->printDeck();
    // Deck->shuffle();
    // Deck->printDeck();
    //std::cout << Deck->StandardDeck::addCard(newcard) << std::endl;

    //phase 4 early tests
    /*std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    Deck-> dealCard();
    Deck-> dealCard();
    Deck-> dealCard();*/

    delete Deck;
    delete ptrPlayer1;
    delete ptrPlayer2;
    delete ptrBattleGround;

    return 0;
}
