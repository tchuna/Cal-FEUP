//
// Created by elgner on 11/05/20.
//

#ifndef NURSINGHOME_H
#define NURSINGHOME_H
#include "Elderly.h"
#include "Vehicle.h"
#include<vector>
#include <iostream>


using  namespace std;

class NursingHome {
    MapPoint* mapPoint;
    int elderlyNumber;

public:

    NursingHome(MapPoint* node,int number){
        this->mapPoint=node;
        this->elderlyNumber=number;
    }


    MapPoint* getMapPoint();
    int getElderlyNumber();

    void print();
    bool operator==(const NursingHome & nur) const;
};


#endif //NURSINGHOME_H
