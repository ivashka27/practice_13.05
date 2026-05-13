#pragma once

#include "Room.h"

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(string n);

    void goToRoom(Room* room);

    void printCurrentRoomInfo();

    Room* getCurrentRoom();
};