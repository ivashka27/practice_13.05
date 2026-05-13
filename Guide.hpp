#pragma once
#include <string>
#include "Room.hpp"

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string gName);
    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
};

