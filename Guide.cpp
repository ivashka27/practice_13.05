#include "Guide.hpp"
#include <iostream>

Guide::Guide(std::string n) : name(n), currentRoom(nullptr) {} 

void Guide::goToRoom(Room* room) {
    currentRoom = room;
    if (currentRoom != nullptr) {
        currentRoom->visit();
        std::cout << "Гид провел группу в комнату: " << currentRoom->getName() << std::endl;
    }
}

void Guide::printCurrentRoomInfo() {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    }
    else {
        std::cout << "Текущая комната:" << std::endl;
        currentRoom->printInfo(); 
    }
}