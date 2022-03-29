//
// Created by Michał on 09.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_CAR_H
#define KLEBUKOWSKIMICHAL_ETAP2_CAR_H

#include <string>
#include<iostream>
#include "MotorVehicle.h"


class Car: public MotorVehicle {
    int doors;
public:
    Car(const std::string &_color, const std::string &_brand, int _doors);
    void info() override;
};

#endif //KLEBUKOWSKIMICHAL_ETAP2_CAR_H
