// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card()
{

}

Card::Card(int s, int f)
{
    suitVal_ = s;
    faceVal_ = f;
}

Card::~Card()
{

}

std::string Card::getSuit()
{
  return Card::SUIT[suitVal_];
}

std::string Card::getFace()
{
  return Card::FACE[faceVal_];
}

std::string Card::print()
{
  std::string pls = getFace() + " of " + getSuit();
  return pls;
}

void Card::initialize(int s, int f)
{
    suitVal_ = suitVal_;
    faceVal_ = faceVal_;
}
