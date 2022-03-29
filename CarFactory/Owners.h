//
// Created by Michał on 17.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_OWNERS_H
#define KLEBUKOWSKIMICHAL_ETAP2_OWNERS_H
#include <vector>
#include <memory>
#include"Vehicle.h"

//Klasa przechowująca pojazdy aktualnie używane i mające swoich właścicieli
class Owners{
    std::vector < std::shared_ptr<Vehicle> > owners;

public:
    void add(const std::shared_ptr<Vehicle> &vehicle); //wstawienie pojazdu do wektora
    void print();                                      //wyświetlenie informacji o pojazdach
    int get_size(){return owners.size();}              //zwrócenie ilości pojazdów
    void more_info(int index);                         //wyświetla szczegółowe informacje o pojeździe
    void drive(int index, int length);
    bool is_valid(int index){return !owners[index];}
    std::shared_ptr<Vehicle> sell(int index);          //sprzedanie samochodu do komisu
    std::shared_ptr<Vehicle> get_vehicle(int index){return owners[index];}
};
#endif //KLEBUKOWSKIMICHAL_ETAP2_OWNERS_H
