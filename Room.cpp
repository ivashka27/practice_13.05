#include "Room.h"
#include <iostream>

Room::Room(std::string n, std::string t, int c) 
    : name(n), type(t), capacity(c), visitCount(0) {}

void Room::printInfo() {
    std::cout << "Название: " << name << "\n"
              << "Тип: " << type << "\n"
              << "Вместимость: " << capacity << "\n"
              << "Количество посещений: " << visitCount << std::endl;
}

void Room::visit() {
    visitCount++;
}

int Room::getVisitCount() const {
    return visitCount;
}

std::string Room::getName() const {
    return name;
}

std::string Room::getType() const {
    return type;
}