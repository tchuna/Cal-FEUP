//
// Created by elgner on 12/05/20.
//

#include "GraphWorkout.h"
#include "../Utilities/ReadFiles.h"


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

        //cout<<connectP[i]->getId() << "   Point1: "<<connectP[i]->getFirstP()<<"   "<<"Point2: "<<connectP[i]->getSecondP()<<"   "<<"dist: "<<dist<<endl;
    }




}


bool  GraphWorkout::addVehicles(){
    ReadFiles file;
    vehicles =file.loadVehicles();

}

bool  GraphWorkout::addNursingHome(){
    ReadFiles file;
    nursingHome=file.loadNursingHome();
}

bool  GraphWorkout::addHealthStation(){
    ReadFiles file;
    healthCareLocation=file.loadHealthStation();

}

vector<string>  GraphWorkout::getHealthStationIds(){

}


vector<Vertex<MapPoint> * >  GraphWorkout::OneVehicleOneItineration(Vehicle * vehicle , HealthStation * healthCare){


}

vector<Vertex<MapPoint> * >  GraphWorkout::OneVehicleMultipleItineration(Vehicle * vehicle, HealthStation * healthCare){


}

void  GraphWorkout::floydWarshallShortestPath(){

}

vector<Vertex<MapPoint> *>  GraphWorkout::backPreProcess(vector<Vertex<MapPoint>* > shortenedPath){


}

void  GraphWorkout::distBetHealthLocation(int vertexPos, bool isSort){


}