#include "NursingHome.h"

int NursingHome::getXposition(){
    return xPosition;
}
int NursingHome::getYposition(){
    return yPosition;
}
unsigned long int NursingHome::getId(){
    return id;
}
vector<Elderly*> NursingHome::getElderly(){
    return elderly;
}
void NursingHome::setElderly(vector<Elderly*> elderly){
    this->elderly=elderly;
}

vector<Vehicle *> NursingHome::getVehicle(){
    return vehicle;
}
void NursingHome::setVehicle(vector<Vehicle *> vehicle) {
    this->vehicle=vehicle;
}
