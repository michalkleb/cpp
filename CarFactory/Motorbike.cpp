//
// Created by Michał on 09.12.2020.
//
#include <iostream>
#include "Motorbike.h"

using namespace std;

Motorbike::Motorbike(const std::string &_color, const std::string &_brand): MotorVehicle(_color,_brand) {}

void Motorbike::info()
{
    cout<<"Marka : "<<brand<<endl;
    cout<<"Kolor: "<<color<<endl;
    cout<<"Wlasciciel: "<<owner<<endl;
    cout<<"Przebieg: "<<mileage<<endl;
    cout<<"Ilość paliwa: "<<fuel<<endl;
    cout<<endl;
}