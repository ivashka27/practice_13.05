#include "Room.hpp"
#include <iostream>

Room::Room(std::string n, std::string t, int c)
    : name(n), type(t), capacity(c), visitCount(0) {
}

void Room::printInfo() {
    std::cout << "Название: " << name << "\nТип: " << type
        << "\nВместимость: " << capacity
        << "\nКоличество посещений: " << visitCount << std::endl;
}

void Room::visit() { visitCount++; }
int Room::getVisitCount() { return visitCount; }
std::string Room::getName() { return name; }