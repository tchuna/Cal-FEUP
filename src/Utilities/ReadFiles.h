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
#include "../Emirita/Vehicle.h"
#include "../Emirita/NursingHome.h"
#include "../Emirita/HealthStation.h"



using namespace std;

class ReadFiles{


public:

	vector<MapPoint*>  loadMapPoints();
    vector<Vehicle*>  loadVehicles();
    vector<NursingHome*>  loadNursingHome();
    vector<HealthStation*>  loadHealthStation();
	vector<ConnectPoints*> loadConnects();
};





#endif
