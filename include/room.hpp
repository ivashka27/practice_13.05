#pragma once

#include <string>

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
    const std::string& getName() const;
    int getCapacity() const;
};