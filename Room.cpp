#include "Room.h"

#include <iostream>

Room::Room(const std::string name, const std::string type, const int capacity):
    name(name), type(type), capacity(capacity) {}

void Room::printInfo() const {
    std::cout<<"Название: "<<this->name<<std::endl;
    std::cout<<"Тип: "<<this->type<<std::endl;
    std::cout<<"Вместимость: "<<this->capacity<<std::endl;
    std::cout<<"Количество посещений: "<<this->visitCount<<std::endl;
}

void Room::visit() {
    this->visitCount++;
}

int Room::getVisitCount() const {
    return this->visitCount;
}

std::string Room::getName() const {
    return this->name;
}