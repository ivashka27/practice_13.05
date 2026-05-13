#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(const std::string& name, const std::string& type, int capacity);
    void printInfo() const;
    void visit();
    int getVisitCount() const;
    std::string getName() const;
    std::string getType() const;
    int getCapacity() const;
};

#endif
