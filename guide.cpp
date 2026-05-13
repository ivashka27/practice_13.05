#include "guide.h"
#include <iostream>

Guide::Guide(const std::string& name) : name(name), currentRoom(nullptr) {}

void Guide::goToRoom(Room* room) {
	currentRoom = room;
	if (currentRoom != nullptr) {
		currentRoom->visit();
		std::cout << "Гид " << name << " провёл группу в комнату: " << currentRoom->getName() << std::endl;
	}
}

void Guide::printCurrentRoomInfo() const {
	if (currentRoom == nullptr) {
		std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
	}
	else {
		std::cout << "Текущая комната:" << std::endl;
		currentRoom->printInfo();
	}
}

Room* Guide::getCurrentRoom() const {
	return currentRoom;
}