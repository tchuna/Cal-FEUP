//
// Created by elgner on 11/05/20.
//

#ifndef VEHICLE_H
#define VEHICLE_H
#include "../Map/MapPoint.h"
#include <vector>
#include <iostream>



class Vehicle {

    int vehicleCapacity;
    int vehicleType;
    MapPoint mapPoint;


public:

    Vehicle(int capacity, int type,MapPoint node) {
        this->vehicleCapacity=capacity;
        this->vehicleType=type;
        this->mapPoint=node;
    };


    int getVehicleCapacity();
    void setVehicleCapacity(int n);
    int getVehicleType();
    void setVehicleType(int type);
    MapPoint getMapPoint();
    void setMapPoint(MapPoint node);
    bool operator==(const Vehicle & vehicle) const;
    Vehicle & addPass(int value);



    void print();


};


#endif //VEHICLE_H
