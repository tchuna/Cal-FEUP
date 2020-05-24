#ifndef EXAMPLE_MENU_H
#define EXAMPLE_MENU_H
#include "../Emirita/GraphWorkout.h"

class Menu {
    GraphWorkout emeritaHealth;

public:
    Menu(GraphWorkout emeritaHealth){
        this->emeritaHealth = emeritaHealth;
    }

    void start();
    void showMainMenu();

    void showBasic();
    void showMapPoints();
    void showMapEdges();
    void showVehicles();
    void showNursingHomes();
    void showHealthCareLocations();

    void showTestMenu();
    void oneVoneIHARD();
    void oneVoneI();
    void oneVmulI();
    void oneVehicleUrgent();
    void mulVmulI();
    void drawGraphFromFile(std::string name, unsigned int port, vector<Vertex<MapPoint> *> path);

};


#endif //EXAMPLE_MENU_H
