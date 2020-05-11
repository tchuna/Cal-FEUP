#ifndef EMERITAHEALTH_H
#define EMERITAHEALTH_H

#include <string>
#include <vector>
#include<iostream>
#include <math.h>
#include <algorithm>
#include <cmath>
#include "../Graph/Graph.h"
#include "../Utilities/ReadFiles.h"
#include "../GraphViewer/graphviewer.h"
#include "../GraphViewer/edgetype.h"

using  namespace std;

class EmeritaHealth {

    vector <MapPoint*>points;
    vector<ConnectPoints*>connectP;
    GraphViewer *gv;
    EdgeType edgeType;
    Graph<unsigned long> graph;

public:

    //Files Methods
    void loadFiles();

    //graph Methods
    Graph<unsigned long> constructGraph();
    double distanceTwoPoints(unsigned long pointX1,unsigned long pointY1,
                             unsigned long pointX2,unsigned long pointY2);

    GraphViewer* generateGraphForNodes();
    GraphViewer* generateGVnodes(double minX, double minY, double maxX, double maxY, bool drawEdges, int vertexSize, const string &vertexColor, bool dashedEdges);

    void createViewer();


};


#endif //EMERITAHEALTH_H
