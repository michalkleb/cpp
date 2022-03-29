//
// Created by Michał on 06.01.2021.
//

#ifndef KLEBUKOWSKIMICHAL_ETAP2_EXCEPTION_H
#define KLEBUKOWSKIMICHAL_ETAP2_EXCEPTION_H

#include <string>
struct index_error: public std::exception {
    std::string message;
    explicit index_error(std::string msg): message(std::move(msg)) {}
};
struct drive_error: public std::exception  {
    std::string message;
    explicit drive_error(std::string msg):message(std::move(msg)) {}
};
struct create_error: public std::exception  {
    std::string message;
    explicit create_error(std::string msg):message(std::move(msg)) {}
};

#endif //KLEBUKOWSKIMICHAL_ETAP2_EXCEPTION_H
