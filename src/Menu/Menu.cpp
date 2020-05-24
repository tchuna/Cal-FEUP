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
                showVehicles(0, emeritaHealth.vehicles);
                break;
            case 4:
                showNursingHomes();
                break;
            case 5:
                showHealthCareLocations(0, emeritaHealth.healthCareLocation);
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

void Menu::showVehicles(int show, vector<Vehicle *> vehicles){
    //show = 0 - all
    //show = 1 - urgent
    //show = 2 - normal
    if(vehicles.size() == 0) {
        cout << "\nNo Vehicles Available\n";
        exit(-1);
    }
    for(unsigned int i = 0; i < vehicles.size(); i++) {
        if(show == 0){
            cout << i <<" - Vehicle ID: "<< vehicles[i]->getMapPoint().getID();
            if(vehicles[i]->getVehicleType() == 1)
                cout << "   Type: Ambulance   Point: ";
            else
                cout << "   Type: Normal   Point: ";
            vehicles[i]->getMapPoint().print();
        }
        else if(show == 1)  {
            if(vehicles[i]->getVehicleType() == 1)
                cout << i <<" - Vehicle ID: "<< vehicles[i]->getMapPoint().getID();
                cout << "   Type: Ambulance   Point: ";
            vehicles[i]->getMapPoint().print();
        }
        else if(show == 2)  {
            if(vehicles[i]->getVehicleType() == 0)
                cout << i <<" - Vehicle ID: "<< vehicles[i]->getMapPoint().getID();
            cout << "   Type: Normal   Point: ";
            vehicles[i]->getMapPoint().print();
        }
    }
}

void Menu::showNursingHomes(){
    for(unsigned int i = 0; i < emeritaHealth.nursingHome.size(); i++) {
        cout << i << " - NursingHome ID: " << emeritaHealth.nursingHome[i]->getMapPoint().getID();
        cout << "     ElderNumber: " << emeritaHealth.nursingHome[i]->getElderlyNumber() << "   ";
        cout << "   Point: "; emeritaHealth.nursingHome[i]->getMapPoint().print();

    }
}

void Menu::showHealthCareLocations(int show, vector<HealthStation *> hs){
    for(unsigned int i = 0; i < emeritaHealth.healthCareLocation.size(); i++) {
        if(show == 0) {
            cout << i << " - HealthCare ID: " << emeritaHealth.healthCareLocation[i]->getMapPoint().getID();
            if(emeritaHealth.healthCareLocation[i]->getType() == 1)
                cout << "   Type: Hospital   Point: ";
            else
                cout << "   Type: HealthCenter   Point: ";
            emeritaHealth.healthCareLocation[i]->getMapPoint().print();
        }
        else if(show == 1) {
            if(emeritaHealth.healthCareLocation[i]->getType() == 1) {
                cout << i << " - HealthCare ID: " << emeritaHealth.healthCareLocation[i]->getMapPoint().getID();
                cout << "   Type: Hospital   Point: ";
                emeritaHealth.healthCareLocation[i]->getMapPoint().print();
            }
        }
        else if(show == 2) {

            if(emeritaHealth.healthCareLocation[i]->getType() == 0){
                cout << i << " - HealthCare ID: " << emeritaHealth.healthCareLocation[i]->getMapPoint().getID();
                cout << "   Type: HealthCenter   Point: ";
                emeritaHealth.healthCareLocation[i]->getMapPoint().print();
            }
        }
    }
}

void Menu::showTestMenu() {
    int nextMenu = -1;
    while(nextMenu != 0){
        cout << "\nTest Menu\n";
        cout << "1 - One Vehicle Normal\n";
        cout << "2 - One Vehicle Urgent\n";
        cout << "3 - On vehicle Multiple Iteneration\n";
        cout << "4 - Multiple Vehicle Multiple Iteneration\n";
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
                oneVehicleUrgent();
                //TODO
                break;
            case 3:
                oneVmulI();
                break;
            case 4:
                mulVmulI();
                break;
        }
    }
}

void Menu::oneVehicleUrgent() {
    cout << "\nUrgent Transportation\n";
    cout << "\n NursingHomes\n";
    showNursingHomes();
    cout << "\nSelect NursingHomes by ID: ";
    int nsID;
    cin >> nsID;

    NursingHome * nh = emeritaHealth.nursingHome[nsID];

    Vehicle * v = emeritaHealth.nearVehicle(nh->getMapPoint(),1);
    HealthStation * hs = emeritaHealth.nearHealthStation(nh->getMapPoint(), 0);

    vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleOneItineration(v, hs, nh, 0);
    vector<vector<Vertex<MapPoint>*>> path;
    path.push_back(result);

    drawGraphFromFile("teste", 5555, path);

}

void Menu::oneVoneI() {

    cout << "\n NursingHomes\n";
    showNursingHomes();
    cout << "\nSelect NursingHomes by ID: ";
    int nsID;
    cin >> nsID;
    cin.clear();

    NursingHome * ns = emeritaHealth.nursingHome[nsID];
    HealthStation * hs = emeritaHealth.healthCareLocation[0];
    Vehicle * v = emeritaHealth.vehicles[0];

    vector<Vehicle *>  vehiclesWithPath;
    vector<HealthStation *>  healthStationWithPath;

    for(unsigned int i = 0; i < emeritaHealth.vehicles.size(); i++) {
        vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleOneItineration(emeritaHealth.vehicles[i], hs, ns, 1);
        if(result.size() > 0)
            vehiclesWithPath.push_back(emeritaHealth.vehicles[i]);
    }

    /*for(unsigned int i = 0; i < vehiclesWithPath.size(); i++) {
        if(vehiclesWithPath[i]->getVehicleType() != show) {
            vehiclesWithPath.erase(vehiclesWithPath.begin() + i);
            i--;
        }
    }*/
    if(vehiclesWithPath.size() == 0){
        cout << "\nNo Vehicles Available";
        exit(-1);
    }

    cout << "\n\nOne Vehicle One iteneration\n\n";
    showVehicles(0, vehiclesWithPath);
    cout << "\nSelect vehicle by ID: ";
    int vID;
    cin >> vID;

    int show = vehiclesWithPath[vID]->getVehicleType();

    for(unsigned int i = 0; i < emeritaHealth.healthCareLocation.size(); i++) {
        vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleOneItineration(v, emeritaHealth.healthCareLocation[i], ns, 2);
        if(result.size() > 0)
            if(emeritaHealth.healthCareLocation[i]->getType() == show)
                healthStationWithPath.push_back(emeritaHealth.healthCareLocation[i]);
    }

    if(healthStationWithPath.size() == 0){
        cout << "\nNo HealthCare Locations Available";
        exit(-1);
    }

    cout << "\nHealhStations\n";
    showHealthCareLocations(show, healthStationWithPath);
    cout << "\nSelect HealthhCare: ";
    int hsID;
    cin >> hsID;

    vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleOneItineration(vehiclesWithPath[vID],healthStationWithPath[hsID], ns, 0);
    vector<vector<Vertex<MapPoint>*>> path;
    path.push_back(result);

    cout << "\nPath:" << endl;
    for (int i=0; i < result.size(); i++) {
        result[i]->getInfo().print();
    }

    drawGraphFromFile("teste", 1234, path);
}

void Menu::oneVmulI() {

    cout << "\n\nOne Vehicle One iteneration\n\n";
    showVehicles(0, emeritaHealth.vehicles);
    cout << "\nSelect vehicle by ID: ";
    int vID;
    cin >> vID;

    cout << "\n HealhStationsn\n";
    showHealthCareLocations(0, emeritaHealth.healthCareLocation);
    cout << "\nSelect vehicle by ID: ";
    int hsID;
    cin >> hsID;


    Vehicle * v = emeritaHealth.vehicles[vID];
    HealthStation * hs = emeritaHealth.healthCareLocation[hsID];

    vector<Vertex<MapPoint> *> result = emeritaHealth.oneVehicleMultipleItineration(v);
    vector<vector<Vertex<MapPoint>*>> path;
    path.push_back(result);

    cout << "\nPath:" << endl;
    for (int i=0; i < result.size(); i++) {
        result[i]->getInfo().print();
    }
    unsigned int port = 4321;
    std:string test = "test";
    drawGraphFromFile(test, port, path);
}

void Menu::mulVmulI() {
    cout << "\nMultiples Vehicles Multiple Itineration\n";
    showVehicles(0, emeritaHealth.vehicles);
    showNursingHomes();
    showHealthCareLocations(0, emeritaHealth.healthCareLocation);
    vector<vector<Vertex<MapPoint> *>> result = emeritaHealth.multipleVehicleMultipleItineration();
    drawGraphFromFile("mulVmulI", 5555, result);
}

void Menu::drawGraphFromFile(std::string name,unsigned int port, vector<vector<Vertex<MapPoint>*>> path){
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
    GraphViewer *gv = new GraphViewer(width, height, dynamic, 5002);
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
    //string nodePathColor = "red";
    string nursingColor = "blue";
    string urgentHealthColor = "red";
    string normalHealthColor = "green";
    string vehicleColor = "gray";

    vector<string> colors;
    colors.push_back("red");
    colors.push_back("pink");
    colors.push_back("orange");
    colors.push_back("cyan");
    colors.push_back("magenta");
    colors.push_back("dark_gray");


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
        for(unsigned int k = 0; k < emeritaHealth.getUrgentHealthID().size(); k++) {
            if(emeritaHealth.getUrgentHealthID()[k] == emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID())
                gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), urgentHealthColor);
        }
        for(unsigned int k = 0; k < emeritaHealth.getNormalHealthID().size(); k++) {
            if(emeritaHealth.getNormalHealthID()[k] == emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID())
                gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), normalHealthColor);
        }
        for(unsigned int k = 0; k < emeritaHealth.getVehiclesID().size(); k++) {
            if(emeritaHealth.getVehiclesID()[k] == emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID())
                gv->setVertexColor(emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID(), vehicleColor);
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
    int thicknessPath = 6;
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
            gv->setEdgeThickness(edgeId, thickness);
            int auxColors = 0;
            for(unsigned int z = 0; z < path.size(); z++, auxColors++){
                cout << "\nVehicle: " << z << endl;
                if(auxColors == colors.size())
                    auxColors = 0;
                pathEdgeColor = colors[auxColors];
                for(unsigned int k = 0; k < path[z].size(); k++) {
                    cout << "\nID: " << path[z][k]->getInfo().getID();
                    if(k+1 == path[z].size()) break;
                    if (emeritaHealth.originalGraph->getVertexSet()[i]->getInfo().getID() == path[z][k]->getInfo().getID()) {
                        if (emeritaHealth.originalGraph->getVertexSet()[i]->getAdj()[j].getNode()->getInfo().getID() ==
                            path[z][k + 1]->getInfo().getID()) {
                            gv->setEdgeColor(edgeId, pathEdgeColor);
                            gv->setEdgeThickness(edgeId, thicknessPath);
                            break;
                        }
                    }
                }
            }

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