#pragma once

#include "Room.h"

class Guide {
public:
    Guide() = default;
    Guide(const std::string& name);

    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
private:
    std::string name = "Ivan";
    Room* currentRoom = nullptr;
};
