#include "Guide.h"
#include <iostream>

Guide::Guide(const std::string& n) : name(n), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    if (room == nullptr) {
        return;
    }
    currentRoom = room;
    currentRoom->visit();
    std::cout << "Гид провёл группу в комнату: " << currentRoom->getName() << std::endl;
}

void Guide::printCurrentRoomInfo() {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    } else {
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() {
    return currentRoom;
}