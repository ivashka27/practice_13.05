#ifndef GUIDE_HPP
#define GUIDE_HPP

#include <string>

#include "room.hpp"

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(const std::string& guideName);

    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
};

#endif
