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

    vector <vector<unsigned long long >>data;
    vector <MapPoint*>points;

    vector<ConnectPoints *>connectP;

    Graph<MapPoint> * originalGraph;

    Graph<MapPoint> * preProcessingGraph;

    vector<Vehicle *> vehicles ;

    vector<NursingHome *> nursingHome;

    vector<HealthStation *> healthCareLocation;

    vector<Vertex<MapPoint> * > resultPath;


    void loadGraph();
    Graph<MapPoint> * constructGraph();
    double distanceTwoPointsOnMap(unsigned long pointX1, unsigned long pointY1,unsigned long pointX2, unsigned long pointY2);
    NursingHome* nearNursingHome(MapPoint node);
    HealthStation*  nearHealthStation(MapPoint node,int type);

    vector<MapPoint> findPath(MapPoint source, MapPoint dest ,int type);

        bool addVehicles();
    bool addData();

    bool addNursingHome();

    bool addHealthStation();

    vector<Vertex<MapPoint> * >  oneVehicleOneItineration(Vehicle * vehicle , HealthStation * healthCar,NursingHome * nr);

    vector<Vertex<MapPoint> * > oneVehicleMultipleItineration(Vehicle * vehicle, HealthStation * healthCare);

    vector<vector<Vertex<MapPoint>*>> multipleVehicleMultipleItineration(HealthStation * hs, int vehiclesCapacity);

    void distBetHealthLocation(int vertexPos, bool isSort);

    bool checkVertexInGraph(unsigned long long id);

};


#endif //GRAPHWORKOUT_H
