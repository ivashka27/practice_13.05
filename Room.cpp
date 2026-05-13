#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(string roomName, string roomType, int roomCapacity) {
    name = roomName;
    type = roomType;
    capacity = roomCapacity;
    visitCount = 0;
}

void Room::printInfo() {
    cout << "Название: " << name << endl;
    cout << "Тип: " << type << endl;
    cout << "Вместимость: " << capacity << endl;
    cout << "Количество посещений: " << visitCount << endl;
}

void Room::visit() {
    visitCount++;
}

int Room::getVisitCount() {
    return visitCount;
}

string Room::getName() {
    return name;
}
