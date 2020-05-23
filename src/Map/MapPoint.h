#ifndef MAPPOINT_H_
#define MAPPOINT_H_


#include<string>
#include<vector>
#include<iostream>
#include <math.h>


using namespace std;

class MapPoint{
	unsigned long long idPoint;
	double y;
	double x;

public:

    MapPoint(){
        this->idPoint=0;
        this->x=0;
        this->y=0;

    }

    MapPoint(unsigned long long id, double x,double y){
		this->idPoint=id;
		this->x=x;
		this->y=y;
	}


	unsigned long long getID();
    bool operator==(const MapPoint & point) const;
    bool operator!=(const MapPoint & point) const;

	double getY();
	double getX();
	void print();
};



#endif
