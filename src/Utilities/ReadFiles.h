#ifndef READFILES_H_
#define READFILES_H_


#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../Map/MapPoint.h"
#include "../Map/ConnectPoints.h"


using namespace std;

class ReadFiles{


public:

	vector<MapPoint*>  loadMapPoints();
	vector<ConnectPoints*> loadConects();
};





#endif
