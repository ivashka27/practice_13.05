#include "Guide.h"
#include <iostream>

Guide::Guide(std::string n) : name(n), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    if (room != nullptr) {
        currentRoom = room;
        currentRoom->visit();
        std::cout << "Гид " << name << " провел группу в комнату: " << currentRoom->getName() << std::endl;
    }
}

void Guide::printCurrentRoomInfo() {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    } else {
        std::cout << "Текущая информация:" << std::endl;
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() const {
    return currentRoom;
}