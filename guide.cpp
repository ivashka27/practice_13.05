#include "guide.hpp"
#include <iostream>

Guide::Guide(const std::string& name)
    : name(name), currentRoom(nullptr) {
}
void Guide::goToRoom(Room* room) {
    if (room == nullptr) {
        return;
    }
    currentRoom = room;
    currentRoom->visit();

    std::cout << "Гид провёл группу в комнату: " << currentRoom->getName() << std::endl;
}
void Guide::printCurrentRoomInfo() const {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
        return;
    }
    std::cout << "Текущая комната:" << std::endl;
    currentRoom->printInfo();
}
Room* Guide::getCurrentRoom() const {
    return currentRoom;
}
