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
    Room(std::string n, std::string t, int c);
    
    void printInfo();
    void visit();
    int getVisitCount() const;
    std::string getName() const;
    std::string getType() const;
};

#endif
