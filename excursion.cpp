#include "excursion.hpp"
#include <iostream>
#include <cstring>

using namespace std;

// ========== Реализация класса Room ==========

Room::Room(const char* n, const char* t, int cap) {
    name = new char[strlen(n) + 1];
    type = new char[strlen(t) + 1];
    strcpy(name, n);
    strcpy(type, t);
    capacity = cap;
    visitCount = 0;
}

Room::~Room() {
    delete[] name;
    delete[] type;
}

// Вывод информации о комнате
void Room::printInfo() {
    cout << "Название: " << name << endl;
    cout << "Тип: " << type << endl;
    cout << "Вместимость: " << capacity << endl;
    cout << "Количество посещений: " << visitCount << endl;
}

// Увеличить количество посещений
void Room::visit() {
    visitCount++;
}

// Получить количество посещений
int Room::getVisitCount() const {
    return visitCount;
}

// Получить название комнаты
const char* Room::getName() const {
    return name;
}

// Получить тип комнаты
const char* Room::getType() const {
    return type;
}

// Получить вместимость
int Room::getCapacity() const {
    return capacity;
}

// ========== Реализация класса Guide ==========

Guide::Guide(const char* n) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    currentRoom = nullptr;
}

Guide::~Guide() {
    delete[] name;
}

// Перевести группу в другую комнату
void Guide::goToRoom(Room* room) {
    if (room != nullptr) {
        currentRoom = room;
        currentRoom->visit();
        cout << "Гид " << name << " провёл группу в комнату: " 
             << currentRoom->getName() << endl;
    } else {
        cout << "Ошибка: комната не существует!" << endl;
    }
}

// Вывести информацию о текущей комнате
void Guide::printCurrentRoomInfo() {
    if (currentRoom != nullptr) {
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
    } else {
        cout << "Группа пока не находится ни в одной комнате." << endl;
    }
}

// Получить указатель на текущую комнату
Room* Guide::getCurrentRoom() const {
    return currentRoom;
}

// Получить имя гида
const char* Guide::getName() const {
    return name;
}