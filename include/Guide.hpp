#pragma once

#include "Room.hpp"

#include <string>

class Guide {
private:
    std::string _name;
    Room* _currentRoom;

public:
    Guide(const std::string& guideName);

    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
};
