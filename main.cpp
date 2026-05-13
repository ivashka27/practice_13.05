#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void printHelp() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "(1) Select room" << std::endl;
    std::cout << "(2) View current room info" << std::endl;
    std::cout << "(3) View traversal history" << std::endl;
    std::cout << "(4) Calculate maximum visits" << std::endl;
    std::cout << "(5) Exit" << std::endl;
    std::cout << std::endl;
}


class Room {
private:
    std::string name;
    std::string type;
    unsigned int capacity;
    unsigned int visitCount;

public:
    Room(const std::string& name, const std::string& type, unsigned int capacity)
        : name(name), type(type), capacity(capacity), visitCount(0) {}

    void visit() {
        visitCount++;
    }

    std::string getName() const {
        return name;
    }

    unsigned int getVisitCount() const {
        return visitCount;
    }

    void printInfo() const {
        std::cout << "Room: " << name << ", Type: " << type << ", Capacity: " << capacity << ", Visits: " << visitCount << std::endl;
    }
};

class Guide {
private:
    std::string name;
    Room* currentRoom;
    std::vector<Room*> traversalHistory; // using c style array is nightmare (unknown size, potential limitless growth, clearing logic) for no benefits. 
    
public:
    Guide(const std::string& name) : name(name), currentRoom(nullptr), traversalHistory() {}

    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();
        traversalHistory.push_back(room);
    }

    Room* getCurrentRoom() const {
        return currentRoom;
    }

    const std::vector<Room*>& getTraversalHistory() const {
        return traversalHistory;
    }

    void getCurrentRoomInfo() const {
        if (currentRoom) {
            currentRoom->printInfo();
        } else {
            std::cout << "The guide is not currently in any room." << std::endl;
        }
    }
};


Room* getMaxVisitRoom(Room* const rooms[], size_t numRooms) {
    // if equal, the room with lowest index will be returned
    size_t max_index = 0;
    unsigned int max_visit = 0;

    for (size_t i = 0; i < numRooms; ++i) {
        if (rooms[i]->getVisitCount() > max_visit) {
            max_visit = rooms[i]->getVisitCount();
            max_index = i;
        }
    }

    return rooms[max_index];
}

void printAvailableRooms(Room* const rooms[], size_t numRooms) {
    std::cout << "Available rooms:" << std::endl;
    for (size_t i = 0; i < numRooms; ++i) {
        std::cout << "(" << (i + 1) << ") " << rooms[i]->getName() << std::endl;
    }
}

int main() {
    // create rooms
    std::vector<std::pair<std::string, std::pair<std::string, unsigned int>>> room_data = {
        {"Lobby", {"Common Area", 50}},
        {"Conference Room", {"Meeting Space", 20}},
        {"Cafeteria", {"Dining Area", 100}},
        {"Office A", {"Work Space", 10}},
        {"Office B", {"Work Space", 10}}
    };
    const size_t numRooms = room_data.size();

    Room* rooms[numRooms]; // stack allocation; size is known at compile time
    for (size_t i = 0; i < numRooms; i++) {
        rooms[i] = new Room(room_data[i].first, room_data[i].second.first, room_data[i].second.second);
    }
    Guide guide("Yandex Guide");

    // cli loop
    std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;
    printHelp();
    bool exiting = false;
    bool choosing_room = false;

    while (!exiting) {
        std::string input;
        std::getline(std::cin, input);
        int command = 0;
        try {
            size_t parsedChars = 0;
            command = std::stoi(input, &parsedChars);
            if (parsedChars != input.size()) {
                throw std::invalid_argument("Input contains non-numeric characters.");
            }
        } 
        catch (const std::exception&) {
            std::cout << "Unexpected input error. Please try again." << std::endl;
            continue;
        }

       if (choosing_room) {
            // handle room selection
            if (command >= 1 && command <= static_cast<int>(numRooms)) {
                guide.goToRoom(rooms[command - 1]);
                std::cout << "Moved to " << rooms[command - 1]->getName() << "." << std::endl;
            } else {
                std::cout << "Invalid room selection. Please choose a number between 1 and " << numRooms << "." << std::endl;
            }

            std::cout << "Exiting room selection mode." << std::endl;
            choosing_room = false;

            std::cout << std::endl;
            printHelp();
            continue;
        } 

        switch (command) {
            case 1:
                printAvailableRooms(rooms, numRooms);
                std::cout << "Entering room selection mode. Please choose a room (1-" << numRooms << ")." << std::endl << std::endl;
                choosing_room = true;
                continue;
            case 2:
                guide.getCurrentRoomInfo();
                break;
            case 3:
                std::cout << "Traversal history:" << std::endl;
                if (guide.getTraversalHistory().empty()) {
                    std::cout << "No rooms visited yet." << std::endl;
                } else {
                    for (const auto& room : guide.getTraversalHistory()) {
                        room->printInfo();
                    }
                }
                break;
            case 4: {
                Room* maxVisitRoom = getMaxVisitRoom(rooms, numRooms);
                std::cout << "Room with maximum visits: " << maxVisitRoom->getName() << " (" << maxVisitRoom->getVisitCount() << " visits)" << std::endl;
                break;
            }
            case 5:
                exiting = true;
                std::cout << "Exiting the application. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid command. Please enter a number between 1 and 5." << std::endl;
        };
        
        std::cout << std::endl;
        printHelp();
    }

    // I don't care about dangling pointers in the traversal history since the program is exiting.
    for (size_t i = 0; i < numRooms; i++) {
        delete rooms[i];
        rooms[i] = nullptr; // neutralize dangling pointers
    }

    return 0;
}