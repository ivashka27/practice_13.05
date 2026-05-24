#pragma once

#include <string>
#include <iostream>

// класс описывает комнату в офисе
class Room {
private:
    std::string name_;
    std::string type_;
    int capacity_;
    int visits_;
public:
    Room(std::string name, std::string type, int capacity);
    void visit();
    int visitCount() const;
    std::string name() const;
    int getVisitCount() const { return visitCount(); }
    std::string getName() const { return name(); }
    void printInfo() const;
};
