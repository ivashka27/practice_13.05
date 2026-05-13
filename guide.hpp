#ifndef GUIDE_HPP
#define GUIDE_HPP

#include <string>
#include "room.hpp"

class Guide 
{
private:
    std::string name;           
    Room* currentRoom;         
public:
    Guide(std::string n);
   
    void goToRoom(Room* room);
    void printCurrentRoomInfo();
    Room* getCurrentRoom();
 
    std::string getName();
};

#endif