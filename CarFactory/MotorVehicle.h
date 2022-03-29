//
// Created by Michał on 09.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_MOTORVEHICLE_H
#define KLEBUKOWSKIMICHAL_ETAP2_MOTORVEHICLE_H

#include <string>
#include<iostream>
#include "Vehicle.h"


class MotorVehicle: public Vehicle {
protected:
    double mileage;
    double fuel;

public:
    MotorVehicle(const std::string &_color, const std::string &_brand);
    void drive(double new_mileage) override;                            //zwiekszam przebieg
    double get_mileage ()override {return mileage;}                     //zwrcam przebieg
    void set_mileage(double _mileage)override{mileage = _mileage;}      //dokonuje zmian w przebiegu

};
#endif //KLEBUKOWSKIMICHAL_ETAP2_MOTORVEHICLE_H
