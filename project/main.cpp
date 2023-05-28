#include <iostream>
#include "board.h"
#include "player.h"
#include <string>
using namespace std;

int main()
{
    cout << "________________________________\n\n";
    cout << "---Welcome to TIC TAC TOE !!!---\n\n";
    cout << "________________________________\n\n";

    system("pause");
    system("CLS");

    Player player1("1", 'X', 0);
    Player player2("2", 'O', 0);

    system("pause");
    system("CLS");

    Player *wsk1 = &player1;
    Player *wsk2 = &player2;
    int turn = 1;
    int cont = 0;

    while(true){
        Board myBoard;

        if(cont==0)
        {
            myBoard.continueGame();
        }

        cont=1;
        myBoard.printBoard();
        int whowon = 0;

        if(turn%2==0){
            wsk1 = &player2;
            wsk2 = &player1;
        }

        if(turn%2!=0){
            wsk1 = &player1;
            wsk2 = &player2;
        }

        turn+=1;

        while(true){
            myBoard.markBoard(&(*wsk1));
            myBoard.printBoard();

            if(myBoard.checkWin()==1)
            {
                myBoard.printWin(&(*wsk1));
                whowon = 1;
                break;
            }
            cout << "\n_____________________________\n\n\n";

            if(myBoard.nooneWon()==1)
            {
                cout << "NOONE WON!\n---------------GAME OVER---------------\n";
                break;
            }

            myBoard.markBoard(&(*wsk2));
            myBoard.printBoard();

            if(myBoard.checkWin()==1)
            {
                myBoard.printWin(&(*wsk2));
                whowon = 2;
                break;
            }

            if(myBoard.nooneWon()==1)
            {
                cout << "NOONE WON!\n---------------GAME OVER---------------\n";
                break;
            }

            cout << "\n_____________________________\n\n\n";
        }

        string y = "";

        if(whowon==1)
        {
            wsk1->addPoints();
            wsk1->Points();
            wsk2->Points();
            cout << "\n" << wsk2->Name() << " are you ready for REVENGE?\n";
        }

        if(whowon==2)
        {
            wsk2->addPoints();
            wsk1->Points();
            wsk2->Points();
            cout << "\n" << wsk1->Name() << " are you ready for REVENGE?\n";
        }

        if(whowon==0)
        {
            cout << "\nAre you ready for another game?\n";
        }

        cout << "Type: \n ""y"" - Yes or anything - No: ";
        cin >> y;

        if(y!="y")
        {
            cout << "\nSee you in another game next time!\n";
            break;
        }
        else
        {
            system("CLS");
            myBoard.continueGame();
        }

    }
}
