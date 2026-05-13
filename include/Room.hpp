#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string n, std::string t, int c);
    
    void printInfo() const;
    void visit();
    
    int getVisitCount() const;
    std::string getName() const;
};

#endif