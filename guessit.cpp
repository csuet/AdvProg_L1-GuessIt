#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


#include<iostream>
#include<stdlib.h>
#include<time.h>
 
using namespace std;
int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int guess,int secretNumber,int score);
int checkscore(int guess,int secretNumber,int &score);
int Playonegame();
bool askifcontinue(){int x;
	cout<<endl<<"Do you want to play a new game???"<<endl<<"Press 1 if you want or Press an another key to exit"<<endl;
	cin>>x;
	if(x==1) return true;
	else return false;
}
int run(){
	bool Playagain;
	do{
		Playonegame();
		Playagain=askifcontinue();
	}while(Playagain);
	return 0;
}
 
int Playonegame(){
	int score =100;
	cout<<"WELCOME TO GUESS It!"<<endl;
	cout<<"Your Score is 100 "<<endl;
    int guess;
 
int secretNumber = generateRandomNumber();
do{
    guess=getPlayerGuess();
    score=checkscore(guess,secretNumber,score);
    printAnswer(guess, secretNumber,score);
} 
while (guess!=secretNumber&&score>0); 
return 0;
}
int generateRandomNumber(){srand(time(NULL));
return rand()%100+1;
}
int getPlayerGuess(){
    int guess;
cout << endl << "Enter your guess (1..100): ";
cin >> guess;
return guess;
}
void printAnswer(int guess,int secretNumber,int score){
if (guess > secretNumber) {
cout << "Your number is too big." << endl;
cout << "Your score is "<<score << endl;
 
} else if (guess < secretNumber) {
cout << "Your number is too small." << endl;
cout << "Your score is "<<score << endl;
} else { 
cout << "Congratulation! You win." << endl;
 
}
}
int checkscore(int guess,int secretNumber,int &score){
	if(guess!=secretNumber) score=score-10;
	return score;	
}