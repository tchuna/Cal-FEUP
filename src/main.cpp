#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Graph/Graph.h"
#include "../Emirita/GraphWorkout.h"


using namespace std;

int main() {
    Graph<unsigned long> graph;

    GraphWorkout emeritaHealth;
    emeritaHealth.constructGraph();
    emeritaHealth.addVehicles();
    emeritaHealth.addNursingHome();
    emeritaHealth.addHealthStation();


    /*for(int i=0;i<emeritaHealth.vehicles.size();i++){
        emeritaHealth.vehicles[i]->print();

    }*/

    /*for(int i=0;i<emeritaHealth.nursingHome.size();i++){
        emeritaHealth.nursingHome[i]->print();

    }*/

    for(int i=0;i<emeritaHealth.healthCareLocation.size();i++){
        emeritaHealth.healthCareLocation[i]->print();
    }

	return 0;
}
