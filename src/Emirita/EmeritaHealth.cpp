
#include "EmeritaHealth.h"


double EmeritaHealth::distanceTwoPoints(unsigned long pointX1, unsigned long pointY1,
                                        unsigned long pointX2, unsigned long pointY2){

    pair<double,double> distance = make_pair(pointX2 - pointX1 ,pointY2 - pointY1 );

    return sqrt(distance.first*distance.first + distance.second*distance.second);

}


void EmeritaHealth::createViewer() {
    gv= new GraphViewer(600, 1800, false);
    gv->setBackground("background.jpg");
    gv->createWindow(600, 1800);


}

void EmeritaHealth:: loadFiles(){
    ReadFiles file;
    this->connectP=file.loadConects();
    this->points=file.loadMapPoints();

}


Graph<unsigned long> EmeritaHealth:: constructGraph(){
    loadFiles();
    double x1,x2,y1,y2, dist;
    vector<unsigned long> nodes;

    for(unsigned int i =0; i<points.size();i++){
        graph.addVertex(points[i]->getID());
        gv->addNode(points[i]->getID(),points[i]->getX() ,points[i]->getY());
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

        gv->addEdge(connectP[i]->getId(),connectP[i]->getFirstP(),connectP[i]->getSecondP(),edgeType.DIRECTED);

        cout<<connectP[i]->getId() << "   Point1: "<<connectP[i]->getFirstP()<<"   "<<"Point2: "<<connectP[i]->getSecondP()<<"   "<<"dist: "<<dist<<endl;
    }
    gv->rearrange();
    return graph;
}
