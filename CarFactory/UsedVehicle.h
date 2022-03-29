//
// Created by Michał on 17.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_USEDVEHICLE_H
#define KLEBUKOWSKIMICHAL_ETAP2_USEDVEHICLE_H
#include <string>
#include<memory>
#include<vector>
#include "Vehicle.h"

//Klasa reprezentująca komis samochodowy
class UsedVehicle{
    std::vector < std::shared_ptr<Vehicle> > motor_vehicles;
public:
    void add( const std::shared_ptr<Vehicle> &vehicle); //dodanie pojazdu do komisu
    int get_size(){return motor_vehicles.size();}       //zwracam ilosc pojazdów będących w komisie
    void more_info(int index);
    std::shared_ptr<Vehicle> sell(int index, std::string &customer);           //sprzedaję i usuwam pojazd
    void print();
    void drive(int index, int length);
    bool is_valid(int index){return !motor_vehicles[index];}
};
#endif //KLEBUKOWSKIMICHAL_ETAP2_USEDVEHICLE_H
