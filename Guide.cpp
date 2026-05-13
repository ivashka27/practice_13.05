#include "Guide.h"

#include <iostream>

Guide::Guide(const std::string& name): name(name) {}

void Guide::goToRoom(Room* room) {
    this->currentRoom = room;
    room->visit();
    std::cout<<"Гид провёл группу в комнату: "<<room->getName()<<std::endl;
}

Room* Guide::getCurrentRoom() const {
    return this->currentRoom;
}

void Guide::printCurrentRoomInfo() const {
    Room* room = this->getCurrentRoom();
    if (room == nullptr) {
        std::cout<<"Группа пока не находится ни в одной комнате."<<std::endl;
    }
    else {
        std::cout<<"Текущая комната:"<<std::endl;
        room->printInfo();
    }
}
