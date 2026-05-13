#include "Room.h"
#include <iostream>

Room::Room(const std::string& n, const std::string& t, int cap)
    : name(n), type(t), capacity(cap), visitCount(0) {}

void Room::printInfo() const {
    std::cout << "Название: " << name << "\n"
              << "Тип: " << type << "\n"
              << "Вместимость: " << capacity << "\n"
              << "Количество посещений: " << visitCount << std::endl;
}

void Room::visit() {
    ++visitCount;
}

int Room::getVisitCount() const {
    return visitCount;
}

std::string Room::getName() const {
    return name;
}
