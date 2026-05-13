#pragma once
#include <string>
#include "Room.hpp"

class Guide{
    private:
        std::string name;
        Room* currentRoom;
    public:
        Guide(std::string name);
        void goToRoom(Room* room);
        void printCurrentRoomInfo();
        Room* getCurrentRoom();
        std::string getName() const;
};
