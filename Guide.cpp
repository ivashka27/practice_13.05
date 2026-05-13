#include "Guide.h"
#include <iostream>

using namespace std;

Guide::Guide(string guideName) {
    name = guideName;
    currentRoom = nullptr;
}

void Guide::goToRoom(Room* room) {
    currentRoom = room;
    currentRoom->visit();
}

void Guide::printCurrentRoomInfo() {
    if (currentRoom == nullptr) {
        cout << "Группа пока не находится ни в одной комнате." << endl;
    } else {
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
    }
}

void Guide::printCurrentRoomInfoWithGuide() {
    cout << "Гид: " << name << endl;
    printCurrentRoomInfo();
}

Room* Guide::getCurrentRoom() {
    return currentRoom;
}
