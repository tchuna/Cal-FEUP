
#ifndef HEALTCARE_H
#define HEALTCARE_H
#include "Vehicle.h"


class HealthStation {
    MapPoint mapPoint;
    int type;

public:

    HealthStation(MapPoint node,int type){

        this->type=type;
        this->mapPoint=node;

    }

    int getType();
    MapPoint getMapPoint();
    void print();
    bool operator==(const HealthStation & hs) const;
    
};


#endif //HEALTCARE_H
