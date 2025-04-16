// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#include <iostream>
#include <fstream>
#include <string>
#include "Car.h"

int main()
{
  //main object variables
  std::string name;
  int speed;
  int control;

  //position variables and main driver array
  int i = 1;
  int size = 0;
  Car driving [33];

  // car object to add value to array of objects
  Car test;

  int lapNumber = 0;

  //ensures our random number is more random?
  srand(time(0));

  std::cout<< "***Welcome to the 2023 Indianapolis 500 Race!***"<<std::endl;
  std::cout<< std::endl;


  std::ifstream input("indy500.txt");
    if(input.is_open())
    {
      while(!input.eof())
      {
        //places name speed and control into their variables
        input >> name;
        input >> speed;
        input >> control;

        //Creates an object called test that uses the variables set up above and adds to a array of objects
        test = Car(name, speed, control, 0);
        driving[size++] = test;
        //size++ increases by 1 after line is completed so the next driver is at the next position in the array
      }
      input.close();
    }
    else
    {
      //nothing
    }

    //do while loop that runs through our array to calculate laps and update through simulate race
    do
    {
      //this allows us to continously update the same 33 drivers, without this we reach i = 34 which doesnt exist in our array
      if (i >= 33)
      {
        //prints racing out everytime we finish going through every racer once
        std::cout<<"***--> Racing... "<<std::endl;
        i = 0;
      }

      //calls simulate race which returns the calculated laps driver has completed, which is then set as the new lapnumber
      lapNumber = driving[i].simulateRace();
      driving[i].setLapNumber(lapNumber);

    }while(driving[i++].getLapNumber() < 200);
    //this i++ is in the while condition, because when it was in the loop, I wasnt able to check if a driver had reached 200
    //untill it looped around to said driver again, tell me if there is a better way because this looks convuluded to me

    //this puts the position variable back one so that we get the correct name of the driver
    i--;
    std::cout<< std::endl;
    std::cout<< "\t" << "***" << driving[i].getName()<<" has won the 2023 Indianapolis 500! *** " << std::endl;

    //driver cant go past 200 laps so this corrects for that
    driving[i].setLapNumber(200);
    std::cout<< std::endl;
    std::cout<< "Driver Name: Lap Number"<<std::endl;
    std::cout<< "***********************"<<std::endl;

    //sets position variable back at 0 and loops through all the drivers and their lap number
    for (i=0; i<33; i++)
    {
      std::cout<< driving[i].getName() << ":" << " " << driving[i].getLapNumber()<<std::endl;
      //if you want to test out printinfo function
      //driving[i].printInfo();
    }

    std::cout<< std::endl;
    std::cout<< "Thank you for using my race simulation program - goodbye!" <<std::endl;


    return 0;
}
