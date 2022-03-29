//
// Created by Michał on 17.12.2020.
//

#include "Owners.h"
#include "MotorVehicle.h"
#include "Exception.h"
#include <memory>
using namespace std;

void Owners::add(const  std::shared_ptr<Vehicle> &vehicle)
{
    double mileage = vehicle->get_mileage();
    string brand =vehicle->get_brand();
    double _price = vehicle->get_price();

    if(brand == "Yamaha") vehicle->set_price(_price * 0.6 - mileage*1.2);
    else if(brand== "Honda") vehicle->set_price(_price * 0.54 - mileage*1.1);
    else if(brand =="Audi") vehicle->set_price(_price * 0.7 - mileage*1.3);
    else if(brand== "Volksvagen")vehicle->set_price(_price * 0.6 - mileage*0.9);

   owners.push_back(vehicle);
}


void Owners::print()
{
    cout << "Nr " << "marka " << "kolor " <<"cena "<< "wlasciciel " << endl;
    for (int i = 0; i < owners.size(); i++)
    {
       cout << i << ". " << *owners[i] << endl;
    }
    cout << endl;
}

std::shared_ptr<Vehicle> Owners::sell(int index)
{
    string customer = "komis";
    owners[index]->change(customer);
    shared_ptr<Vehicle> vehicle = owners[index];
    auto it = owners.begin()+index;
    owners.erase(it);
    return owners[index];
}

void Owners::more_info(int index) {
    cout << "\nPojazd numer " << index << ":\n";
    owners[index]->info(); //wywolanie metody info ktora wyswietla informacje o danym pojezdzie
}

void Owners::drive(int index, int length) {

     //wywolanie metody drive ktora zwieksza przebieg danego pojazdu
    try {owners[index]->drive(length);}
    catch(drive_error & ex)
    {
        std::cout << ex.message << std::endl;
    }

    //Po zwiekszeniu przebiegu danego pojazdu ustawiam nową cenę
    double mileage = owners[index]->get_mileage();
    double _price = owners[index]->get_price();
    owners[index]->set_price(_price * 0.6 - mileage*1.2);
}

