#ifndef GUIDE_H
#define GUIDE_H

#include "room.h"
#include <string>

class Guide {
private:
	std::string name;
	Room* currentRoom;

public:
	Guide(const std::string& name);

	void goToRoom(Room* room);
	void printCurrentRoomInfo() const;
	Room* getCurrentRoom() const;
};

#endif