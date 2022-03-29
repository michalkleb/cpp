//
// Created by Michał on 18.12.2020.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_PAINTER_H
#define KLEBUKOWSKIMICHAL_ETAP2_PAINTER_H
#include "Vehicle.h"
#include <memory>
class Painter{
public:
    void paint(const std::shared_ptr<Vehicle> &vehicle, std::string &new_color); //funkcja zmieniająca kolor danego pojazdu

};
#endif //KLEBUKOWSKIMICHAL_ETAP2_PAINTER_H
