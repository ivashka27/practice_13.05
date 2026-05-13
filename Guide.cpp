#include "Guide.hpp"
#include <iostream>

Guide::Guide(std::string gName) : name(gName), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    currentRoom = room;
    currentRoom->visit();
    std::cout << "Гид " << name << " завел группу в " << currentRoom->getName() << std::endl;
}

void Guide::printCurrentRoomInfo() const {
    std::cout << "\nГид: " << name << std::endl;
    if (!currentRoom) std::cout << "Группа еще не в комнате.\n";
    else currentRoom->printInfo();
}