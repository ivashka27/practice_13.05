#pragma once

#include <string>

class Room {
private:
    std::string _name;
    std::string _type;
    int _capacity;
    int _visitCount;

public:
    Room(const std::string& roomName, const std::string& roomType, int roomCapacity);

    void printInfo() const;
    void visit();
    int getVisitCount() const;
    std::string getName() const;
};
