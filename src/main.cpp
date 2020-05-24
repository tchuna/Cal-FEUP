#include <iostream>
#include <vector>
#include <cstdio>
#include <chrono>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Graph/Graph.h"
#include "../Emirita/GraphWorkout.h"
#include "Menu/Menu.h"


using namespace std;

int main() {

    GraphWorkout emeritaHealth;
    emeritaHealth.constructGraph();


    if(emeritaHealth.originalGraph->connectivity()){
        cout<<"Graph Strong Connected"<<endl;
    }else{
        cout<<" N Strong Connected"<<endl;
    }


    auto start = chrono::steady_clock::now();
    emeritaHealth.originalGraph->floydWarshallShortestPath();
    auto end = chrono::steady_clock::now();
    auto diff=end-start;

    cout <<"floyd Warshall Shortest Path Done"<<endl;
    cout<< "Time: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;

    emeritaHealth.addData();
    emeritaHealth.addVehicles();
    emeritaHealth.addNursingHome();
    emeritaHealth.addHealthStation();

    Menu menu =  Menu(emeritaHealth);
    menu.start();


	return 0;
}
