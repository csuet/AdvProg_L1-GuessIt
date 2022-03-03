#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;



int generateRandomNumber() {
    int randomNumber = rand() % 100 + 1;
    return randomNumber;
}



int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
    int guess;
    cin >> guess;
    return guess;
}



string getAnswer(int number, int randomNumber) {
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;
    if(number > randomNumber)
    {
        answer= "Your number is higher." ;
    }
    else if(number < randomNumber)
    {
        answer= "Your number is lower." ;
    }
    else if(number == randomNumber){
        answer= "Congratulation! You win." ;
    }

    return answer;
}


bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    if(answer == "Your number is higher." || answer == "Your number is lower." )
    {
        return false;
    }
    else if(answer == "Congratulation! You win.")
    {
        return true;
    }
}



bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if(isContinued == 'y' || isContinued == 'Y')
    {
        result = true;
    }
    return result;
}



char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    cin >> isContinued;
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
