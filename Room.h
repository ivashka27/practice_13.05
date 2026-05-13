#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room 
{
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string rName, std::string rType, int rCapacity);

    void printInfo();
    void visit();

    int getVisitCount();
    std::string getName();
    int getCapacity();
};

#endif