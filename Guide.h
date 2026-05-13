#pragma once

#include <string>
#include "Room.h"

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string guideName);
    
    void goToRoom(Room* room);
    void printCurrentRoomInfo();

    Room* getCurrentRoom();
};