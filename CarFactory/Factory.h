//
// Created by Michał on 09.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_FACTORY_H
#define KLEBUKOWSKIMICHAL_ETAP2_FACTORY_H

#include <string>
#include<memory>
#include "Vehicle.h"
#include "Owners.h"


class Factory {
    std::shared_ptr<Vehicle> vehicles[10];
    int count;
    int size;
    void add(const std::shared_ptr<Vehicle> &vehicle); //dodanie do tablicy pojazdów
public:
    explicit Factory();
    void create_vehicle(const std::string &brand,const std::string &color, int doors, int x); //Tworzenie nowego pojazdu
    void sell(std::string &customer, int index, Owners & owner);                              //usuwam z tablicy pojazdów i zmieniam mu właściciela
    void print();                                 //wyswietlam asortyment fabryki
    void more_info(int index);                    //wyswietlam szczegolowe informacje o danym pojeździe
    int get_size() const {return size;}     //zwracam ilosc pojazdów gotowych do sprzedazy
    void drive(int index, int length) ;           //zwiekszam przebieg danego pojazdu
    bool is_valid(int index){return !vehicles[index];}

    friend std::ostream &operator<<(std::ostream &out, Vehicle& car);

};


#endif //KLEBUKOWSKIMICHAL_ETAP2_FACTORY_H
