#include "NursingHome.h"


MapPoint NursingHome::getMapPoint() {
    return mapPoint;
}
int NursingHome::getElderlyNumber(){
    return elderlyNumber;
}

void NursingHome::print(){
    mapPoint.print();
    cout<<elderlyNumber<<endl;
}

bool NursingHome::operator==(const NursingHome & nur) const {
    return mapPoint == nur.mapPoint;
}