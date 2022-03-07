#include<iostream>
#include<cstdlib>
using namespace std;

int RandomNumber(){
    int randomnum= rand()%100 + 1;
    return randomnum;
   //return 45;
}
void GetPlayerName(){
    string s;
    cout<<"What is your name? ";
    cin>>s;
    cout<<"Hello "<<s<<endl;
    cout<<"Wellcome to GuessIt game. "<<endl;

}
int Playerguess(){
    int n;
    cout<<"Enter your number:";
    cin>>n;
    return n;
}
void print(int guess,int secertNumber){
    if(guess==secertNumber){

    }
    else if(guess<secertNumber){
        cout<<"Your number is too small,try again!"<<endl;
    }
    else if(guess>secertNumber){
        cout<<"Your number is too big,try again!"<<endl;
    }
}
void playerguessit(){
    int guess;
    int secertNumber=RandomNumber();
    int count=0;
    do{
        count++;
        guess=Playerguess();
        print(guess,secertNumber);
    }while(guess!=secertNumber);
    if(count>8){
        cout<<"You lose!"<<endl;
    }
    else{
        cout<<"Congratulation,You win"<<endl;
    }

}
void PlayAgain(){
    char continued;
    do {
        playerguessit();
        cout<<endl<<"Do you want to play again(y/n) ?: ";
        cin>>continued;

    }while(continued=='y'||continued=='Y');
}

int main(){
    srand(time(0));
    GetPlayerName();
    PlayAgain();
    return 0;
}
