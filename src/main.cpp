#include <iostream>
#include <vector>
#include <cstdio>
#include "Utilities/ReadFiles.h"
#include "Map/MapPoint.h"
#include "Graph/Graph.h"
#include "../Emirita/GraphWorkout.h"


using namespace std;

int main() {
    Graph<unsigned long> graph;

    GraphWorkout emeritaHealth;
    emeritaHealth.constructGraph();

	return 0;
}
