/*
Factorial_Calculator.cpp
Aug 19, 2017
Juan Casian
*/

#include <iostream>

using namespace std;

int TestPositiveValue (int TestValue){
  if (TestValue <= 0) {
    cout << "The value you entered is not a positive integer, please try again: "; cin >> TestValue;
    return TestPositiveValue (TestValue);
  } else {
    return TestValue;
  }
}

int Factorializing (int WorkingNumber){

  int Result;
  Result = WorkingNumber;
  WorkingNumber = WorkingNumber - 1;

  for (; WorkingNumber > 0; --WorkingNumber){
    Result = Result * WorkingNumber;
    // cout << "Stage Result: " << Result << " Working number: " << WorkingNumber << endl;      Used to test the loop to get the factorial value
  }

  return Result;

}

void ResultGiving (int Initial, int Final){

  cout << "The factorial result for " << Initial << " is " << Final << "." <<endl;

}

int RestartingProgram (){

  char Answer;
  cout << "Would you like to find another factorial? (Answer Y or N)"; cin >> Answer;

  if (Answer == 'Y' || Answer == 'y') {

    int RestartingInitialValue, RestartingFactorialValue;
    cout << "Please enter another positive integer: "; cin >> RestartingInitialValue;

    RestartingInitialValue = TestPositiveValue(RestartingInitialValue);
    RestartingFactorialValue = Factorializing(RestartingInitialValue);
    ResultGiving(RestartingInitialValue, RestartingFactorialValue);
    RestartingProgram();
    return 0;

  } else if (Answer == 'N' || Answer == 'n') {

    cout << "Thank you for your time! SHUTTING DOWN..." << endl;
    return 0;

  } else {
    cout << "The answer you gave is not Y or N. ";
    RestartingProgram();
    return 0;
  }

}

int main () {

  int InitialValue, FactorialValue;

  InitialValue = 0;
  FactorialValue = 0;

  cout << "This is a Factorial Calculator, please enter a positive integer: "; cin >> InitialValue;


  InitialValue = TestPositiveValue(InitialValue);

  //cout << InitialValue << endl;    Used to test TestPositiveValue function

  FactorialValue = Factorializing(InitialValue);

  ResultGiving (InitialValue, FactorialValue);

  // cout << "Prueba de continuacion de programa!!" << endl;   Test to see the program's flow


  RestartingProgram();

  // cout << "Shutting down test" <<endl;   Test to see if the program runed to this point
  return 0;

  }
