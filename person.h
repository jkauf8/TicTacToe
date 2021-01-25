//
//  person.hpp
//  hw1-pic10b
//
//  Created by Justin Kaufman on 1/22/21.
//

#ifndef person_h
#define person_h


#include <stdio.h>
#include <string>
using namespace std;

class Person{
public:
    Person(string playerName){
        name=playerName;
    }
    string getName();
    void point();
    int getScore();
private:
    string name;
    int score=0;
};



#endif /* person_h*/
