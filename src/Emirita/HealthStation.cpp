#include "HealthStation.h"

int HealthStation::getType(){
    return type;
}

MapPoint HealthStation::getMapPoint(){
    return mapPoint;
}

void HealthStation::print(){
    mapPoint.print();
    cout<<type<<endl;
}

bool HealthStation::operator==(const HealthStation & hs) const {
    return mapPoint == hs.mapPoint;
}