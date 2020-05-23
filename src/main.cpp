#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Graph/Graph.h"
#include "../Emirita/GraphWorkout.h"
#include "Menu/Menu.h"


using namespace std;

int main() {
    ReadFiles file;
    vector<MapPoint> path;
    vector<Vertex<MapPoint> * > result;
    Graph<unsigned long> graph;
    GraphWorkout emeritaHealth;
    emeritaHealth.constructGraph();
    emeritaHealth.originalGraph = emeritaHealth.originalGraph->preProcessGraph();
    emeritaHealth.addData();
    emeritaHealth.addVehicles();
    emeritaHealth.addNursingHome();
    emeritaHealth.addHealthStation();
    //result=emeritaHealth.oneVehicleOneItineration();
    //result=emeritaHealth.oneVehicleMultipleItineration();


//    for(unsigned int i = 0; i < emeritaHealth.nursingHome.size(); i++) {
//        emeritaHealth.nursingHome[i]->print();
//    }
//    for(unsigned int i = 0; i < emeritaHealth.healthCareLocation.size(); i++) {
//        emeritaHealth.healthCareLocation[i]->print();
//    }

    Menu menu =  Menu(emeritaHealth);
    menu.start();
    bool isconnect=emeritaHealth.originalGraph->connectivity();

    /*Vehicle* v= emeritaHealth.vehicles[0];
    HealthStation* hs=emeritaHealth.healthCareLocation[40];
    NursingHome* nr=emeritaHealth.nursingHome[6];
    result=emeritaHealth.oneVehicleOneItineration(v,hs,nr);*/
    //result=emeritaHealth.oneVehicleMultipleItineration(v,hs);

    //path=emeritaHealth.findPath(v->getMapPoint(),hs->getMapPoint(),1);

    /*cout<<"short path:"<<endl;
    for(int i=0;i<result.size();i++){
        result[i]->getInfo().print();




   // cout<<"short path:"<<endl;

    for(int i=0;i<emeritaHealth.nursingHome.size();i++){
        emeritaHealth.nursingHome[i]->print();

    }*/



	return 0;
}
