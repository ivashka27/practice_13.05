#include "Guide.h"
#include <iostream>

Guide::Guide(const std::string& n) : name(n), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    if (room != nullptr) {
        room->visit();
        currentRoom = room;
        std::cout << "Гид " << name << " провёл группу в комнату: "
                  << room->getName() << std::endl;
    }
}

void Guide::printCurrentRoomInfo() const {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате.\n";
    } else {
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() const {
    return currentRoom;
}
