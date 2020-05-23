#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Graph/Graph.h"
#include "../Emirita/GraphWorkout.h"


using namespace std;

int main() {
    ReadFiles file;
    vector<MapPoint> path;
    vector<Vertex<MapPoint> * > result;
    GraphWorkout emeritaHealth;
    emeritaHealth.constructGraph();
    emeritaHealth.addData();
    emeritaHealth.addVehicles();
    emeritaHealth.addNursingHome();
    emeritaHealth.addHealthStation();
    bool isconnect=emeritaHealth.originalGraph->connectivity();

    Vehicle* v= emeritaHealth.vehicles[0];
    HealthStation* hs=emeritaHealth.healthCareLocation[0];
    NursingHome* nr=emeritaHealth.nursingHome[2];
    result=emeritaHealth.oneVehicleOneItineration(v,hs,nr);
    //result=emeritaHealth.oneVehicleMultipleItineration(v,hs);

    //path=emeritaHealth.findPath(v->getMapPoint(),hs->getMapPoint(),1);





  /*  cout<<"short path:"<<endl;
    for(int i=0;i<result.size();i++){
        result[i]->getInfo().print();

    }*/


    if(isconnect){
        cout<<"\n\n"<<endl;
        cout<<"is strongly connect"<<endl;
    }else{
        cout<<"\n\n"<<endl;
        cout<<"is Not strongly connect"<<endl;
    }

    vector<vector<unsigned long long>> tags=file.loadTags();

    //cout<<"\n"<<tags.size()<<endl;
    /*for(int i=0;i<emeritaHealth.nursingHome.size();i++){
        emeritaHealth.nursingHome[i]->print();

    }*/

   /* for(int i=0;i<emeritaHealth.healthCareLocation.size();i++){
        emeritaHealth.healthCareLocation[i]->print();
    }*/
	return 0;
}
