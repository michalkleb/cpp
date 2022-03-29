//
// Created by Michał on 09.12.2020.
//
#include <iostream>
#include "Vehicle.h"
#include "memory"

using namespace std;

Vehicle::Vehicle(const std::string &_color, const std::string &_brand,  const std::string& _owner ):brand(_brand), color(_color),  owner(_owner)
{
    if(_brand == "Yamaha"){trunk = 20; price = 1000;}
    else if(_brand == "Honda") {trunk = 25; price = 1100;}
    else if(_brand == "Audi") {trunk = 600; price = 40000;}
    else if(_brand == "Volkswagen") {trunk = 700;price = 45000;}
}


void Vehicle::info()
{
    cout<<"Marka : "<<brand<<endl;
    cout<<"Kolor: "<<color<<endl;
    cout<<"Cena: "<<price<<endl;
    cout<<"Wlasciciel: "<<owner<<endl;
    cout<<endl;
}


//Przeladowanie operatora wypisania
std::ostream &operator<<(std::ostream &out, Vehicle &vehicle) {
    out << vehicle.brand << " " << vehicle.color << " " <<vehicle.price<<" "<< vehicle.owner;
    return out;
}
