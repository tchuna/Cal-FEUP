#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Emirita/EmeritaHealth.h"
#include "Graph/Graph.h"


using namespace std;

int main() {
    Graph<unsigned long> graph;

    EmeritaHealth emeritaHealth;
    emeritaHealth.createViewer();
    graph=emeritaHealth.constructGraph();





	/*ReadFiles map;
	vector <MapPoint*>node;
	vector <ConnectPoints*>edg;


	node=map.loadMapPoints();
	edg=map.loadConects();

	int result=node.size();

	cout<<"Nodes"<<endl;
	for(int i=0; i < result;i++){
		node[i]->print();

	}
	cout<<endl;


    result=edg.size();
    cout<<"Edges"<<endl;
    for(int i=0; i < result;i++){
        edg[i]->print();

    }
	cout<<endl;
	cout<<result<<endl;*/



	return 0;
}
