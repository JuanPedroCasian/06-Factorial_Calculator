/*
Factorial_Calculator.cpp
Aug 19, 2017
Juan Casian
*/

#include <iostream>

using namespace std;

/* In this program we used the several functions to run in the main loop
*/

int TestPositiveValue (int TestValue){        /* This function test if the input value is positive, if not it
                                                  ask for a new Value and then reruns itself to test the given value again*/
  if (TestValue <= 0) {
    cout << "The value you entered is not a positive integer, please try again: "; cin >> TestValue;
    return TestPositiveValue (TestValue);     //This function calls itself but now with the new value
  } else {
    return TestValue;                   //After the value has been accepted it returns the correct value
  }
}

int Factorializing (int WorkingNumber){     /*This function does the actual calculation of the Factorial numbers
                                              going through a loop to multiply itself */

  int Result;
  Result = WorkingNumber;
  WorkingNumber = WorkingNumber - 1;        //Here I created the "WorkingNumber" variable to have something multiply my total to get the factorial

  for (; WorkingNumber > 0; --WorkingNumber){
    Result = Result * WorkingNumber;
    // cout << "Stage Result: " << Result << " Working number: " << WorkingNumber << endl;      Used to test the loop to get the factorial value
  }

  return Result;    //returns the total we worked on

}

void ResultGiving (int Initial, int Final){     //This functions seems stupid, but it helps to write less code in the second run

  cout << "The factorial result for " << Initial << " is " << Final << "." <<endl;

}

int RestartingProgram (){         /* This function ask to restart the program, but instead of rerunning main()
                                    it simply runs the other functions and itself so that it does not gives the entering message
                                    */

  char Answer;
  cout << "Would you like to find another factorial? (Answer Y or N)"; cin >> Answer;

  if (Answer == 'Y' || Answer == 'y') {         //If the answer is yes, it will run the same functions as the main program

    int RestartingInitialValue, RestartingFactorialValue;
    cout << "Please enter another positive integer: "; cin >> RestartingInitialValue;

    RestartingInitialValue = TestPositiveValue(RestartingInitialValue);
    RestartingFactorialValue = Factorializing(RestartingInitialValue);
    ResultGiving(RestartingInitialValue, RestartingFactorialValue);
    RestartingProgram();
    return 0;

  } else if (Answer == 'N' || Answer == 'n') {

    cout << "Thank you for your time! SHUTTING DOWN..." << endl; //If not it will end the current function and go back to main loop
    return 0;

  } else {
    cout << "The answer you gave is not Y or N. ";        //If the answer for user is not a option it will ask for the input again
    RestartingProgram();
    return 0;
  }

}

int main () {   /* In the main prgram there is not much to discuss, it just runs the functions
                    that were created before */

  int InitialValue, FactorialValue;

  InitialValue = 0;
  FactorialValue = 0;

  cout << "This is a Factorial Calculator, please enter a positive integer: "; cin >> InitialValue; //welcome message


  InitialValue = TestPositiveValue(InitialValue);   /*This runs the test, giving the value of "InitialValue" and after the
                                                      test is finished the return value will be the new "InitialValue"
                                                      */

  //cout << InitialValue << endl;    Used to test TestPositiveValue function

  FactorialValue = Factorializing(InitialValue);    /* This runs the Factorial calculation with the "InitialValue" and then
                                                      returns the value after the calculation, which is assigned to
                                                      "FactorialValue" */

  ResultGiving (InitialValue, FactorialValue);      //This only prints the results

  // cout << "Prueba de continuacion de programa!!" << endl;   Test to see the program's flow


  RestartingProgram();              /*This calls the rerunning function and if the user decides not to
                                      start again then it goes back to the main function*/

  // cout << "Shutting down test" <<endl;   Test to see if the program runed to this point
  return 0; //After the restarting program ends the main program ends too

  }
/****************** Note: Several printings have been done around the main loop and then they were put in comment.
                          This printings were used while writting the code to test if everything was wroking as expected
                          Later they were put in comment to keep a record of the testings that were made
                          ****************************/
