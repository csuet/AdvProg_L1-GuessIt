#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    return 100;
    return rand() % 100 + 1;
}


@@ -26,8 +26,8 @@ int generateRandomNumber() {
***/
int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number

    return 1;
    int pNumber; cin>>pNumber;
    return pNumber;
}


@@ -47,6 +47,13 @@ string getAnswer(int number, int randomNumber) {
    ***/
    string answer;

    if(number > randomNumber){
      answer = "Your number is higher.";
    }else if(number < randomNumber) {
      answer = "Your number is lower.";
    }else 
      answer = "Congratulation! You win.";

    return answer;
}

@@ -59,7 +66,10 @@ string getAnswer(int number, int randomNumber) {
***/
bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong

    if(answer != "Congratulation! You win.") {
      return false;
    }

    return true;
}

@@ -74,6 +84,10 @@ bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;

    if (isContinued == 'y' || isContinued == 'Y') { 
      result = true;
    }

    return result;
}

@@ -86,7 +100,7 @@ bool checkContinuePlaying(char isContinued) {
***/
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    char isContinued; cin>>isContinued;

    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
