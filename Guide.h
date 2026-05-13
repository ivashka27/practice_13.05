#pragma once

#include <string>
#include "Room.h"

class Guide {
private:
    std::string name;
    Room* currentRoom;   // указатель на текущую комнату

public:
    Guide(const std::string& n);

    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
};
