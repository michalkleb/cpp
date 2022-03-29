cmake_minimum_required(VERSION 3.16.3)
project(KlebukowskiMichal-etap3)

set(CMAKE_CXX_STANDARD 14)

add_executable(KlebukowskiMichal-etap3 main.cpp Factory.h Factory.cpp Vehicle.cpp Vehicle.h MotorVehicle.cpp MotorVehicle.h Car.cpp Car.h Motorbike.cpp Motorbike.h Bicycle.cpp Bicycle.h UsedVehicle.h UsedVehicle.cpp Owners.h Owners.cpp Painter.h Painter.cpp Exception.h )