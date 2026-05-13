#include "Excursion.hpp"
#include <iostream>

Room::Room(std::string n, std::string t, uint32_t c)
	: name(n), type(t), capacity(c), visitCount(0)
{
}

void Room::printInfo() {
	std::cout << "Название: " << name << std::endl;
	std::cout << "Тип: " << type << std::endl;
	std::cout << "Вместимость: " << capacity << std::endl;
	std::cout << "Количество посещений: " << visitCount << std::endl;
}

void Room::visit() {
	visitCount += 1;
}

uint32_t Room::getVisitCount() {
	return visitCount;
}

std::string Room::getName() {
	return name;
}

Guide::Guide(std::string n)
	: name(n), currentRoom(nullptr)
{
}

void Guide::goToRoom(Room* room) {
	currentRoom = room;
	currentRoom->visit();
}

void Guide::printCurrentRoom() {
	currentRoom->printInfo();
}

Room* Guide::getCurrentRoom() {
	return currentRoom;
}






