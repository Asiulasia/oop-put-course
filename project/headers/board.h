#include <iostream>
using namespace std;

class Player;

class Board
{
private:
    char board[9];
public:
    static int gamecount;
    Board();
    void printBoard();
    void continueGame();
    void markBoard(Player *player);
    int checkWin();
    void printWin(Player *player);
    int nooneWon();
    friend class Player;
};

class CustomException : public exception {
private:
    string errorMessage;

public:
    CustomException(const string& message) : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};
