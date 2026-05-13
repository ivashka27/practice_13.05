#ifndef GUIDE_HPP
#define GUIDE_HPP

#include "Room.hpp"
#include <string>

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string n);
    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
};

#endif