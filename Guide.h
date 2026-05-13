#ifndef GUIDE_H
#define GUIDE_H

#include "Room.h"
#include <string>

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string n);
    
    void goToRoom(Room* room);
    void printCurrentRoomInfo();
    Room* getCurrentRoom() const;
};

#endif