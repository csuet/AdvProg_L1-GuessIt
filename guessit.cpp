#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"



/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    ///std::srand is called the first time this function is called
    //static auto oneTimeSrandInvoke = (std::srand(std::time(nullptr)), 0);
    return std::rand() % 100 + 1;
}


/***
    Args:
        
    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    std::cout << "Enter your guess: ";
    int number;
    std::cin >> number;
    return number;
}


const std::string HIGHER_MESSAGE = "Your number is higher.";
const std::string LOWER_MESSAGE = "Your number is lower.";
const std::string WIN_MESSAGE = "Congratulation! You win.";

/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
std::string getAnswer(int number, int randomNumber) {
    if (number > randomNumber)
        return HIGHER_MESSAGE;
    if (number < randomNumber)
        return LOWER_MESSAGE;
    return WIN_MESSAGE;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
bool checkSuccess(std::string answer) {
    return answer == WIN_MESSAGE;
}


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    bool result = false;
    if (isContinued == 'y' || isContinued == 'Y')
        result = true;
    return result;
}


/***
    Args:
        
    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    char isContinued;
    std::cout << "Do you want to continue playing? (y/n) ";
    std::cin >> isContinued;
    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    std::string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        std::cout << answer << std::endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(nullptr));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
