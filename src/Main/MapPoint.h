#ifndef MAPPOINT_H_
#define MAPPOINT_H_


#include<string>
#include<vector>
#include<iostream>
#include <math.h>



using namespace std;

class MapPoint{
	unsigned long long idPoint;
	double latitude;
	double longitude;
	double y;
	double x;

public:


	MapPoint(unsigned long long id, double lat,double lon, double x, double y ){
		this->idPoint=id;
		this->latitude=lat;
        this->latitude=lon;
		this->x=x;
		this->y=y;
	};


    //for test simple case
    MapPoint(unsigned long long id, double x,double y){
		this->idPoint=id;
		this->latitude=0;
        this->longitude=0;
		this->x=x;
		this->y=y;
	};



	unsigned long long getID();

	double getLat();
	double getLong();

	double getY();
	double getX();
	void print();
};



#endif
