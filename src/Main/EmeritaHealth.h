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

using  namespace std;

class EmeritaHealth {

    vector <MapPoint*>points;
    vector<ConnectPoints*>connectP;
    GraphViewer *gv;
    Graph<unsigned long> graph;

public:

    //Files Methods
    void loadFiles();

    //graph Methods
    void constructGraph();
    double distanceTwoPoints(unsigned long pointX1,unsigned long pointY1,
                             unsigned long pointX2,unsigned long pointY2);


};


#endif //EMERITAHEALTH_H
