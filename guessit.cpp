#include<bits/stdc++.h>
using namespace std;
***/
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
    return 100;
    return rand()%100+1;
}


int generateRandomNumber() {
***/
int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number

    return 1;
    int number;
	cout << "Enter your guess: "<< endl;
	cin >> number;
    return number;
}


string getAnswer(int number, int randomNumber) {
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
    string answer;
    if(number > randomNumber) {
    	answer = "Your number is highter.";
	} else if(number < randomNumber){
		answer = "Your number is lower.";
	} else answer = "Congratulation! You win.";

    return answer;
}
string getAnswer(int number, int randomNumber) {
***/
bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong

    return true;
    if(answer == "Congratulation! You win.") return true;
    return false;
}


bool checkSuccess(string answer) {
bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    bool result = false;

	if(isContinued == 'Y' || isContinued == 'y'){
		result = true;
	} else if(isContinued == 'n' || isContinued=='N'){
		result = false;
	}
    return result;
}

bool checkContinuePlaying(char isContinued) {
char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;

	cout << "Do you want to play again?" << endl;
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
