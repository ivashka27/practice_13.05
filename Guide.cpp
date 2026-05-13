#include "Guide.h"

#include <iostream>

Guide::Guide(const std::string& name)
    : name(name), currentRoom(nullptr) {
}

void Guide::goToRoom(Room* room) {
    currentRoom = room;
    currentRoom->visit();

    std::cout << "Гид " << name << " провёл группу в комнату: "
              << currentRoom->getName() << '\n';
}

void Guide::printCurrentRoom() const {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате.\n";
        return;
    }

    std::cout << "Текущая комната:\n";
    currentRoom->printInfo();
}

Room* Guide::getCurrentRoom() const {
    return currentRoom;
}