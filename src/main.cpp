#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Main/MapPoint.h"
#include "Main/EmeritaHealth.h"

using namespace std;

int main() {

    EmeritaHealth emeritaHealth;
    emeritaHealth.constructGraph();



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
