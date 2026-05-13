#pragma once
#include <string>
#include "Room.h"

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(const std::string& name);

    void goToRoom(Room* room);
    void printCurrentRoom() const;

    Room* getCurrentRoom() const;
};

