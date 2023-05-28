#include "player.h"
#include "board.h"

Player::Player(string n="1", char c='X', int p=0)
    {
        cout << "Player " << n << ":\nSet your nickname: ";
        cin >> n;
        name = n;
        cout << "Your nickname has been set properly to " << n << "!";
        cout << "\n\n";
        chosen=c;
    }

void Player::addPoints()
{
    points+=1;
}

void Player::Points()
{
    cout << "\n" << name << " POINTS: " << points << "\n";
}
