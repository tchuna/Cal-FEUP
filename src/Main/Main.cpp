#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include "../Utilities/ReadFiles.h"
#include "MapPoint.h"

using namespace std;

int main() {

	ReadFiles map;
	vector <MapPoint*>node;
	vector <ConectPoints*>edg;


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
	cout<<result<<endl;


	getchar();

	return 0;
}
