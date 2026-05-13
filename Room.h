#pragma once

#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(const std::string& n, const std::string& t, int cap);

    void printInfo() const;
    void visit();
    int getVisitCount() const;
    std::string getName() const;
};
