//
// Created by Michał on 17.12.2020.
//
#include "UsedVehicle.h"
#include"Exception.h"
#include <memory>

using namespace std;

void UsedVehicle::add(const std::shared_ptr<Vehicle> &vehicle)
{
    double margin = vehicle->get_price() * 0.2;
    vehicle->set_price(vehicle->get_price()+margin);
    if(vehicle->get_brand() == "Audi" ||vehicle->get_brand() =="Honda") {
        vehicle->set_mileage(vehicle->get_mileage() / 2);
    }
    motor_vehicles.push_back(vehicle);
}

std::shared_ptr<Vehicle> UsedVehicle::sell(int index, std::string &customer)
{
    motor_vehicles[index]->change(customer);
    shared_ptr<Vehicle> vehicle = motor_vehicles[index];
    auto it = motor_vehicles.begin()+index;
    motor_vehicles.erase(it);
    return vehicle;
}

void UsedVehicle::print()
{
    cout << "Nr " << "marka " << "kolor "<<"cena "<< "wlasciciel " << endl;
    for (int i = 0; i < motor_vehicles.size(); i++)
    {
        cout << i << ". " << *motor_vehicles[i] << endl;
    }
    cout << endl;
}

void UsedVehicle::more_info(int index) {
    cout << "\nPojazd numer " << index << ":\n";
    motor_vehicles[index]->info(); //wywolanie metody info ktora wyswietla informacje o danympojezdzie
}

void UsedVehicle::drive(int index, int length) {

     //wywolanie metody drive ktora zwieksza przebieg danego pojazdu
    try {motor_vehicles[index]->drive(length);}
    catch(drive_error & ex)
    {
        std::cout << ex.message << std::endl;
    }
}