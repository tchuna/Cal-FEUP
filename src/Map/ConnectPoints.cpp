#include "ConnectPoints.h"

unsigned long ConnectPoints:: getId(){
	return this->idConnect;
}
unsigned  long ConnectPoints:: getFirstP(){

	return this->firstPoint;
}
unsigned long ConnectPoints:: getSecondP(){

	return this->secondPoint;
}
void ConnectPoints::print(){

	cout<<this->idConnect<<" "<<this->firstPoint<<" "<<this->secondPoint<<endl;
}
