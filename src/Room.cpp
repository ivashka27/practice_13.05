#include "Room.hpp"
#include <iostream>

Room::Room(std::string n, std::string t, int c) 
    : name(n), type(t), capacity(c), visitCount(0) {}

void Room::printInfo() const {
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Вместимость: " << capacity << std::endl;
    std::cout << "Посещений: " << visitCount << std::endl;
}

void Room::visit() { visitCount++; }
int Room::getVisitCount() const { return visitCount; }
std::string Room::getName() const { return name; }