//
// Created by elgner on 12/05/20.
//

#ifndef GRAPHWORKOUT_H
#define GRAPHWORKOUT_H

#include "../Graph/Graph.h"
#include "../Map/MapPoint.h"
#include "HealthStation.h"
#include "Vehicle.h"
#include "NursingHome.h"
#include "../Map/ConnectPoints.h"
#include "../Map/MapPoint.h"



class GraphWorkout {
public:

    vector <MapPoint*>points;

    vector<ConnectPoints *>connectP;

    Graph<MapPoint> * originalGraph;

    Graph<MapPoint> * preProcessingGraph;

    vector<Vehicle *> vehicles ;

    vector<NursingHome *> nursingHome;

    vector<HealthStation *> healthCareLocation;


    void loadGraph();
    Graph<MapPoint> * constructGraph();
    double distanceTwoPointsOnMap(unsigned long pointX1, unsigned long pointY1,unsigned long pointX2, unsigned long pointY2);

    GraphWorkout & preProcessGraph();

    bool addVehicles();

    bool addNursingHome();

    bool addHealthStation();

    vector<string> getHealthStationIds();



    vector<Vertex<MapPoint> * > OneVehicleOneItineration(Vehicle * vehicle , HealthStation * healthCare);

    vector<Vertex<MapPoint> * > OneVehicleMultipleItineration(Vehicle * vehicle, HealthStation * healthCare);

    void floydWarshallShortestPath();

    vector<Vertex<MapPoint> *> backPreProcess(vector<Vertex<MapPoint>* > shortenedPath);

    void distBetHealthLocation(int vertexPos, bool isSort);

};


#endif //GRAPHWORKOUT_H
