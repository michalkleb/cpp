//
// Created by Michał on 09.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_VEHICLE_H
#define KLEBUKOWSKIMICHAL_ETAP2_VEHICLE_H
#include <string>
#include<iostream>
#include "memory"


class Vehicle {
protected:
    std::string owner;
    std::string color;
    std::string brand;
    int trunk;
    double price;
public:
    Vehicle(const std::string &_color, const std::string &_brand,  const std::string &_owner = "fabryka");

    virtual void drive(double new_mileage){}                       //dokonuje jazdy próbnej
    virtual void info();                                           //wyswietlam informacje o danym samochodzie
    virtual void set_mileage(double _mileage){}                    //dokonuję zmiany przebiegu
    virtual double get_mileage(){return 0;}               //zwracam przebieg pojazdu
    virtual int capacity() const {return trunk;}                  //zwracam łądowność pojazdu
    void change(std::string &customer){owner = customer;}  //zmieniam właściciela pojazdu

    std::string get_brand() const {return brand;}         //zwracam marke pojazdu
    double get_price() const {return price;}              //zwracam cenę pojzdu

    void set_price(double _price){price = _price;}                //dokonuję zmiany ceny
    void set_color(std::string &new_color) {color=new_color;}     //dokonuję zmiany koloru

    friend std::ostream &operator<<(std::ostream &out, Vehicle& car); //przyjażń z przeładowanym operatorem wypisania

};


#endif //KLEBUKOWSKIMICHAL_ETAP2_VEHICLE_H
