#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;

int generateRandomNumber() {
    return 1 + rand() % 100;
}

int getPlayerGuess() {
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

string getAnswer(int number, int randomNumber) {
    string answer;
    if (number > randomNumber) {
        answer = "Your number is higher.";
    } else if (number < randomNumber) {
        answer = "Your number is lower.";
    } else answer = "Congratulation! You win.";
    return answer;
}

bool checkSuccess(string answer) {
    if(answer != "Congratulation! You win.") return false;
    return true;
}

bool checkContinuePlaying(char isContinued) {
    bool result = false;
    if(isContinued == 'Y' || isContinued == 'y') result = true;
    return result;
}

char getPlayerOpinion() {
    char isContinued;
    cout << "Do you want to continue playing? (Yes = Y / y, No = N / n): ";
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
