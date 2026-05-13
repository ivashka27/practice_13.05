#ifndef OFFICE_H
#define OFFICE_H

#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string rName, std::string rType, int rCapacity);
    void printInfo() const;
    void visit();
    int getVisitCount() const;
    std::string getName() const;
};

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string gName);
    void goToRoom(Room* room);
    void printCurrentRoomInfo() const;
    Room* getCurrentRoom() const;
};

#endif
