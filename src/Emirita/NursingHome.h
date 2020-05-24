
#ifndef NURSINGHOME_H
#define NURSINGHOME_H
#include "Elderly.h"
#include "Vehicle.h"
#include<vector>
#include <iostream>


using  namespace std;

class NursingHome {
    MapPoint mapPoint;
    int elderlyNumber;

public:
    double dist;
    int posAtVec;

    NursingHome(MapPoint node,int number){
        this->mapPoint=node;
        this->elderlyNumber=number;
    }


    MapPoint getMapPoint();
    int getElderlyNumber();

    void print();
    bool operator==(const NursingHome & nur) const;


};

struct compareNursingHome {

    bool const operator()(NursingHome *lhs, NursingHome *rhs) const {
        return lhs->dist < rhs->dist;
    }
};


#endif //NURSINGHOME_H
