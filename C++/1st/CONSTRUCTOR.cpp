// Demonstrates declaration of a constructor and destructor for the Cat class
#include <iostream>
using namespace std;
class Cat                // begin declaration of the class
{
    int itsAge;
    public:                 // begin public section
        Cat(int );          // constructor
        ~Cat();             // destructor
        int GetAge();       // accessor function
        void SetAge(int );  // accessor function
        void Meow();
};
// constructor of Cat,
Cat::Cat(int initialAge){
    itsAge = initialAge;
}
// destructor, takes no action
Cat::~Cat(){
}
// GetAge, Public accessor function
// returns value of itsAge member
int Cat::GetAge(){
    return itsAge;
}
// Definition of SetAge, public
// accessor function
void Cat::SetAge(int age){
    // set member variable itsAge to
    // value passed in by parameter age
    itsAge = age;
}
  // definition of Meow method
  // returns: void
  // parameters: None
  // action: Prints “meow” to screen
void Cat::Meow(){
    cout << "Meow.\n";
}
// create a cat, set its age, have it
// meow, tell us its age, then meow again.
int main()
{
      Cat Frisky(5);//constructor with a argument
      Frisky.Meow();
      cout << "Frisky is a cat who is " ;
      cout << Frisky.GetAge() << " years old.\n";
      Frisky.Meow();
      Frisky.SetAge(7);
      cout << "Now Frisky is " ;
      cout << Frisky.GetAge() << " years old.\n";
      return 0;
}
//There is no need to call SetAge(), because Frisky was created
//with the value 5 in its member variable itsAge, as shown in line 47.
