#include "MapPoint.h"


unsigned long  long MapPoint:: getID(){

	return this->idPoint;
}

double MapPoint::getY(){

	return this->y;
}
double MapPoint::getX(){

	return this->y;

}



void MapPoint::print(){

    cout<<this->idPoint<<" "<<this->x<<" "<<this->y<<endl;

}



bool MapPoint::operator==(const MapPoint & point) const {
    return idPoint == point.idPoint;
}




