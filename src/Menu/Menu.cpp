#include "Menu.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "graphviewer.h"

void Menu::start() {
    showMainMenu();

}

void Menu::showMainMenu() {
    int nextMenu = -1;
    while(nextMenu != 0) {
        cout << "\nMain Menu\n";
        string input;
        cout << "1 - Show Basic\n";
        cout << "2 - Show Tests\n";
        cout << "0 - Exit\n\n";

        cout << "Option: ";
        cin >> nextMenu;

        switch (nextMenu) {
            case 1:
                showBasic();
                break;
            case 2:
                showTestMenu();
                break;
            default:
                break;
        }
    }

}

void Menu::showBasic() {
    int nextMenu = -1;
    while(nextMenu != 0){
        cout << "\nShow Basic Menu\n";
        cout << "1 - Show Vertex\n";
        cout << "2 - Show Edges\n";
        cout << "3 - Show Vehicles\n";
        cout << "4 - Show Nursing Homes\n";
        cout << "5 - Show HealthCare Locations\n";
        cout << "0 - Exit\n\n";

        cout << "Option: ";
        cin >> nextMenu;

        switch (nextMenu) {
            case 0:
                break;
            case 1:
                showMapPoints();
                break;
            case 2:
                showMapEdges();
                break;
            case 3:
                showVehicles();
                break;
            case 4:
                showNursingHomes();
                break;
            case 5:
                showHealthCareLocations();
                break;
        }
    }

}

void Menu::showMapPoints(){
    for(unsigned int i = 0; i < emeritaHealth.originalGraph->getVertexSet().size(); i++) {
        cout << "Point["<< i << "]: ";
        emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().print();
    }
}

void Menu::showMapEdges(){ //TODO
    for(unsigned int i = 0; i < emeritaHealth.connectP.size(); i++) {
        cout << "Edge["<< i << "]: ";
        emeritaHealth.connectP[i]->print();
    }
}

void Menu::showVehicles(){
    for(unsigned int i = 0; i < emeritaHealth.vehicles.size(); i++) {
        cout << "Vehicle["<< i << "]: ";
        emeritaHealth.vehicles[i]->print();
    }
}
void Menu::showNursingHomes(){
    for(unsigned int i = 0; i < emeritaHealth.nursingHome.size(); i++) {
        cout << "NursingHome["<< i << "]: ";
        cout << emeritaHealth.nursingHome[i]->getMapPoint().getID() << " " <<
        emeritaHealth.nursingHome[i]->getElderlyNumber() << " " <<
        emeritaHealth.nursingHome[i]->getMapPoint().getX() << " " <<
        emeritaHealth.nursingHome[i]->getMapPoint().getY() << endl;
    }
}
void Menu::showHealthCareLocations(){
    for(unsigned int i = 0; i < emeritaHealth.healthCareLocation.size(); i++) {
        cout << "HealthCare["<< i << "]: ";
        cout << emeritaHealth.healthCareLocation[i]->getMapPoint().getID() << " " <<
             emeritaHealth.healthCareLocation[i]->getMapPoint().getX() << " " <<
             emeritaHealth.healthCareLocation[i]->getMapPoint().getY() << endl;
    }
}

void Menu::showTestMenu() {
    int nextMenu = -1;
    while(nextMenu != 0){
        cout << "\nTest Menu\n";
        cout << "1 - One Vehicle One Iteneration\n";
        cout << "2 - On vehicle Multiple Iteneration\n";
        cout << "3 - One Vehicle One Iteneration HARD\n";
        cout << "0 - Exit\n\n";

        cout << "Option: ";
        cin >> nextMenu;

        switch (nextMenu) {
            case 0:
                break;
            case 1:
                oneVoneI();
                break;
            case 2:
                oneVmulI();
                //TODO
                break;
            case 3:
                oneVoneIHARD();
                break;
        }
    }
}

void Menu::oneVoneIHARD() {
    cout << "\n\nOne Vehicle One iteneration HARD\n\n";
    cout << "\n NursingHomes\n";
    showNursingHomes();
    cout << "\nSelect NursingHomes by ID: ";
    int nsID;
    cin >> nsID;
    cin.clear();
    NursingHome * ns = emeritaHealth.nursingHome[nsID];


    HealthStation * hs;

    vector<Vehicle*> vehiclesWithPath;
    vector<vector<Vertex<MapPoint> * >> vehiclesPath;

    vector<HealthStation*> healthWithPath;
    vector<vector<Vertex<MapPoint> * >> healthPath;

    vector<Vertex<MapPoint> * > path;

    for(unsigned int i = 0; i < emeritaHealth.vehicles.size(); i++) {
        path = emeritaHealth.oneVehicleOneItineration(emeritaHealth.vehicles[i], hs, ns, 1);
        if(path.size() > 0) {
            vehiclesPath.push_back(path);
            vehiclesWithPath.push_back(emeritaHealth.vehicles[i]);
        }

    }
    cout << "\nListing Vehicles with path: ";
    for(unsigned int j = 0; j < vehiclesWithPath.size(); j++) {
        cout << "ID: "<< j;
        vehiclesWithPath[j]->print();
    }

    /*
    for(unsigned int k = 0; k < emeritaHealth.healthCareLocation.size(); k++) {
        if(k == 2) continue;
        cout << "\nBEFOREBOOM: " << k << endl;
        path = emeritaHealth.oneVehicleOneItineration(emeritaHealth.vehicles[0], emeritaHealth.healthCareLocation[k], ns, 2);
        if(path.size() > 0) {
            healthPath.push_back(path);
            healthWithPath.push_back(emeritaHealth.healthCareLocation[k]);
        }

    }

    cout << "\nListing HealthStation with path: ";
    for(unsigned int j = 0; j < healthWithPath.size(); j++) {
        cout << "ID: "<< j;
        healthWithPath[j]->print();
    }*/


}

void Menu::oneVoneI() {


    cout << "\n\nOne Vehicle One iteneration\n\n";
    showVehicles();
    cout << "\nSelect vehicle by ID: ";
    int vID;
    cin >> vID;

    cout << "\n HealhStationsn\n";
    showHealthCareLocations();
    cout << "\nSelect vehicle by ID: ";
    int hsID;
    cin >> hsID;

    cout << "\n NursingHomes\n";
    showNursingHomes();
    cout << "\nSelect NursingHomes by ID: ";
    int nsID;
    cin >> nsID;

    Vehicle * v = emeritaHealth.vehicles[vID];
    HealthStation * hs = emeritaHealth.healthCareLocation[hsID];
    NursingHome * ns = emeritaHealth.nursingHome[nsID];

    vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleOneItineration(v,hs, ns, 0);

    cout << "\nPath:" << endl;
    for (int i=0; i < result.size(); i++) {
        result[i]->getInfo().print();
    }

    drawGraphFromFile("teste", 1234, result);
}

void Menu::oneVmulI() {

    cout << "\n\nOne Vehicle One iteneration\n\n";
    showVehicles();
    cout << "\nSelect vehicle by ID: ";
    int vID;
    cin >> vID;

    cout << "\n HealhStationsn\n";
    showHealthCareLocations();
    cout << "\nSelect vehicle by ID: ";
    int hsID;
    cin >> hsID;


    Vehicle * v = emeritaHealth.vehicles[vID];
    HealthStation * hs = emeritaHealth.healthCareLocation[hsID];

    vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleMultipleItineration(v, hs);

    cout << "\nPath:" << endl;
    for (int i=0; i < result.size(); i++) {
        result[i]->getInfo().print();
    }
    unsigned int port = 1234;
    std:string test = "test";
    drawGraphFromFile(test, port, result);
}

void Menu::drawGraphFromFile(std::string name,unsigned int port, vector<Vertex<MapPoint> *> path){
    std::ifstream nodes("../files/maps/16x16/nodes.txt");
    std::ifstream edges("../files/maps/16x16/edges.txt");
    std::ifstream window("../files/maps/window.txt");

    std::string line, background_path;
    std::istringstream iss;
    unsigned int n_nodes, n_edges, height, width, v1, v2, type, scale, dynamic, thickness, size, dashed, curved;
    float x, y;
    int id;
    char color[20], icon_path[256], flow[256], weight[256];

    window >> width >> height >> dynamic >> scale >> dashed >> curved >> background_path;
    GraphViewer *gv = new GraphViewer(width, height, dynamic, port);
    gv->setBackground(background_path);
    gv->createWindow(width, height);
    gv->defineEdgeDashed(dashed);
    gv->defineEdgeCurved(curved);

    // read num of nodes
    std::getline(nodes, line);
    iss.str(line);
    iss >> n_nodes;

    // draw nodes
    string nodeDefaultColor = "yellow";
    string nodePathColor = "red";
    string nursingColor = "blue";
    string healthColor = "green";
    string label;
    size = 10;
    icon_path[0] = '-';
    for(unsigned int i = 0; i < emeritaHealth.originalGraph->getVertexSet().size(); i++) {
        gv->addNode(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(),
                    emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getX(),
                    emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getY());
        gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), nodeDefaultColor);

        for(unsigned int k = 0; k < emeritaHealth.getNursingHomesID().size(); k++) {
                if(emeritaHealth.getNursingHomesID()[k] == emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID())
                    gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), nursingColor);

        }
        for(unsigned int k = 0; k < emeritaHealth.getHealthStationID().size(); k++) {
            if(emeritaHealth.getHealthStationID()[k] == emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID())
                gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), healthColor);
        }


//        for(unsigned int j = 0; j < path.size(); j++) {
//
//            if(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID() == path[j]->getInfo().getID()) {
//                gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), nodePathColor);
//
//                break;
//            }
//        }
        gv->setVertexLabel(i, "Node " + to_string(i));
        if (icon_path[0] != '-')
            gv->setVertexIcon(i, std::string(icon_path));
        gv->setVertexSize(i, size);
    }


    // read num of edges
    std::getline(edges, line);
    sscanf( line.c_str(), "%d", &n_edges);

    //draw edges
    type = EdgeType::DIRECTED;
    string defaultEdgeColor = "black";
    string pathEdgeColor = "red";
    thickness = 1;
    label[0] = '-';
    flow[0] = '%';
    weight[0] = '%';

    int edgeId = 0;

    for(unsigned int i = 0; i < emeritaHealth.originalGraph->getVertexSet().size(); i++)  {
//        if(emeritaHealth.originalGraph->getVertexSet()[i]->getAdj().size()){
//            cout << "Node " << emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID()<< endl;
//        }

        for(unsigned int j = 0; j < emeritaHealth.originalGraph->getVertexSet()[i]->getAdj().size(); j++) {
            edgeId++;
            (type)? gv->addEdge(edgeId,emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(),
                    emeritaHealth.originalGraph->getVertexSet()[i]->getAdj()[j].getNode()->getInfo().getID(),
                    EdgeType::DIRECTED): gv->addEdge(edgeId, emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(),
                                                     emeritaHealth.originalGraph->getVertexSet()[i]->getAdj()[j].getNode()->getInfo().getID()
                                                     , EdgeType::UNDIRECTED);

            gv->setEdgeColor(edgeId, defaultEdgeColor);
            for(unsigned int k = 0; k < path.size(); k++) {
                if(k+1 == path.size()) break;
                if (emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID() == path[k]->getInfo().getID()) {
                    if (emeritaHealth.originalGraph->getVertexSet()[i]->getAdj()[j].getNode()->getInfo().getID() ==
                        path[k + 1]->getInfo().getID()) {
                        gv->setEdgeColor(edgeId, pathEdgeColor);
                        break;
                    }
                }
            }
                gv->setEdgeThickness(edgeId, thickness);
                if (label[0] != '-')
                    gv->setEdgeLabel(edgeId, label);
                if (flow[0] != '%')
                    gv->setEdgeFlow(edgeId, atoi(flow));
                if (weight[0] != '%')
                    gv->setEdgeWeight(edgeId, atoi(weight));
            }
        }

    gv->rearrange();
}