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
    void normalElders();
    void emergencyElders();

};


#endif //EXAMPLE_MENU_H
