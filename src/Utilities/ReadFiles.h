#ifndef READFILES_H_
#define READFILES_H_


#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "../Main/MapPoint.h"
#include "../Main/ConectPoints.h"


using namespace std;

class ReadFiles{


public:

	vector<MapPoint*>  loadMapPoints();
	vector<ConectPoints*> loadConects();
};





#endif
