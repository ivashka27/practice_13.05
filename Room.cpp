#include "Room.h"

Room::Room(string n, string t, int c) {
    name = n;
    type = t;
    capacity = c;
    visitCount = 0;
}

void Room::printInfo() {
    cout << "Название: " << name << endl;
    cout << "Тип: " << type << endl;
    cout << "Вместимость: " << capacity << endl;
    cout << "Количество посещений: "
        << visitCount << endl;
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