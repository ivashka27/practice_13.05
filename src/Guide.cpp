#include "Guide.hpp"
#include <iostream>

Guide::Guide(std::string n) : name(n), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    if (room != nullptr) {
        currentRoom = room;
        currentRoom->visit();
        std::cout << "\nГид " << name << " провел группу в комнату: " << currentRoom->getName() << std::endl;
    }
}

void Guide::printCurrentRoomInfo() const {
    if (currentRoom == nullptr) {
        std::cout << "\nГруппа пока не находится ни в одной комнате." << std::endl;
    } else {
        std::cout << "\nТекущая комната:" << std::endl;
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() const { return currentRoom; }