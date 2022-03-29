//
// Created by Michał on 09.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_BICYCLE_H
#define KLEBUKOWSKIMICHAL_ETAP2_BICYCLE_H

#include <string>
#include<iostream>
#include "Vehicle.h"


class Bicycle: public Vehicle {
    int carrige;
public:
    Bicycle(const std::string &_color, const std::string &_brand, int _carrige);
    void info() override;
    int capacity() const override {return carrige;}
};
#endif //KLEBUKOWSKIMICHAL_ETAP2_BICYCLE_H
