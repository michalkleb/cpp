//
// Created by Michał on 09.12.2020.
//
#include <iostream>
#include <string>
#include "Factory.h"
#include "Exception.h"
#include "Car.h"
#include "Bicycle.h"
#include "Motorbike.h"

using namespace std;

Factory::Factory() : size(10), count(0) {}

void Factory::create_vehicle(const std::string &brand, const std::string &color, int doors, int x) {
    if (count == size) throw create_error("Brak miejsca na nowy pojazd!");

    if (x != 2 && doors == 0) { //x=2 oznacza że pojazd ma być pojazdem silnikowym
        shared_ptr<Vehicle> vehicle = make_shared <Bicycle>(color, brand,x);//Tworzenie roweru
        add(vehicle);
    }
    else if (x==2 && doors == 0){
        shared_ptr<Vehicle> vehicle = make_shared <Motorbike>(color, brand);  //Tworzenie motocykla
        add(vehicle);
    }
    else {
        if (doors < 2 || doors > 5) throw create_error("Niepoprawna liczba drzwi!");

        shared_ptr<Vehicle> vehicle = make_shared <Car>(color, brand, doors);  //Tworzenie samochodu
        add(vehicle);
    }
}


void Factory::sell(std::string &customer, int index, Owners & owner)
{
    vehicles[index]->change(customer); //zmieniam wlasciciela
    owner.add(vehicles[index]);     //dodaję do tablicy właścicieli
    vehicles[index] = nullptr;
    count--;
}

void Factory::print() {
    cout << "\nASORTYMRNT FABRYKI: " << endl;
    cout << "Nr " << "marka " << "kolor " <<"cena "<< "wlasciciel " << endl;
    for (int i = 0; i < size; i++) {
        if (vehicles[i]) cout << i << ". " << *vehicles[i] << endl;
        else cout << i << ". wolne miejsce" << endl;
    }
    cout << endl;
}

void Factory::more_info(int index) {
    cout << "\nPojazd numer: " << index <<endl;
    vehicles[index]->info(); //wywolanie metody info ktora wyswietla informacje o danym pojeździe
}


void Factory::drive(int index, int length) {
    try { vehicles[index]->drive(length); } //wywolanie metody drive ktora zwieksza przebieg danego pojazdu

    catch(drive_error & ex)
    {
        std::cout << ex.message << std::endl;
    }

}

void Factory::add(const std::shared_ptr<Vehicle> &vehicle) {
    for (int i = 0; i < size; i++) {
        if (!vehicles[i]) {
            vehicles[i] = vehicle; //wstawiam stworzony pojazd do tablicy vehicles (magazynu)
            count++;
            return;
        }
    }
}