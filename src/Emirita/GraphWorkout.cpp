//
// Created by elgner on 12/05/20.
//

#include "GraphWorkout.h"
#include "../Utilities/ReadFiles.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define URGENCY  0
#define HEALTHCENTER  1
#define NURSINGHOME  2

void GraphWorkout::loadGraph(){
    ReadFiles file;
    this->connectP=file.loadConnects();
    this->points=file.loadMapPoints();


}

double GraphWorkout::distanceTwoPointsOnMap(unsigned long pointX1, unsigned long pointY1,unsigned long pointX2, unsigned long pointY2){

    pair<double,double> distance = make_pair(pointX2 - pointX1 ,pointY2 - pointY1 );

    return sqrt(distance.first*distance.first + distance.second*distance.second);

}


Graph<MapPoint> *  GraphWorkout::constructGraph(){
    loadGraph();
    double x1,x2,y1,y2, dist;
    originalGraph=new Graph<MapPoint>;
    vector<MapPoint> nodes;

    for(unsigned int i =0; i<points.size();i++){
        MapPoint node=MapPoint(points[i]->getID(),points[i]->getX(),points[i]->getY());
        originalGraph->addVertex(node);
        //originalGraph->getVertex(node)->getInfo().print();
    }

    for(unsigned int i =0; i<connectP.size();i++){
        x1=0;x2=0;y1=0;y2=0;
        unsigned long  int id1,id2;


        for(unsigned int j =0; j<points.size();j++){
            if(points[j]->getID()==connectP[i]->getFirstP()){
                x1=points[j]->getX();
                y1=points[j]->getY();
                id1=points[j]->getID();
                break;
            }
        }


        for(unsigned int j =0; j<points.size();j++){
            if(points[j]->getID()==connectP[i]->getSecondP()){
                x2=points[j]->getX();
                y2=points[j]->getY();
                id2=points[j]->getID();
                break;
            }

        }

        dist=distanceTwoPointsOnMap(x1,y1,x2,y2);
        MapPoint node1=MapPoint(id1,x1,y1);
        MapPoint node2=MapPoint(id2,x2,y2);
        originalGraph->addEdge(node1,node2,dist);

        cout<<connectP[i]->getId() << "   Point1: "<<connectP[i]->getFirstP()<<"   "<<"Point2: "<<connectP[i]->getSecondP()<<"   "<<"dist: "<<dist<<endl;

    }
}


bool  GraphWorkout::addData(){
    ReadFiles file;
    data=file.loadTags();
    //cout<<data[NURSINGHOME].size()<<endl;


}

bool  GraphWorkout::addVehicles(){
    ReadFiles file;
    vehicles =file.loadVehicles();


}

bool  GraphWorkout::addNursingHome(){
    //ReadFiles file;
    //nursingHome=file.loadNursingHome();

    srand (time(NULL));

    for(int i=0;i<data[NURSINGHOME].size();i++){
        int type;
        type = rand() % 5;
        for(int j=0;j<points.size();j++){
            if(data[NURSINGHOME][i]==points[j]->getID()){
               NursingHome* aux = new NursingHome(*points[j],type);
                if (find(nursingHome.begin(), nursingHome.end(), aux) == nursingHome.end()) {//not in the vector, so it will be added
                    nursingHome.push_back(aux);
                    //aux->print();
                }
            }
        }
    }

}



bool  GraphWorkout::addHealthStation(){
    //ReadFiles file;
    //healthCareLocation=file.loadHealthStation();

    srand (time(NULL));

    for(int i=0;i<data[URGENCY].size();i++){
        int type;
        type = 1;
        for(int j=0;j<points.size();j++){
            if(data[URGENCY][i]==points[j]->getID()){
                HealthStation* aux = new HealthStation(*points[j],type);
                if (find(healthCareLocation.begin(), healthCareLocation.end(), aux) == healthCareLocation.end()) {//not in the vector, so it will be added
                    healthCareLocation.push_back(aux);
                    //aux->print();
                }
            }
        }
    }


    for(int i=0;i<data[HEALTHCENTER].size();i++){
        int type;
        type = 0;
        for(int j=0;j<points.size();j++){
            if(data[HEALTHCENTER][i]==points[j]->getID()){
                HealthStation* aux = new HealthStation(*points[j],type);

                if (find(healthCareLocation.begin(), healthCareLocation.end(), aux) == healthCareLocation.end()) {//not in the vector, so it will be added
                    healthCareLocation.push_back(aux);
                    //aux->print();
                }


            }
        }
    }

}


HealthStation* GraphWorkout::nearHealthStation(MapPoint node,int type) {

    int distMinim = INT_MAX;
    int nodePosition = -1;


    for (unsigned int i = 0; i < healthCareLocation.size(); i++) {
        if( healthCareLocation[i]->getType()==type){

            originalGraph->dijkstraShortestPath(healthCareLocation[i]->getMapPoint());

            int currentDist = originalGraph->getVertex(node)->getDist();
            if (currentDist <= distMinim) {
                nodePosition = i;
                distMinim = currentDist;
            }

        }

    }

    return healthCareLocation[nodePosition];

}

NursingHome* GraphWorkout::nearNursingHome(MapPoint node) {
    int distMinim = INT_MAX;
    int nodePosition = -1;

    originalGraph->dijkstraShortestPath(node);

    for (unsigned int i = 0; i < nursingHome.size(); i++) {
        int currentDist=originalGraph->getVertex(nursingHome[i]->getMapPoint())->getDist();
        if (currentDist < distMinim) {
            nodePosition  = i;
            distMinim = currentDist;
        }
    }

    if (nodePosition == -1) {
        MapPoint* node= new MapPoint(-1,-1,-1);
        NursingHome* nullNode= new NursingHome(*node,-1);
        return nullNode;
    } else
        return nursingHome[nodePosition];


}


vector<MapPoint> GraphWorkout::findPath(MapPoint source, MapPoint dest ,int type) {


    HealthStation* heathType;

    if (type == 1) {
        heathType = nearHealthStation(dest, 1);
    } else {
        heathType = nearHealthStation(dest, 0);
    }

    cout << " Heath Station Position: " <<endl; heathType->getMapPoint().print();


    vector<MapPoint> temp1;
    vector<MapPoint> temp2;
    vector<MapPoint> result;

    if (heathType->getMapPoint().getID() == source.getID() && heathType->getMapPoint().getID() == dest.getID()) {

        result.push_back(source);
        result.push_back(dest);


    } else if (heathType->getMapPoint().getID() == source.getID() || heathType->getMapPoint().getID()  == dest.getID()) {


        result = originalGraph->getPath(source, dest);

    } else {

        temp1 = originalGraph->getPath(source,heathType->getMapPoint());
        temp2 = originalGraph->getPath(heathType->getMapPoint(), dest);

        temp2.erase(temp2.begin());

        temp1.insert(temp1.end(), temp2.begin(), temp2.end());
        result = temp1;
    }

    return result;

}

vector<Vertex<MapPoint> * >  GraphWorkout::oneVehicleOneItineration(Vehicle * v , HealthStation * healthCare , NursingHome * nr){ // nr = nursingHme[0]

    MapPoint healthstation = healthCare->getMapPoint();
    MapPoint vehicle = v->getMapPoint();
    MapPoint nursinghome = nr->getMapPoint();
    vector<Vertex<MapPoint> * > result, temp;
    
    cout<<"floyd1"<<endl;
    originalGraph->floydWarshallShortestPath();


    /*if (nursinghom.size() != 1) {
        cout << "there can only be one Health station" << endl;
        exit(1);
    }*/

    pair<Vertex<MapPoint>*, Vertex<MapPoint>*> nodes = originalGraph->getTwoVertexs(vehicle,nursinghome);
    cout<<"floyd2"<<endl;
    result = originalGraph->getfloydWarshallPath(vehicle, nursinghome);
    temp = originalGraph->getfloydWarshallPath(nodes.second->getInfo(), healthstation);
    result.insert(result.end(), temp.begin() + 1, temp.end());

    return result;


}


vector<Vertex<MapPoint> * >  GraphWorkout::oneVehicleMultipleItineration( Vehicle * v, HealthStation * hs ){
    vector<Vertex<MapPoint> * > result, temp;
    originalGraph->floydWarshallShortestPath();
    //Vehicle* v=vehicles[0];
    //HealthStation* hs=healthCareLocation[0];


    pair<Vertex<MapPoint>*, Vertex<MapPoint>*> nodes = originalGraph->getTwoVertexs(v->getMapPoint(), hs->getMapPoint());
    Vertex<MapPoint> * garage = nodes.first, * station = nodes.second;
    int currentVertex = garage->posAtVec;

    distBetHealthLocation(currentVertex, true);

    Vertex<MapPoint> * current = (*originalGraph)(currentVertex), * next = (*originalGraph)(nursingHome[0]->posAtVec);

    result = originalGraph->getfloydWarshallPath(current->getInfo(), next->getInfo());//shortest from vehicle to nursingHome

    while (nursingHome.size() > 0 && v->getVehicleCapacity() >= nursingHome[0]->getElderlyNumber()) {
        v->addPass(-nursingHome[0]->getElderlyNumber());
        cout << "Add Nursing  Home : ";
        nursingHome[0]->getMapPoint().print();
        nursingHome.erase(nursingHome.begin());//erase the first

        if (nursingHome.size() == 0)
            break;
        distBetHealthLocation(current->posAtVec, true);//recalculates the distances and sorts again
        current = next;
        next = (*originalGraph)(nursingHome[0]->posAtVec);
        temp = originalGraph->getfloydWarshallPath(current->getInfo(), next->getInfo());//shortest from nursingHome to nursingHome
        for (size_t i = 0; i < nursingHome.size(); i++) {//iterate the vertexes in the new path and check for nursingHome passed
            if (temp.size() > 0
                && find(temp.begin(), temp.end(), (*originalGraph)(nursingHome[i]->posAtVec)) != temp.end()
                && v->getVehicleCapacity() >= nursingHome[i]->getElderlyNumber()) {//if the nursingHome is in the new path
                v->addPass(-nursingHome[i]->getElderlyNumber());
                cout << "Add Nursing Home: ";
                nursingHome[i]->getMapPoint().print();
                nursingHome.erase(nursingHome.begin()+i);
                i--;
            }

        }
        result.insert(result.end(), temp.begin() + 1, temp.end());
    }

    temp = originalGraph->getfloydWarshallPath(next->getInfo(), station->getInfo());
    result.insert(result.end(), temp.begin() + 1, temp.end());

    return result;
}


vector<vector<Vertex<MapPoint>*>> GraphWorkout:: multipleVehicleMultipleItineration(HealthStation * hs, int vehiclesCapacity) {
    vector<vector<Vertex<MapPoint>*>> result;

    Vehicle * v = vehicles[0];
    while (nursingHome.size() > 0) {
        v->setVehicleCapacity(vehiclesCapacity);
        result.push_back(oneVehicleMultipleItineration(v, hs));
    }

    return result;
}

void  GraphWorkout::distBetHealthLocation(int vertexPos, bool isSort){
    Vertex<MapPoint> * tempVertex;
    for (auto nursinghome : nursingHome) {
        tempVertex = originalGraph->getVertex(nursinghome->getMapPoint());
        nursinghome->posAtVec = tempVertex->posAtVec;
        nursinghome->dist = originalGraph->W[vertexPos][nursinghome->posAtVec];
    }
    if(isSort && nursingHome.size() > 0)
        sort(nursingHome.begin(), nursingHome.end(),compareNursingHome());
    cout << "SORT DONE" << endl;

}