#include "board.h"
#include "player.h"
#include <limits>
#include <cstdlib>
#include <exception>
#include <string>

int Board::gamecount = 1;

void Board::continueGame()
{
    cout << "\n\n______________________________\n\n";
    cout << "----------GAME NO. " << gamecount << "----------\n\n";
    cout << "______________________________\n";
    gamecount+=1;
}

Board::Board(): board {'1', '2', '3', '4', '5', '6', '7', '8', '9'}
{
}

void Board::printBoard()
{
    cout << "\n" << "   |   |  " << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "___|___|__" << "\n";
    cout << "   |   |  " << "\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "___|___|__" << "\n";
    cout << "   |   |  " << "\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "   |   |  " << "\n\n";

}

int Board::checkWin()
{
    if(board[0]==board[1] && board[1]==board[2])
    {
        return 1;
    }
    if(board[3]==board[4] && board[4]==board[5])
    {
        return 1;
    }
    if(board[6]==board[7] && board[7]==board[8])
    {
        return 1;
    }
    if(board[0]==board[3] && board[3]==board[6])
    {
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7])
    {
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8])
    {
        return 1;
    }
    if(board[2]==board[4] && board[4]==board[6])
    {
        return 1;
    }
    if(board[0]==board[4] && board[4]==board[8])
    {
        return 1;
    }
    else
        return 0;
}


int Board::nooneWon()
{
    int check = 0;
    if(board[0]!='1' && board[1]!='2'  && board[2]!='3' && board[3]!='4' && board[4]!='5' && board[5]!='6' && board[6]!='7' && board[7]!='8' && board[8]!='9')
    {
        check = 1;
    }

    return check;
}


void Board::printWin(Player *player)
{
    cout << "\n\n---------------Congratulations " << player->name << "!" << " You've won!---------------\n";
}

void Board::markBoard(Player* player)
{
    int chosenNum = 1;
    bool check = true;

    while (check) {
        try {
            cout << player->name << ", pick a number from 1 to 9: ";
            cin >> chosenNum;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw CustomException("INVALID INPUT Please enter a number!");
            }

            if (chosenNum < 1 || chosenNum > 9) {
                throw CustomException("CHOOSE AN AVAILABLE NUMBER FROM 1 TO 9!");
            }

            if (board[chosenNum - 1] == 'X' || board[chosenNum - 1] == 'O') {
                throw CustomException("SPACE HAS ALREADY BEEN OCCUPIED Try again.");
            }

            board[chosenNum - 1] = player->chosen;
            check = false;
            system("CLS");
        } catch (const CustomException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

