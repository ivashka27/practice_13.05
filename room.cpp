#include "room.hpp"

#include <iostream>

Room::Room(const std::string& roomName, const std::string& roomType, int roomCapacity)
    : name(roomName), type(roomType), capacity(roomCapacity), visitCount(0) {}


void Room::printInfo() const {
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Вместимость: " << capacity << std::endl;
    std::cout << "Количество посещений: " << visitCount << std::endl;
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