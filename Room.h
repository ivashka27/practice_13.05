#pragma once

#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string roomName, std::string roomType, int roomCapacity);

    void printInfo();
    void visit();

    int getVisitCount();
    std::string getName();
};