#include "guide.hpp"
#include <iostream>

using namespace std;

Guide::Guide(string n) 
{
    name = n;
    currentRoom = nullptr;
}

void Guide::goToRoom(Room* room) 
{
    if (room != nullptr) 
    {
        currentRoom = room;
        currentRoom->visit(); 
        cout << "Гид " << name << " провёл группу в комнату: " << currentRoom->getName() << endl;
    }
}

void Guide::printCurrentRoomInfo() 
{
    if (currentRoom != nullptr) 
    {
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
    } 
    else 
    {
        cout << "Группа пока не находится ни в одной комнате." << endl;
    }
}

Room* Guide::getCurrentRoom() 
{
    return currentRoom;
}

string Guide::getName() 
{
    return name;
}