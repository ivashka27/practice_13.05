#include "..\\include\\room.hpp"

#include <iostream>

Room::Room(const std::string& name, const std::string& type, int capacity)
    : name(name), type(type), capacity(capacity), visitCount(0) {}

void Room::printInfo() const {
    std::cout << "Название: " << name << "\n";
    std::cout << "Тип: " << type << "\n";
    std::cout << "Вместимость: " << capacity << "\n";
    std::cout << "Количество посещений: " << visitCount << "\n";
}

void Room::visit() {
    ++visitCount;
}

int Room::getVisitCount() const {
    return visitCount;
}

const std::string& Room::getName() const {
    return name;
}

int Room::getCapacity() const {
    return capacity;
}