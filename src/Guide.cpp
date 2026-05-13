#include "Guide.hpp"

#include <iostream>

Guide::Guide(const std::string& guideName) : _name(guideName), _currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
    _currentRoom = room;
    _currentRoom->visit();
    std::cout << "Гид " << _name << " провел группу в комнату: " << _currentRoom->getName() << '\n';
}

void Guide::printCurrentRoomInfo() const {
    if (_currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате\n";
        return;
    }

    std::cout << "Гид: " << _name << '\n';
    std::cout << "Текущая комната:\n";
    _currentRoom->printInfo();
}

Room* Guide::getCurrentRoom() const {
    return _currentRoom;
}
