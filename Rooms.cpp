#include "Room.hpp"
#include <iostream>

Room::Room(std::string rName, std::string rType, int rCapacity) 
    : name(rName), type(rType), capacity(rCapacity), visitCount(0) {}

void Room::printInfo() const {
    std::cout << "Название: " << name << "\nТип: " << type 
              << "\nВместимость: " << capacity << "\nПосещений: " << visitCount << std::endl;
}

void Room::visit() { visitCount++; }
int Room::getVisitCount() const { return visitCount; }
std::string Room::getName() const { return name; }
std::string Room::getType() const { return type; }
int Room::getCapacity() const { return capacity; }