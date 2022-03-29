//
// Created by Michał on 09.12.2020.
//
#include <iostream>
#include "Car.h"

using namespace std;
Car::Car(const std::string &_color, const std::string &_brand, int _doors): MotorVehicle(_color,_brand), doors(_doors){};

void Car::info()
{
    cout<<"Marka : "<<brand<<endl;
    cout<<"Kolor: "<<color<<endl;
    cout<<"Cena: "<<price<<endl;
    cout<<"Wlasciciel: "<<owner<<endl;
    cout<<"Przebieg: "<<mileage<<endl;
    cout<<"Liczba drzwi: "<<doors<<endl;
    cout<<"Ilosc paliwa: "<<fuel<<endl;
    cout<<"Ladownosc: "<< capacity()<<endl;
    cout<<endl;
}
