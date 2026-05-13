#include "Room.hpp"

#include <iostream>

Room::Room(const std::string& roomName, const std::string& roomType, int roomCapacity) 
: _name(roomName), _type(roomType), _capacity(roomCapacity), _visitCount(0) {}

void Room::printInfo() const {
    std::cout << "Название: " << _name << '\n';
    std::cout << "Тип: " << _type << '\n';
    std::cout << "Вместимость: " << _capacity << '\n';
    std::cout << "Количество посещений: " << _visitCount << '\n';
}

void Room::visit() {
    _visitCount++;
}

int Room::getVisitCount() const {
    return _visitCount;
}

std::string Room::getName() const {
    return _name;
}
