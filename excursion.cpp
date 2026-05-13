#include "excursion.h"

Room::Room(std::string n, std::string t, int c, int v_C) : name(n), type(t), capacity(c), visitCount(v_C) {};
Room::Room(std::string n, std::string t, int c) : name(n), type(t), capacity(c) {};
void Room::visit()
{
    this->visitCount += 1;
}
std::string Room::getName()
{
    return this->name;
}
void Room::printInfo()
{
    std::cout << "Название: " <<  this->name << std::endl;
    std::cout << "Тип: " <<  this->type << std::endl;
    std::cout << "Вместимость: " <<  this->capacity << std::endl;
    std::cout <<  "Количество посещений: " << this->visitCount << std::endl << std::endl;
}

int Room::getVisitCount()
{
    return this->visitCount;
}

Guide::Guide(std::string n, Room *c_R) : name(n), currentRoom(c_R) {};
Guide::Guide(std::string n) : name(n) {currentRoom = nullptr;};
void Guide::goToRoom(Room *room)
{
    this->currentRoom = room;
    room->visit();
}
void Guide::printCurrentRoomInfo() {
    Room *room = this->currentRoom;
    if (room == nullptr) {
        std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
    }
    else{
        std::cout << "Текущая комната:" << std::endl;
        room->printInfo();
    }
}