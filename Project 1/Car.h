// Honor Pledge:
//
// I pledge that I have neither given nor
// received any help on this assignment.
//
// ncbaker

#include <string>

class Car
{
  public:
    Car();
    Car(std::string n, int s, int c, int l);
    ~Car();

    void printInfo();
    std::string getName();
    int getSpeed();
    int getControl();
    int getLapNumber();
    void setLapNumber(int l);
    int simulateRace();
    
  private:
    std::string name_;
    int speed_;
    int control_;
    int lapNumber_;
};
