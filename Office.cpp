#include "Office.h"
#include <iostream>

Room::Room(std::string rName, std::string rType, int rCapacity) 
    : name(rName), type(rType), capacity(rCapacity), visitCount(0) {}

void Room::visit() {
    visitCount++;
}

void Room::printInfo() const {
    std::cout << "Название: " << name << "\n"
              << "Тип: " << type << "\n"
              << "Вместимость: " << capacity << "\n"
              << "Количество посещений: " << visitCount << std::endl;
}

int Room::getVisitCount() const { return visitCount; }
std::string Room::getName() const { return name; }

Guide::Guide(std::string gName) : name(gName), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    if (room) {
        currentRoom = room;
        currentRoom->visit();
        std::cout << "Гид провёл группу в комнату: " << currentRoom->getName() << std::endl;
    }
}

void Guide::printCurrentRoomInfo() const {
    if (!currentRoom) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    } else {
        std::cout << "Текущая комната:" << std::endl;
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() const { return currentRoom; }
