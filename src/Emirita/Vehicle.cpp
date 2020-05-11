
#include "Vehicle.h"

using namespace  std;

int Vehicle::getVehicleCode(){
    return vehicleCode;
}
void Vehicle::setVehicleCode(int code){
    this->vehicleCode=code;
}

int Vehicle::getVehicleCapacity(){
    return vehicleCapacity;
}

void Vehicle::setVehicleCapacity(int n){
    this->vehicleCapacity=n;
}

int Vehicle::getVehicleType(){
    return vehicleType;
}

void Vehicle::setVehicleType(int type){
    this->vehicleType=type;
}

int Vehicle::getNursingHomeId(){
    return nursingHomeId;
}

void Vehicle::setNursingHomeId(int n){
    this->nursingHomeId=n;
}

void Vehicle::print(){

    cout<<vehicleCode<<" "<<nursingHomeId<<" "<<vehicleCapacity<<" "<<vehicleType<<endl;
}


vector <Elderly*> Vehicle::getOccupants(){
   return occupants;
}

bool  Vehicle::addOccupants(Elderly* elderly){
    int aux=vehicleCapacity-1;
    if(vehicleType==elderly->getUrgency() && aux>0){
        occupants.push_back(elderly);
        return true;
    }
    return false;
}
