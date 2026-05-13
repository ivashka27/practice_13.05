#include "..\\include\\guide.hpp"
#include "..\\include\\room.hpp"

#include <iostream>

Guide::Guide(const std::string& name, int groupSize)
    : name(name), currentRoom(nullptr), groupSize(groupSize) {}

void Guide::goToRoom(Room* room) {
    if (room == nullptr) {
        return;
    }

    if (room->getName() == "Серверная" && groupSize > room->getCapacity()) {
        std::cout << "Группа слишком большая для серверной, оставьте кого-нибудь за дверью "
                     "(вместимость "
                  << room->getCapacity() << ", человек в группе: " << groupSize << ").\n";
        return;
    }

    currentRoom = room;
    currentRoom->visit();
}

void Guide::printCurrentRoomInfo() const {
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате.\n";
    } else {
        std::cout << "Текущая комната:\n";
        currentRoom->printInfo();
    }
}

void Guide::printGuideAndCurrentRoom() const {
    std::cout << "Гид: " << name << "\n";
    if (currentRoom == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате.\n";
    } else {
        std::cout << "Текущая комната:\n";
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() const {
    return currentRoom;
}

const std::string& Guide::getName() const {
    return name;
}

int Guide::getGroupSize() const {
    return groupSize;
}