#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room 
{
private:
    std::string name;        
    std::string type;        
    int capacity;            
    int visitCount;         

public:
    Room(std::string n, std::string t, int cap);
    
    void printInfo();
    void visit();
    int getVisitCount();
    std::string getName();
    
    std::string getType();
    int getCapacity();
};

#endif