#include "Guide.h"

Guide::Guide(string n) {
    name = n;
    currentRoom = nullptr;
}

void Guide::goToRoom(Room* room) {
    currentRoom = room;

    currentRoom->visit();

    cout << "Гид провёл группу в комнату: "
        << currentRoom->getName()
        << endl;
}

void Guide::printCurrentRoomInfo() {

    if (currentRoom == nullptr) {

        cout << "Группа пока не находится "
            << "ни в одной комнате."
            << endl;
    }
    else {

        cout << "Текущая комната:" << endl;

        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() {
    return currentRoom;
}