#pragma once

#include <string>

class Room;

class Guide {
private:
    std::string name;
    Room* currentRoom;
    int groupSize;

public:
    Guide(const std::string& name, int groupSize);

    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;

    void printGuideAndCurrentRoom() const;

    Room* getCurrentRoom() const;
    const std::string& getName() const;
    int getGroupSize() const;
};