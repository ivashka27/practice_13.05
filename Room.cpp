#include "Room.hpp"
#include <iostream>

Room::Room(std::string name_, std::string type_, int capacity_):
    name(name_), type(type_), capacity(capacity_), visitCount(0){}

void Room::printInfo() const{
    std::cout << "Название: "<<name<<std::endl;
    std::cout << "Тип: "<<type<<std::endl;
    std::cout << "Вместимость: "<<capacity<<std::endl;
    std::cout << "Количество посещений: "<<visitCount<<std::endl;
}

void Room::visit(){
    visitCount++;
}

std::string Room::getName() const{
    return name;
}

int Room::getVisitCount() const{
    return visitCount;
}
