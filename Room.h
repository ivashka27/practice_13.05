#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    Room(string roomName, string roomType, int roomCapacity);

    void printInfo();
    void visit();
    int getVisitCount();
    string getName();
};

#endif
