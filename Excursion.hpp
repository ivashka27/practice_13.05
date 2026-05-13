#include <cstdint>
#include <string>

class Room {
private:
	std::string name;
	std::string type;
	uint32_t capacity;
	uint32_t visitCount;
public:
	Room(std::string n, std::string t, uint32_t c);

	void printInfo();

	void visit();

	uint32_t getVisitCount();

	std::string getName();
};

class Guide {
private:
	std::string name;
	Room* currentRoom;
public:
	Guide(std::string);

	void goToRoom(Room*);

	void printCurrentRoom();

	Room* getCurrentRoom();
};








