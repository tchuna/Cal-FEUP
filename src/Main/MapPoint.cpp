#include "MapPoint.h"


unsigned long  long MapPoint:: getID(){

	return this->idPoint;
}

double MapPoint:: getLat(){

	return this->latitude;
}

double MapPoint:: getLong(){

	return this->longitude;
}


double MapPoint::getY(){

	return this->y;
}
double MapPoint::getX(){

	return this->y;

}



void MapPoint::print(){

	/*cout<<this->idPoint<<" "<<this->latitude<<" "<<this->longitude
			<<" "<<this->x<<" "<<this->y<<endl;*/

    cout<<this->idPoint<<" "<<this->x<<" "<<this->y<<endl;

}


