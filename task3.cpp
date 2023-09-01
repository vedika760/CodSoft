#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include<ctime>

using namespace std;

#define Dimension 3

class player 
{
private:
    string name;
public:
    player(string n) 
    {
        name = n;
    }
        string PlayerName() 
    {
        return this->name;
    }
};
class Game 
{
private:
    char gameboard[Dimension][Dimension];
    int count;
public:
    Game() 
    {
        count = 0;
    }
    void CreateBoard() 
    {
        for (int i = 0; i < Dimension; i++) 
        {
            for (int j = 0; j < Dimension; j++)
                gameboard[i][j] = ' ';
        }
        showBoard();
    }
    void showBoard() 
    {
        printf("\n\n");
        for (int i = 0; i < Dimension; i++) 
        {
            cout << "\t\t\t";
            for (int j = 0; j < Dimension; j++)
                cout << "|" << gameboard[i][j];
            cout << "|\n\t\t\t-------" << endl;
        }
    }
    void PlayerTurn(player &player) 
    {
        int position;
        int row;
        cout << "Turn of " << player.PlayerName() << ":" << endl;
        cout << "Enter the position to be marked : ";
        cin >> position;
        row = ceil((float)position / Dimension);
        int col = (position - 1) % Dimension;
        if (gameboard[row - 1][col] != ' ') 
        {
            cout << "This position is already marked" << endl;
            PlayerTurn(player);
        } else 
        {
            gameboard[row - 1][col] = (player.PlayerName() == "Player 1") ? 'X' : 'O';
            cout << "Marked at position: " << position << endl;
            count++;
        }
        showBoard();
    }
    string CheckWin() 
    {
        int r1 = 0, r2 = 0;
        int c1 = 0, c2 = 0;
        int d1 = 0, d2 = 0;
        char x = 'X';
        char o = 'O';
        for (int i = 0; i < Dimension; i++) 
        {
            r1 = 0;
            r2 = 0;
            c1 = 0;
            c2 = 0;
            if (gameboard[i][i] == x) 
            {
                d1++;
            } else if (gameboard[i][i] == o) 
            {
                d2++;
            }
            for (int j = 0; j < Dimension; j++) 
            {
                if (gameboard[i][j] == x) 
                {
                    r1++;
                } else if (gameboard[i][j] == o) 
                {
                    r2++;
                }
                if (gameboard[j][i] == x) 
                {
                    c1++;
                } else if (gameboard[j][i] == o) 
                {
                    c2++;
                }
            }
            if (r1 == Dimension || r2 == Dimension) 
            {
                return (r1 == Dimension) ? "Player 1" : "Player 2";
            } else if (c1 == Dimension || c2 == Dimension) 
            {
                return (c1 == Dimension) ? "Player 1" : "Player 2";
            }
        }
        if (d1 == Dimension || d2 == Dimension) 
        {
            return (d1 == Dimension) ? "Player 1" : "Player 2";
        }
        if (count == Dimension * Dimension) 
        {
            return "draw";
        }
        return "";
    }
};
int main() 
{
    srand(time(NULL));

    Game *game = new Game;
    int ch;
    game->CreateBoard();
    cout << "Press 2 for two-player game: ";
    cin >> ch;
    string fin = "";
    bool flag = true;
    player player1("Player 1"); 
    player player2("Player 2"); 
    while (flag) 
    {
        game->PlayerTurn(player1);
        fin = game->CheckWin();
        if (fin != "") 
        {
            break;
        }
        game->PlayerTurn(player2);
        fin = game->CheckWin();
        if (fin == "Player 1") 
        {
            cout << "Congrats! Player 1 wins";
            flag = false;
        } else if (fin == "Player 2") 
        {
            cout << "Congrats! Player 2 wins";
            flag = false;
        } else if (fin == "draw") 
        {
            cout << "The game ended in a draw";
            flag = false;
        }
    }
    return 0;
}