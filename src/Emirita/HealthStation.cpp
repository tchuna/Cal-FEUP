#include "HealthStation.h"

int HealthStation::getXposition(){
    return xPosition;
}

int  HealthStation::getYposition(){
    return yPosition;
}

int  HealthStation::getType(){
    return type;
}

unsigned long int  HealthStation::getId(){
    return id;
}

vector<Vehicle*>  HealthStation::getVehicle(){
    return vehicle;
}

void  HealthStation::setVehicle(vector<Vehicle*> vehicle){
    this->vehicle=vehicle;
}


