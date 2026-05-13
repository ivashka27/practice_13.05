#pragma once

#include <string>

class Room {
public:
    Room(const std::string name, const std::string type, const int capacity);

    void printInfo() const;
    void visit();
    int getVisitCount() const;
    std::string getName() const;
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount = 0;
};
