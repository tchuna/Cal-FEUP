//
// Created by elgner on 11/05/20.
//

#ifndef HEALTCARE_H
#define HEALTCARE_H
#include "Vehicle.h"


class HealthStation {
    unsigned long int  id;
    int yPosition;
    int xPosition;
    int type;
    vector<Vehicle*> vehicle;

public:

    HealthStation(unsigned long int id, int x, int y, int type){
        this->id=id;
        this->xPosition=x;
        this->yPosition=y;
        this->type=type;

    }

    int getXposition();
    int getYposition();
    int getType();
    unsigned long int getId();
    vector<Vehicle*> getVehicle();
    void setVehicle(vector<Vehicle*> vehicle);

    
};


#endif //HEALTCARE_H
