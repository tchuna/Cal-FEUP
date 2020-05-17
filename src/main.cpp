#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Graph/Graph.h"
#include "../Emirita/GraphWorkout.h"


using namespace std;

int main() {
    vector<Vertex<MapPoint> * > result;
    Graph<unsigned long> graph;
    GraphWorkout emeritaHealth;
    emeritaHealth.constructGraph();
    emeritaHealth.addVehicles();
    emeritaHealth.addNursingHome();
    emeritaHealth.addHealthStation();
    //result=emeritaHealth.oneVehicleOneItineration();
    result=emeritaHealth.oneVehicleMultipleItineration();


    cout<<"short path:"<<endl;
    for(int i=0;i<result.size();i++){
        result[i]->getInfo().print();

    }

    /*for(int i=0;i<emeritaHealth.nursingHome.size();i++){
        emeritaHealth.nursingHome[i]->print();

    }*/

   /* for(int i=0;i<emeritaHealth.healthCareLocation.size();i++){
        emeritaHealth.healthCareLocation[i]->print();
    }*/

	return 0;
}
