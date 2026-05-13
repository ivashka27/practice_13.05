#ifndef GUIDE_H
#define GUIDE_H

#include <string>
#include "Room.h"

class Guide 
{
private:
    std::string name;
    Room* currentRoom;


public:
    Guide(std::string gName);

    void goToRoom(Room* room);
    void printCurrentRoomInfo();

    Room* getCurrentRoom();
};

#endif