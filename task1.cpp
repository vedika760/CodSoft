#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0));  
    int secretNumber = rand() % 100 + 1;  
    int guess;
    int attempts = 0;
    do {
        cout<<"Guess a number between 1 To 100: ";
        cin >> guess;

        attempts++;

        if (guess < secretNumber)
        {
            cout << "Too low next no.\n";
        } else if (guess > secretNumber) {
            cout << "Too high next no.\n";
        } else {
            cout << "YES! you guess the correct No. " ;
        }

    } while (guess != secretNumber);

    return 0;
}