//
// Created by Michał on 18.12.2020.
//

#include "Painter.h"

void Painter::paint(const std::shared_ptr<Vehicle> &vehicle, std::string &new_color)
{
    vehicle->set_color(new_color);

}