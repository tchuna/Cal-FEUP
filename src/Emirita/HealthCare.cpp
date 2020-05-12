#include "HealthCare.h"

int HealthCare::getXposition(){
    return xPosition;
}

int  HealthCare::getYposition(){
    return yPosition;
}

int  HealthCare::getType(){
    return type;
}

unsigned long int  HealthCare::getId(){
    return id;
}

vector<Vehicle*>  HealthCare::getVehicle(){
    return vehicle;
}

void  HealthCare::setVehicle(vector<Vehicle*> vehicle){
    this->vehicle=vehicle;
}


