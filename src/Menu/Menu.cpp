#include "Menu.h"
#include <iostream>

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
    for(unsigned int i = 0; i < emeritaHealth.points.size(); i++) {
        cout << "Point["<< i << "]: ";
        emeritaHealth.points[i]->print();
    }
}

void Menu::showMapEdges(){
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
        cout << emeritaHealth.nursingHome[i]->getId() << " " <<
        emeritaHealth.nursingHome[i]->getElderly().size() << " " <<
        emeritaHealth.nursingHome[i]->getVehicle().size() << " " <<
        emeritaHealth.nursingHome[i]->getXposition() << " " <<
        emeritaHealth.nursingHome[i]->getYposition() << endl;
    }
}
void Menu::showHealthCareLocations(){
    for(unsigned int i = 0; i < emeritaHealth.healthCareLocation.size(); i++) {
        cout << "HealthCare["<< i << "]: ";
        cout << emeritaHealth.healthCareLocation[i]->getId() << " " <<
             emeritaHealth.healthCareLocation[i]->getVehicle().size()<< " " <<
             emeritaHealth.healthCareLocation[i]->getXposition() << " " <<
             emeritaHealth.healthCareLocation[i]->getYposition() << endl;
    }
}

void Menu::showTestMenu() {
    int nextMenu = -1;
    while(nextMenu != 0){
        cout << "\nTest Menu\n";
        cout << "1 - Normal Elders to HealthCare\n";
        cout << "2 - Emergency Elder to HealthCare\n";
        cout << "0 - Exit\n\n";

        cout << "Option: ";
        cin >> nextMenu;

        switch (nextMenu) {
            case 0:
                break;
            case 1:
                normalElders();
                break;
            case 2:
                //emergencyElders();
                //TODO
                break;
        }
    }
}

void Menu::normalElders() {
    cout << "\nNormal Elders test\n";

    cout << "Nursing Homes List\n";
    showNursingHomes();

    int nursingHomeID;
    cout << "\nSelect Nursing Home ID: ";
    cin >> nursingHomeID;

    cout << "\nHealthCare List\n";
    showHealthCareLocations();

    int healthCareID;
    cout << "\nSelect HealthCare ID: ";
    cin >> healthCareID;

    int numberOfNormalElders = 0;

    vector<Elderly*> elders;
    vector<Vehicle*> vehicles;
    vector<Vehicle*> vehiclesToGo;
    HealthStation * healthCare;

    //getHealthCare

    for(unsigned int i = 0; i < emeritaHealth.healthCareLocation.size(); i++) {
        if(healthCareID == emeritaHealth.healthCareLocation[i]->getId()) {
            healthCare = emeritaHealth.healthCareLocation[i];
            break;
        }
    }


    //get elders and vehicles from nursingHome
    for(unsigned int i = 0; i < emeritaHealth.nursingHome.size(); i++) {
        if(emeritaHealth.nursingHome[i]->getId() == nursingHomeID){
            elders = emeritaHealth.nursingHome[i]->getElderly();
            vehicles = emeritaHealth.nursingHome[i]->getVehicle();
        }
    }
    //get number of normal elders
    for(unsigned int i = 0; i < elders.size(); i++) {
        if(elders[i]->getUrgency() == false)
            numberOfNormalElders++;
    }

    //distribute elders to vehicles
    for(unsigned int i = 0; i < vehicles.size(); i++) {
        for(unsigned j = 0; j < elders.size(); i++) {
            if(elders[j]->getUrgency() == false) {
                if(vehicles[i]->getVehicleType() == 0 && vehicles[i]->getOccupants().size() < vehicles[i]->getVehicleCapacity()){
                    numberOfNormalElders--;
                    vehicles[i]->addOccupants(elders[j]);
                    elders.erase(elders.begin()+j);
                    j--;
                    if(vehicles[i]->getOccupants().size() == vehicles[i]->getVehicleCapacity()){
                        vehiclesToGo.push_back(vehicles[i]);
                        vehicles.erase(vehicles.begin()+i);
                        i--;
                        break;  //next vehicle
                    }
                }
            }
        }
    }

    //save vehicles and elders to emeritas
    for(unsigned int i = 0; i < emeritaHealth.nursingHome.size(); i++) {
        if(emeritaHealth.nursingHome[i]->getId() == nursingHomeID){
            emeritaHealth.nursingHome[i]->setElderly(elders);
            emeritaHealth.nursingHome[i]->setVehicle(vehicles);
        }
    }

    //check if all elders have transport
    if(numberOfNormalElders > 0){
        cout << "\nNot all elders have transportation available\n";
    }

    vector<vector<Vertex<MapPoint> * >> paths;
    //Go Vehicles
    for(unsigned int i = 0; i < vehiclesToGo.size(); i++){
        paths.push_back(emeritaHealth.OneVehicleOneItineration(vehiclesToGo[i], healthCare));
    }

    //print results
    for(unsigned int i = 0; i < paths.size(); i++){
        for(unsigned int j = 0; j < paths[i].size(); j++){
            cout << "Point[" << j << "]: " << paths[i][j]->getX() << " " << paths[i][j]->getY();
        }
    }

}

void Menu::emergencyElders() {
    //TODO
    /*
     * 1 - Search nearest emergency vehicle for elder
        * - search all healthCare for an emergency vehicle
        * - for every vehicle calculate distance to nursinghome
        * - update vehicle with minimum distance
        * - remove from station/update status
    2 - Save path from origin HealthCare
    3 - Calculate path to nearest HealthCare
    4 - Remove Elder from nursingHome
    5 - update vehicle status?
    */
}