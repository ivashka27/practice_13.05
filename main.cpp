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

    void printInfo() const {
        cout << "Название: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Количество посещений: " << visitCount << endl;
    }

    void visit() {
        visitCount++;
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
    Guide(string guideName) {
        name = guideName;
        currentRoom = nullptr;
    }

    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();

        cout << "Гид " << name << " провёл группу в комнату: "
             << currentRoom->getName() << endl;
    }

    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            cout << "Группа пока не находится ни в одной комнате." << endl;
        } else {
            cout << "Текущая комната:" << endl;
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() const {
        return currentRoom;
    }
};

void printMenu() {
    cout << endl;
    cout << "===== Экскурсия по офису Яндекса =====" << endl;
    cout << "1. Посетить комнату" << endl;
    cout << "2. Информация о текущей комнате" << endl;
    cout << "3. Показать все посещённые комнаты" << endl;
    cout << "4. Самая посещаемая комната" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите пункт: ";
}

void printAllRooms(Room* rooms[], int size) {
    cout << endl;
    cout << "Доступные комнаты:" << endl;

    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

void printVisitedRooms(Room* rooms[], int size) {
    bool hasVisitedRooms = false;

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            hasVisitedRooms = true;
            break;
        }
    }

    if (!hasVisitedRooms) {
        cout << "Пока не посещено ни одной комнаты." << endl;
        return;
    }

    cout << "Посещённые комнаты:" << endl;

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            cout << endl;
            rooms[i]->printInfo();
        }
    }
}

void printMostVisitedRoom(Room* rooms[], int size) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (mostVisitedRoom == nullptr ||
                rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
                mostVisitedRoom = rooms[i];
            }
        }
    }

    if (mostVisitedRoom == nullptr) {
        cout << "Пока нет посещённых комнат." << endl;
    } else {
        cout << "Самая посещаемая комната: "
             << mostVisitedRoom->getName() << endl;
        cout << "Количество посещений: "
             << mostVisitedRoom->getVisitCount() << endl;
    }
}

int main() {
    const int roomsCount = 5;

    Room* rooms[roomsCount];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Валентинович");

    int choice = 0;

    while (choice != 5) {
        printMenu();
        cin >> choice;

        cout << endl;

        if (choice == 1) {
            printAllRooms(rooms, roomsCount);

            int roomNumber;

            cout << endl;
            cout << "Введите номер комнаты: ";
            cin >> roomNumber;

            if (roomNumber >= 1 && roomNumber <= roomsCount) {
                guide.goToRoom(rooms[roomNumber - 1]);
            } else {
                cout << "Такой комнаты нет." << endl;
            }
        } else if (choice == 2) {
            guide.printCurrentRoomInfo();
        } else if (choice == 3) {
            printVisitedRooms(rooms, roomsCount);
        } else if (choice == 4) {
            printMostVisitedRoom(rooms, roomsCount);
        } else if (choice == 5) {
            cout << "Экскурсия завершена." << endl;
        } else {
            cout << "Такого пункта меню нет." << endl;
        }
    }

    for (int i = 0; i < roomsCount; i++) {
        delete rooms[i];
    }

    return 0;
}
