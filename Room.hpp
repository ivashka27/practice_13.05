#pragma once
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
    std::string getType() const;
    int getCapacity() const;
};

