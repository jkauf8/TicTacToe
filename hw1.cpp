/*
    PIC 10B 1A, Homework 1
    Purpose: Tic-tac-toe game
    Author: Justin Kaufman
    Date: 1/21/2021
*/

#include <iostream>
#include <string>
#include "game.h"

using namespace std;

int main(int argc, const char * argv[]) {
//    vector<string> test;
//    test.push_back("uhj");
//    for(int i =0; i<test.size(); ++i){
//        cout<<test[i];
//    }
//
//    if(std::find(test.begin(),test.end(), "h") != test.end()){
//        cout<<"element found";
//    }
//    else{
//        cout<<"f";
//    }
    int numGames;
    int p1Score, p2Score;
    cout<<"Number of Games: ";
    cin>>numGames;

    if(!numGames){
        cout<<"Enter a valid input."<<endl;
    }

    string name1, name2;
    cout<<"Player 1 name: ";
    cin>>name1;
    cout<<"Player 2 name: ";
    cin>>name2;
    
    Person* player1= new Person(name1);
    Person* player2 = new Person(name2);
    for (int i=0; i<numGames; ++i){
        Game run = Game(player1, player2);
        run.play();
    }
    p1Score=player1->getScore();
    p2Score=player2->getScore();
    if(p1Score>p2Score){
        cout<<"Congratulations "<<name1<<". You won!"<<endl;
    }
    else if(p1Score<p2Score){
        cout<<"Congratulations "<<name2<<". You won!"<<endl;
    }
    else{
        cout<<"It's a draw."<<endl;
    }
    delete player1;
    delete player2;
    
    return 0;
}
