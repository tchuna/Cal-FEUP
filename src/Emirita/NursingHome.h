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
    unsigned long int  id;
    int yPosition;
    int xPosition;
    vector<Elderly*> elderly;
    vector<Vehicle*> vehicle;

public:

    NursingHome(unsigned long int id, int x, int y){
        this->id=id;
        this->xPosition=x;
        this->yPosition=y;

    }


    int getXposition();
    int getYposition();
    unsigned long int getId();
    vector<Elderly*> getElderly();
    vector<Vehicle*> getVehicle();
    void setElderly(vector<Elderly*> elderly);
    void setVehicle(vector<Vehicle*> vehicle);






};


#endif //NURSINGHOME_H
