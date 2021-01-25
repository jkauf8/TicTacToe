//
//  person.cpp
//  hw1-pic10b
//
//  Created by Justin Kaufman on 1/22/21.
//

#include "person.h"
using namespace std;

string Person::getName(){
    return name;
}

void Person::point(){
    score++;
}

int Person::getScore(){
    return score;
}
