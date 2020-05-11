//
// Created by elgner on 11/05/20.
//

#ifndef ELDERLY_H
#define ELDERLY_H

#include<string>

using namespace std;


class Elderly {
    int age;
    string name;
    bool isUrgent;



    Elderly(int age,string name, bool urgency){
        this->name=name;
        this->isUrgent=urgency;
        this->age=age;

    }


public:
    int  getAge();
    string getName();
    bool getUrgency();



};




#endif //ELDERLY_H
