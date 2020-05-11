
#include "EmeritaHealth.h"


double EmeritaHealth::distanceTwoPoints(unsigned long pointX1,unsigned long pointY1,
                                           unsigned long pointX2,unsigned long pointY2){

    pair<double,double> distance = make_pair(pointX2 - pointX1 ,pointY2 - pointY1 );

    return sqrt(distance.first*distance.first + distance.second*distance.second);

}

void EmeritaHealth:: loadFiles(){
    ReadFiles file;

    this->connectP=file.loadConects();
    this->points=file.loadMapPoints();
    this->gv = new GraphViewer(1200, 600,true);


}


void EmeritaHealth:: constructGraph(){
    loadFiles();
    double x1,x2,y1,y2, dist;

    for(unsigned int i =0; i<points.size();i++){
        graph.addVertex(points[i]->getID());
    }


    for(unsigned int i =0; i<connectP.size();i++){
        x1=0;x2=0;y1=0;y2=0;

        for(unsigned int j =0; j<points.size();j++){
            if(points[j]->getID()==connectP[i]->getFirstP()){
                x1=points[j]->getX();
                y1=points[j]->getY();
                break;
            }
        }


        for(unsigned int j =0; j<points.size();j++){
            if(points[j]->getID()==connectP[i]->getSecondP()){
                x2=points[j]->getX();
                y2=points[j]->getY();
                break;
            }

        }

        dist=distanceTwoPoints(x1,y1,x2,y2);
        graph.addEdge(connectP[i]->getFirstP(),connectP[i]->getSecondP(),dist);

        cout<<connectP[i]->getId() << "   Point1: "<<connectP[i]->getFirstP()<<"   "<<"Point2: "<<connectP[i]->getSecondP()<<"   "<<"dist: "<<dist<<endl;
    }




}
