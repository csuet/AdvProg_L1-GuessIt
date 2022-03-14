#include <bits/stdc++.h>
using namespace std;
int generateRandomNumber() {
	srand(time(NULL));
	return rand() % 100 + 1;
}
int getPlayerGuess() {
    int guess;
    cout <<  "Enter your guess (1..100): ";
    cin >> guess;
 	return guess;
}
string getAnswer(int number, int randomNumber) {
	string answer;
    if(number > randomNumber) answer = "Your number is higher.";
    else if(number < randomNumber) answer = "Your number is lower.";
    else answer = "Congratulation! You win.";
    return answer;
}

bool checkSuccess(string answer) {
    if(answer != "Congratulation! You win."){
    	return false;
	}
	return true;
}



bool checkContinuePlaying(char isContinued) {
    bool result = false;
	if(tolower(isContinued) == 'y') {
		result = true;
	}
    return result;
}


char getPlayerOpinion() {
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

int main() {
    srand(time(NULL));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
