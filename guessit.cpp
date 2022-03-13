#include<bits/stdc++.h>
#define For(i, x, y) for(int i = x; i <= y; i++)
#define Forn(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
int Number, Answer, PlayerGuess;
int generateRandomNumber()
{
    srand(time(0));
    int num = rand() % 100 + 1;
    return num;
}
int getPlayerGuess()
{
    int Guess;
    cout << "Enter your guess (1..100): ";
    cin >> Guess;
    return Guess;
}
bool Check(int PlayerGuess)
{
    PlayerGuess = getPlayerGuess();
    if(PlayerGuess > Number)
    {
        cout << "Your number is too big.";
        cout << endl << endl;
        return false;
    }
    if(PlayerGuess < Number)
    {
        cout << "Your number is too small.";
        cout << endl << endl;
        return false;
    }
    if(PlayerGuess == Number)
    {
        cout << "Congratulation! You win.";
        return true;
    }
}
int main()
{
    Number = generateRandomNumber();
    while( !Check(PlayerGuess) );
}
