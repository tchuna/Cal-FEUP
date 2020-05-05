#include "ConectPoints.h"

unsigned long ConectPoints:: getId(){
	return this->idConect;
}
unsigned  long ConectPoints:: getFristP(){

	return this->fristPoint;
}
unsigned long ConectPoints:: getSecondP(){

	return this->secondPoint;
}
void ConectPoints::print(){

	cout<<this->idConect<<" "<<this->fristPoint<<" "<<this->secondPoint<<endl;
}
