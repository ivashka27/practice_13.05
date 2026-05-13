#include "guide.h"

Guide::Guide(const std::string& name) : name(name), currentRoom(nullptr) {
}

void Guide::goToRoom(Room* room) {
    if (room != nullptr) {
        currentRoom = room;
        currentRoom->visit();
        std::cout << "Гид " << name << " провёл группу в комнату: " 
                  << currentRoom->getName() << std::endl;
    } else {
        std::cout << "Ошибка: комната не существует!" << std::endl;
    }
}

void Guide::printCurrentRoomInfo() const {
    if (currentRoom != nullptr) {
        std::cout << "\nТекущая комната:" << std::endl;
        currentRoom->printInfo();
    } else {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    }
}

Room* Guide::getCurrentRoom() const {
    return currentRoom;
}

std::string Guide::getName() const {
    return name;
}
