#ifndef GUIDE_H
#define GUIDE_H

#include <string>
#include <iostream>
#include "room.h"

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(const std::string& name);

    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
    std::string getName() const;
};

#endif
