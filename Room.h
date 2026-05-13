#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(const std::string& n, const std::string& t, int cap);

    void printInfo();

    void visit();

    int getVisitCount();

    std::string getName();
};

#endif