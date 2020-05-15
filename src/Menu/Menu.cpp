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
        cout << "2 - ";
        cout << "0 - Exit\n\n";

        cout << "Option: ";
        cin >> nextMenu;

        switch (nextMenu) {
            case 1:
                showBasic();
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