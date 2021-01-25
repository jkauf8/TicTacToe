//
//  game.hpp
//  hw1-pic10b
//
//  Created by Justin Kaufman on 1/22/21.
//

#ifndef game_h
#define game_h

#include "person.h"
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Game{
public:
    Game(Person* playerOne, Person* playerTwo);
    void play();
    void displayBoard();
    bool win();
    bool full();
private:
    Person* player1;
    Person* player2;
    vector<string> row1;
    vector<string> row2;
    vector<string> row3;
    
    
};



#endif /* game_h */
