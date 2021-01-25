//
//  game.cpp
//  hw1-pic10b
//
//  Created by Justin Kaufman on 1/22/21.
//

#include "game.h"
#include <iostream>
using namespace std;



Game::Game(Person* playerOne, Person* playerTwo){
    player1=playerOne;
    player2=playerTwo;
}

bool Game::win(){
    bool winning;
    string current,current1,current2;
    winning =false;
    // across
    current = row1[2];
    if((current[5]=='X' && current[13]=='X' && current[21]=='X')||(current[5]=='O' && current[13]=='O' && current[21]=='O')){
        winning = true;
    }
    current = row2[2];
    if((current[5]=='X' && current[13]=='X' && current[21]=='X')||(current[5]=='O' && current[13]=='O' && current[21]=='O') ){
        winning = true;
    }
    current = row3[2];
    if((current[5]=='X' && current[13]=='X' && current[21]=='X')||(current[5]=='O' && current[13]=='O' && current[21]=='O') ){
        winning = true;
    }
    
    //up/down
    current = row1[2];
    current1=row2[2];
    current2=row3[2];
    if((current[5]=='X' && current1[5]=='X' && current2[5]=='X')||(current[5]=='O' && current1[5]=='O' && current2[5]=='O') ){
        winning = true;
    }
    current = row1[2];
    current1=row2[2];
    current2=row3[2];
    if((current[13]=='X' && current1[13]=='X' && current2[13]=='X')||(current[13]=='O' && current1[13]=='O' && current2[13]=='O') ){
        winning = true;
    }
    current = row1[2];
    current1=row2[2];
    current2=row3[2];
    if((current[21]=='X' && current1[21]=='X' && current2[21]=='X')||(current[21]=='O' && current1[21]=='O' && current2[21]=='O') ){
        winning = true;
    }
    
    //diagonal
    current = row1[2];
    current1=row2[2];
    current2=row3[2];
    if((current[5]=='X' && current1[13]=='X' && current2[21]=='X')||(current[5]=='O' && current1[13]=='O' && current2[21]=='O') ){
        winning = true;
    }
    current = row1[2];
    current1=row2[2];
    current2=row3[2];
    if((current2[5]=='X' && current1[13]=='X' && current[21]=='X')||(current2[5]=='O' && current1[13]=='O' && current[21]=='O') ){
        winning = true;
    }
    return winning;
}

bool Game::full(){
    bool done;
    string at, at1, at2;
    done=false;
    
    at=row1[2];
    at1=row2[2];
    at2=row3[2];
    if((at[5]=='X' || at[5]=='O') && (at[13]=='X' || at[13]=='O') && (at[21]=='X' || at[21]=='O')){
        if((at1[5]=='X' || at1[5]=='O') && (at1[13]=='X' || at1[13]=='O') && (at1[21]=='X' || at1[21]=='O')){
           if((at2[5]=='X' || at2[5]=='O') && (at2[13]=='X' || at2[13]=='O') && (at2[21]=='X' || at2[21]=='O')){
               done = true;
           }
        }
    }
    else{
        done=false;
    }
    
    return done;
}

void Game::play(){
    int x,y;
    bool alreadyThere = false;
    int p1Score, p2Score;
    string name1=player1->getName();
    string name2= player2->getName();
    cout<<endl;
    cout<<"     Tic Tac Toe     "<<endl;
    cout<<" "+ name1 + " (X)"+ "  -  "+ name2+" (O)"<<endl;
    cout<<endl;
    row1.push_back("     1       2       3   ");
    row1.push_back("         |       |       ");
    row1.push_back("1        |       |       ");
    row1.push_back("         |       |       ");
    row2.push_back("  -------|-------|-------");
    row2.push_back("         |       |       ");
    row2.push_back("2        |       |       ");
    row2.push_back("         |       |       ");
    row3.push_back("  -------|-------|-------");
    row3.push_back("         |       |       ");
    row3.push_back("3        |       |       ");
    row3.push_back("         |       |       ");
    displayBoard();
    cout<<endl;
    
    while(win()==false && full()==false){
        do{
            cout<< name1<< " (X) Mark Location: ";
            cin>> x;
            cin>> y;
            string current;
            
            if(x==1 && y==1){
                current = row1[2];
                if(current[5]!='X' && current[5]!='O'){
                    current[5]='X';
                    row1[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==1 && y==2){
                current = row2[2];
                if(current[5]!='X' && current[5]!='O'){
                    current[5]='X';
                    row2[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==1 && y==3){
                current = row3[2];
                if(current[5]!='X' && current[5]!='O'){
                    current[5]='X';
                    row3[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==2 && y==1){
                current = row1[2];
                if(current[13]!='X' && current[13]!='O'){
                    current[13]='X';
                    row1[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==2 && y==2){
                current = row2[2];
                if(current[13]!='X' && current[13]!='O'){
                    current[13]='X';
                    row2[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==2 && y==3){
                current = row3[2];
                if(current[13]!='X' && current[13]!='O'){
                    current[13]='X';
                    row3[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==3 && y==1){
                current = row1[2];
                if(current[21]!='X' && current[21]!='O'){
                    current[21]='X';
                    row1[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==3 && y==2){
                current = row2[2];
                if(current[21]!='X' && current[21]!='O'){
                    current[21]='X';
                    row2[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==3 && y==3){
                current = row3[2];
                if(current[21]!='X' && current[21]!='O'){
                    current[21]='X';
                    row3[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            cin.clear();
            cin.ignore(10000, '\n');
        } while((x>3 || x<1)|| (y>3||y<1)|| isalpha(x) || isalpha(y) || alreadyThere==true);
        if(win()==true){
            cout<<name1<<" wins this round"<<endl;
            player1->point();
            p1Score=player1->getScore();
            p2Score=player2->getScore();
            cout<<name1<<": "<< p1Score<<endl;
            cout<<name2<<": "<<p2Score<<endl;
            break;
        }
        if(full()==true){
            cout<<"It's a tie!"<<endl;
            break;
        }
        do{
            string current;
            cout<< name2<< " (O) Mark Location: ";
            cin>> x;
            cin>> y;
            if(x==1 && y==1){
                current = row1[2];
                if(current[5]!='X' && current[5]!='O'){
                    current[5]='O';
                    row1[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==1 && y==2){
                current = row2[2];
                if(current[5]!='X' && current[5]!='O'){
                    current[5]='O';
                    row2[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==1 && y==3){
                current = row3[2];
                if(current[5]!='X' && current[5]!='O'){
                    current[5]='O';
                    row3[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==2 && y==1){
                current = row1[2];
                if(current[13]!='X' && current[13]!='O'){
                    current[13]='O';
                    row1[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==2 && y==2){
                current = row2[2];
                if(current[13]!='X' && current[13]!='O'){
                    current[13]='O';
                    row2[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==2 && y==3){
                current = row3[2];
                if(current[13]!='X' && current[13]!='O'){
                    current[13]='O';
                    row3[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==3 && y==1){
                current = row1[2];
                if(current[21]!='X' && current[21]!='O'){
                    current[21]='O';
                    row1[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==3 && y==2){
                current = row2[2];
                if(current[21]!='X' && current[21]!='O'){
                    current[21]='O';
                    row2[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            else if(x==3 && y==3){
                current = row3[2];
                if(current[21]!='X' && current[21]!='O'){
                    current[21]='O';
                    row3[2]=current;
                    displayBoard();
                    alreadyThere=false;
                }
                else{
                    cout<<"That position is already marked"<<endl;
                    alreadyThere=true;
                }
            }
            cin.clear();
            cin.ignore(10000, '\n');

        } while((x>3 || x<1)|| (y>3||y<1) || isalpha(x) || isalpha(y)||alreadyThere==true);
        if(win()==true){
            cout<<name2<<" wins this round"<<endl;
            player2->point();
            p1Score=player1->getScore();
            p2Score=player2->getScore();
            cout<<name1<<": "<< p1Score<<endl;
            cout<<name2<<": "<<p2Score<<endl;
            break;
        }
        if(full()==true){
            cout<<"It's a tie!"<<endl;
            break;
        }
    }
    
}

void Game::displayBoard(){
    for (int i=0; i< row1.size(); ++i){
        cout << row1[i]<<endl;
    }
    for (int i=0; i< row2.size(); ++i){
        cout<<row2[i]<<endl;
    }
    for (int i=0; i< row3.size(); ++i){
        cout<<row3[i]<<endl;
    }
}
