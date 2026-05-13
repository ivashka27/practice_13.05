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
	Room(const std::string& name, const std::string& type, int capacity);

	void printInfo();
	void visit();

	int getVisitCount() const;

	std::string getName() const;
};

#endif