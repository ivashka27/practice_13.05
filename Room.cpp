#include "Room.h"
#include <iostream>


Room::Room(std::string rName, std::string rType, int rCapacity) 
{
    name = rName;
    type = rType;
    capacity = rCapacity;
    visitCount = 0;
}

void Room::printInfo() 
{
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << type << std::endl;
    std::cout << "Вместимость: " << capacity << std::endl;
    std::cout << "Количество посещений: " << visitCount << std::endl;
}

void Room::visit() 
{
    visitCount++;
}

int Room::getVisitCount() 
{
    return visitCount;
}

std::string Room::getName() 
{
    return name;
}

int Room::getCapacity() 
{
    return capacity;
}