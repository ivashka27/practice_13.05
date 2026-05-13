#include <iostream>
#include "Guide.hpp"

Guide::Guide(std::string name_):
    name(name_), currentRoom(nullptr){}

void Guide::goToRoom(Room* room){
    currentRoom = room;
    currentRoom->visit();
    std::cout << "Гид " << name << " провёл группу в комнату: " << room->getName() << std::endl;
}

void Guide::printCurrentRoomInfo(){
    if (currentRoom == nullptr){
            std::cout <<"Группа пока не находится ни в одной комнате."<<std::endl;
    }
    else{
        std::cout<<"\nТекущая комната:" << std::endl;
        currentRoom->printInfo();
    }
}

Room* Guide::getCurrentRoom() {
    return currentRoom;
}
 
std::string Guide::getName() const {
    return name;
}
