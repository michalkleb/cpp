//
// Created by Michał on 09.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_MOTORBIKE_H
#define KLEBUKOWSKIMICHAL_ETAP2_MOTORBIKE_H

#include <string>
#include<iostream>
#include "MotorVehicle.h"


class Motorbike: public MotorVehicle {
public:
    Motorbike(const std::string &_color, const std::string &_brand);

    void info() override;
};

#endif //KLEBUKOWSKIMICHAL_ETAP2_MOTORBIKE_H
