//
// Created by elgner on 11/05/20.
//

#ifndef VEHICLE_H
#define VEHICLE_H
#include "Elderly.h"
#include <vector>
#include <iostream>



class Vehicle {

    int vehicleCapacity;
    int vehicleType;
    int nursingHomeId;
    int vehicleCode;
    vector <Elderly*>occupants;


public:

    Vehicle(int code, int capacity, int type, int nurhid ){
        this->vehicleCode=code;
        this->vehicleCapacity=capacity;
        this->vehicleType=type;
        this->nursingHomeId=nurhid;
    };


    int getVehicleCode();
    void setVehicleCode(int code);

    int getVehicleCapacity();
    void setVehicleCapacity(int n);

    int getVehicleType();
    void setVehicleType(int type);

    int getNursingHomeId();
    void setNursingHomeId(int g);

    void print();

    vector <Elderly*>getOccupants();

    bool  addOccupants(Elderly* container);

};


#endif //VEHICLE_H
