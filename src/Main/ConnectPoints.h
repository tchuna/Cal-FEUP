#ifndef CONNECTPOINTS_H_
#define CONNECTPOINTS_H_

#include<string>
#include<vector>
#include<iostream>

using namespace std;


class ConnectPoints{

	unsigned long idConnect;
	unsigned long firstPoint;
	unsigned long secondPoint;

public:
	ConnectPoints(unsigned long id, unsigned long point1,unsigned long point2){
		this->idConnect=id;
		this->firstPoint=point1;
		this->secondPoint=point2;
	};

	unsigned long getId();
	unsigned long getFirstP();
	unsigned long getSecondP();
	void print();


};




#endif
