#pragma once
#include <string>
#include <iostream>

class Room
{
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string n, std::string t, int c, int v_C);
    Room(std::string n, std::string t, int c);
    std::string getName();
    void visit();
    void printInfo();
    int getVisitCount();
};

class Guide
{
private:
    std::string name;
    Room *currentRoom;

public:
    Guide(std::string n, Room *c_R);
    Guide(std::string n);
    void goToRoom(Room *room);
    void printCurrentRoomInfo();
    Room *getCurrentRoom();
};
