
#include "Vehicle.h"

using namespace  std;

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


void Vehicle::print(){
    mapPoint->print();
    cout<<vehicleCapacity<<" "<<vehicleType<<endl;
}

bool Vehicle::operator==(const Vehicle & vehicle) const {
    return mapPoint == vehicle.mapPoint;
}



