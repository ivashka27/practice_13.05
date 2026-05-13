#ifndef GUIDE_H
#define GUIDE_H

#include "Room.h"
#include <string>

using namespace std;

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(string guideName);

    void goToRoom(Room* room);
    void printCurrentRoomInfo();
    void printCurrentRoomInfoWithGuide();
    Room* getCurrentRoom();
};

#endif
