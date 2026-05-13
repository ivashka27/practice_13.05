#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    Room(string roomName, string roomType, int roomCapacity) {
        name = roomName;
        type = roomType;
        capacity = roomCapacity;
        visitCount = 0;
    }

    void printInfo() {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Visit count: " << visitCount << endl;
    }

    void visit() {
        visitCount++;
    }

    int getVisitCount() {
        return visitCount;
    }

    string getName() {
        return name;
    }
};

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(string guideName) {
        name = guideName;
        currentRoom = nullptr;
    }

    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();

        cout << "The guide took the group to the room: "
            << currentRoom->getName() << endl;
    }

    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            cout << "The group is not in any room yet." << endl;
        }
        else {
            cout << "Current room:" << endl;
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {
    const int roomCount = 5;

    Room* rooms[roomCount];

    rooms[0] = new Room("Peregovorka Tolstoy", "peregovornaya", 12);
    rooms[1] = new Room("Kukhnya 3 etazh", "kukhnya", 20);
    rooms[2] = new Room("Open space Backend", "rabochaya zona", 40);
    rooms[3] = new Room("Zona otdykha", "otdykh", 15);
    rooms[4] = new Room("Servernaya", "tekhnicheskaya", 5);

    Guide guide("Guide");

    int choice = 0;

    while (choice != 5) {
        cout << endl;
        cout << "===== Yandex Office Tour =====" << endl;
        cout << "1. Visit a room" << endl;
        cout << "2. Show current room information" << endl;
        cout << "3. Show all visited rooms" << endl;
        cout << "4. Show the most visited room" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        cout << endl;

        if (choice == 1) {
            cout << "Available rooms:" << endl;

            for (int i = 0; i < roomCount; i++) {
                cout << i + 1 << ". " << rooms[i]->getName() << endl;
            }

            int roomNumber;

            cout << endl;
            cout << "Enter room number: ";
            cin >> roomNumber;

            if (roomNumber >= 1 && roomNumber <= roomCount) {
                guide.goToRoom(rooms[roomNumber - 1]);
            }
            else {
                cout << "Invalid room number." << endl;
            }
        }
        else if (choice == 2) {
            guide.printCurrentRoomInfo();
        }
        else if (choice == 3) {
            bool hasVisitedRooms = false;

            cout << "Visited rooms:" << endl;

            for (int i = 0; i < roomCount; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    hasVisitedRooms = true;
                    rooms[i]->printInfo();
                    cout << endl;
                }
            }

            if (!hasVisitedRooms) {
                cout << "No rooms have been visited yet." << endl;
            }
        }
        else if (choice == 4) {
            Room* mostVisitedRoom = nullptr;
            int maxVisits = 0;

            for (int i = 0; i < roomCount; i++) {
                if (rooms[i]->getVisitCount() > maxVisits) {
                    maxVisits = rooms[i]->getVisitCount();
                    mostVisitedRoom = rooms[i];
                }
            }

            if (mostVisitedRoom == nullptr) {
                cout << "There are no visited rooms yet." << endl;
            }
            else {
                cout << "The most visited room: "
                    << mostVisitedRoom->getName() << endl;
                cout << "Visit count: "
                    << mostVisitedRoom->getVisitCount() << endl;
            }
        }
        else if (choice == 5) {
            cout << "The tour is finished." << endl;
        }
        else {
            cout << "Invalid menu option." << endl;
        }
    }

    for (int i = 0; i < roomCount; i++) {
        delete rooms[i];
    }

    return 0;
}
