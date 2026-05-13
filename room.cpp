#include "room.h"
#include <iostream>

Room::Room(const std::string& name, const std::string& type, int capacity):
	name(name), type(type), capacity(capacity), visitCount(0) {}

void Room::printInfo() {
	std::cout << "Название: " << name << std::endl;
	std::cout << "Тип: " << type << std::endl;
	std::cout << "Вместимость: " << capacity << std::endl;
	std::cout << "Количество посещений: " << visitCount << std::endl;
}

void Room::visit() {
	visitCount++;
}

int Room::getVisitCount() const {
	return visitCount;
}

std::string Room::getName() const {
	return name;
}