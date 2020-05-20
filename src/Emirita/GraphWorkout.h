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

    vector<unsigned long long> getHealthStationIds();
    vector<unsigned long long>  getNursingHomeIds();


    vector<Vertex<MapPoint> * >  oneVehicleOneItineration(Vehicle * vehicle , HealthStation * healthCar,NursingHome * nr);

    vector<Vertex<MapPoint> * > oneVehicleMultipleItineration(Vehicle * vehicle, HealthStation * healthCare);

    vector<Vertex<MapPoint> *> backPreProcess(vector<Vertex<MapPoint>* > shortenedPath);

    vector<vector<Vertex<MapPoint>*>> multipleVehicleMultipleItineration(HealthStation * hs, int vehiclesCapacity);

    void distBetHealthLocation(int vertexPos, bool isSort);

};


#endif //GRAPHWORKOUT_H
