#include "Guide.h"
#include <iostream>

Guide::Guide(std::string gName)
{
    name = gName;
    currentRoom = nullptr;

}

void Guide::goToRoom(Room* room)
{
    currentRoom = room;
    currentRoom->visit();

    std::cout << "Гид провёл группу в комнату: " << currentRoom->getName() << std::endl;
}

void Guide::printCurrentRoomInfo()
{
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    } else {
        std::cout << "Текущая комната:" << std::endl;
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom()
{
    return currentRoom;
}