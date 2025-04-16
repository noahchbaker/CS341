// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#include "Car.h"
#include <iostream>
#include <string>

std::string details;

//default car constructor so when I make a driver array, it doesnt need the data from indy500 immeditely
Car::Car()
{

}

// parameters needed to take the data from indy500 and place it into out driving array, after its been costrcuted with constructor above
Car::Car(std::string n, int s, int c, int l)
{
  name_ = n;
  speed_ = s;
  control_ = c;
  lapNumber_ = l;

}

//desconstructor
Car::~Car()
{

}

std::string Car::getName()
{
  return name_;
}
int Car::getSpeed()
{
  return speed_;
}
int Car::getControl()
{
  return control_;
}
int Car::getLapNumber()
{
  return lapNumber_;
}
void Car::setLapNumber(int l)
{
  lapNumber_ = l;
}

// Simulate race uses data from array, and according to control value returns the number of laps completed
int Car::simulateRace()
{
  //uses helper variables above
  control_ = getControl();
  speed_ = getSpeed();
  lapNumber_ = getLapNumber();

  //help on random would be appreciated, I feel like I made the random number generated poorly
  //these variables are re-initialized every time its run, which isnt efficent, would it be better for it to be initialized somewhere else?
  int random = (rand() % 10) + 1;
  int lapsPer = 0;
  int randomCon = 0;

  if (control_ > 5)
  {
    randomCon = control_ / random;
    lapsPer = randomCon + speed_;
    //after setting up the number of laps completed, we add it to our old lapNumber so less math is done in driver.cpp
    lapNumber_ = lapNumber_ + lapsPer;
    //std::cout << getName() << " " << "Control: " << control_ << " Speed: " << speed_ << " Random Control: " <<randomCon<< " Laps per turn: " << lapsPer << " Total Laps " << lapNumber_ << std::endl;
    return lapNumber_;
  }
  else
  {
    lapNumber_ = lapNumber_ + speed_;
    //std::cout << getName() << " " << lapNumber_ << std::endl;
    return lapNumber_;
  }
}

void Car::printInfo()
{
  //prints out each objects information, mine worked after file was closed in for loop
  //2 questions on this, is this a good way to print out object info, and how does this function work?
  //I dont understand how this can collect the correct name_, speed_, lapNumber_, without using getters in this function

  std::cout<< name_ << " " << speed_ << " " << control_ << " " << lapNumber_ << std::endl;
}
