#ifndef CONECTPOINTS_H_
#define CONECTPOINTS_H_

#include<string>
#include<vector>
#include<iostream>

using namespace std;


class ConectPoints{

	unsigned long idConect;
	unsigned long fristPoint;
	unsigned long secondPoint;

public:
	ConectPoints(unsigned long id, unsigned long point1,unsigned long point2){
		this->idConect=id;
		this->fristPoint=point1;
		this->secondPoint=point2;
	};

	unsigned long getId();
	unsigned  long getFristP();
	unsigned long getSecondP();
	void print();


};




#endif
