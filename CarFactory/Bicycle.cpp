//
// Created by Michał on 09.12.2020.
//
#include <iostream>
#include "Bicycle.h"

using namespace std;


Bicycle::Bicycle(const std::string &_color, const std::string &_brand, int _carrige): Vehicle(_color,_brand),carrige(_carrige)
{
    if(_carrige) trunk = 10;
    price=300;
}

void Bicycle::info()
{
    cout<<"Marka : "<<brand<<endl;
    cout<<"Kolor: "<<color<<endl;
    cout<<"Wlasciciel: "<<owner<<endl;
    cout<<"Ladownosc: "<< capacity()<<endl;
    cout<<endl;
}
