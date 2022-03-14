#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    return rand() % 100 + 1;
    srand(time(NULL));
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}


string getAnswer(int number, int randomNumber) {
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
   string answer;
   string answer;
    if(number>randomNumber) answer="Your number is higher.";
    else{
        if(number<randomNumber) answer= "Your number is lower.";
bool checkSuccess(string answer) {
    } else {
        check = false;
    }
    return true;
    return check;
}
