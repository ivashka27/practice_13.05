#include "Room.h"
#include <iostream>

Room::Room(std::string roomName, std::string roomType, int roomCapacity) {
    name = roomName;
    type = roomType;
    capacity = roomCapacity;
    visitCount = 0;
}

void Room::printInfo() {
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Вместимость: " << capacity << std::endl;
    std::cout << "Количество посещений: " << visitCount << std::endl;
}

void Room::visit() {
    visitCount++;
}

int Room::getVisitCount() {
    return visitCount;
}

std::string Room::getName() {
    return name;
}