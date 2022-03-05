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
    return rand()%100+1;
}


/***
    Args:

    Returns:
        number (int) : the number that player guessed
***/
int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
    int a;
    cout<<"Your guess number: ";
    cin>>a;
    return a;
}


/***
    Args:
        number (int): answer number from player
        randomNumber (int): the true number
    Returns:
        answer (string) : answer of computer after checking result
***/
string getAnswer(int number, int randomNumber) {
    /***
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;
    if(number > randomNumber){
        answer = "Your number is higher.";
    }else if(number < randomNumber){
        answer = "Your number is lower.";
    }else answer = "Congratulation! You win.";
    return answer;
}


/***
    Args:
        answer (string): answer from computer after compare numbers
    Returns:
        result (bool) : player win or not
***/
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


/***
    Args:
        isContinued (char): player's choice
    Returns:
        result (bool) : continue playing or not
***/
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;
    if(isContinued=='y'||isContinued=='Y'){
        result=true;
    }
    return result;
}


/***
    Args:

    Returns:
        isContinues (char) : player's choice (continue playing or not)
***/
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    //int count_bad=0;
    char isContinued;
    cout<<"Do you want to cotinue play:"<<endl;
    cout<<"Yes(fill y) or No(fill n)"<<endl;

    do{
        /*if(count_bad>2){
            cout<<"Please chose 'y' or 'n'"<<endl;
        }*/
        cout<<"Your choice is :";
        cin>>isContinued;
        //count_bad++;
    }while(isContinued!='y'&&isContinued!='n'&&isContinued!='N'&&isContinued!='Y');
    //count_bad=0;
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

int run() {//run
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
