#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    Room(const string& roomName, const string& roomType, int roomCapacity)
        : name(roomName), type(roomType), capacity(roomCapacity), visitCount(0) {
    }

    void printInfo() const {
        cout << "Название: " << name << '\n';
        cout << "Тип: " << type << '\n';
        cout << "Вместимость: " << capacity << '\n';
        cout << "Количество посещений: " << visitCount << '\n';
    }

    void visit() {
        ++visitCount;
    }

    int getVisitCount() const {
        return visitCount;
    }

    string getName() const {
        return name;
    }
};

class Guide {
private:
    string name;
    Room* currentRoom;

public:
    Guide(const string& guideName) : name(guideName), currentRoom(nullptr) {
    }

    void goToRoom(Room* room) {
        currentRoom = room;

        if (currentRoom != nullptr) {
            currentRoom->visit();
            cout << name << " провёл группу в комнату: "
                 << currentRoom->getName() << '\n';
        }
    }

    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            cout << "Группа пока не находится ни в одной комнате.\n";
            return;
        }

        cout << "Текущая комната:\n";
        currentRoom->printInfo();
    }

    Room* getCurrentRoom() const {
        return currentRoom;
    }
};

const int ROOM_COUNT = 5;

void printMenu() {
    cout << "\n===== Экскурсия по офису Яндекса =====\n";
    cout << "1. Посетить комнату\n";
    cout << "2. Информация о текущей комнате\n";
    cout << "3. Показать все посещённые комнаты\n";
    cout << "4. Самая посещаемая комната\n";
    cout << "5. Выход\n";
    cout << "Выберите пункт: ";
}

void showAvailableRooms(Room* rooms[], int roomCount) {
    cout << "Доступные комнаты:\n";
    for (int i = 0; i < roomCount; ++i) {
        cout << i + 1 << ". " << rooms[i]->getName() << '\n';
    }
}

void showVisitedRooms(Room* rooms[], int roomCount) {
    bool hasVisitedRooms = false;

    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i]->getVisitCount() > 0) {
            hasVisitedRooms = true;
            break;
        }
    }

    if (!hasVisitedRooms) {
        cout << "Пока не посещено ни одной комнаты.\n";
        return;
    }

    cout << "Посещённые комнаты:\n";
    for (int i = 0; i < roomCount; ++i) {
        if (rooms[i]->getVisitCount() > 0) {
            rooms[i]->printInfo();
            cout << '\n';
        }
    }
}

void showMostVisitedRoom(Room* rooms[], int roomCount) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < roomCount; ++i) {
        if (mostVisitedRoom == nullptr ||
            rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
            mostVisitedRoom = rooms[i];
        }
    }

    if (mostVisitedRoom == nullptr || mostVisitedRoom->getVisitCount() == 0) {
        cout << "Пока нет посещённых комнат.\n";
        return;
    }

    cout << "Самая посещаемая комната: "
         << mostVisitedRoom->getName() << '\n';
    cout << "Количество посещений: "
         << mostVisitedRoom->getVisitCount() << '\n';
}

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    Room* rooms[ROOM_COUNT];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Гид");

    int choice = 0;
    bool isRunning = true;

    while (isRunning) {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int roomNumber = 0;
                showAvailableRooms(rooms, ROOM_COUNT);
                cout << "Введите номер комнаты: ";
                cin >> roomNumber;

                if (roomNumber < 1 || roomNumber > ROOM_COUNT) {
                    cout << "Комнаты с таким номером нет.\n";
                    break;
                }

                guide.goToRoom(rooms[roomNumber - 1]);
                break;
            }
            case 2:
                guide.printCurrentRoomInfo();
                break;
            case 3:
                showVisitedRooms(rooms, ROOM_COUNT);
                break;
            case 4:
                showMostVisitedRoom(rooms, ROOM_COUNT);
                break;
            case 5:
                isRunning = false;
                cout << "Экскурсия завершена.\n";
                break;
            default:
                cout << "Некорректный пункт меню.\n";
                break;
        }
    }

    for (int i = 0; i < ROOM_COUNT; ++i) {
        delete rooms[i];
        rooms[i] = nullptr;
    }

    return 0;
}
