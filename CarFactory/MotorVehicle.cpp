//
// Created by Michał on 09.12.2020.
//
#include "MotorVehicle.h"
#include "Exception.h"

using namespace std;

MotorVehicle::MotorVehicle(const std::string &_color, const std::string &_brand): Vehicle(_color,_brand), mileage(0), fuel(25){}
void MotorVehicle::drive(double new_mileage)
{
    if (new_mileage < 0) throw drive_error("Nie mozna przejechac ujemnego dystansu!");
    if(new_mileage*0.06>=fuel)throw drive_error("Za malo paliwa na tak dluga jazde!");

    mileage += new_mileage;
    fuel -= new_mileage*0.06;
}
