#include <iostream>
#include <string>
#include <clocale>

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

void showAllRooms(Room* rooms[], int count) {
    cout << endl;
    cout << "Доступные комнаты:" << endl;

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

void visitSelectedRoom(Guide& guide, Room* rooms[], int count) {
    showAllRooms(rooms, count);

    cout << endl;
    cout << "Введите номер комнаты: ";

    int number;
    cin >> number;

    if (number < 1 || number > count) {
        cout << "Комнаты с таким номером нет." << endl;
        return;
    }

    guide.goToRoom(rooms[number - 1]);
}

void showVisitedRooms(Room* rooms[], int count) {
    bool hasVisitedRooms = false;

    cout << endl;
    cout << "Посещённые комнаты:" << endl;

    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            rooms[i]->printInfo();
            cout << endl;
            hasVisitedRooms = true;
        }
    }

    if (!hasVisitedRooms) {
        cout << "Пока не посещено ни одной комнаты." << endl;
    }
}

void showMostVisitedRoom(Room* rooms[], int count) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (mostVisitedRoom == nullptr ||
                rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
                mostVisitedRoom = rooms[i];
            }
        }
    }

    cout << endl;

    if (mostVisitedRoom == nullptr) {
        cout << "Пока нет посещённых комнат." << endl;
    } else {
        cout << "Самая посещаемая комната: "
             << mostVisitedRoom->getName() << endl;
        cout << "Количество посещений: "
             << mostVisitedRoom->getVisitCount() << endl;
    }
}

void deleteRooms(Room* rooms[], int count) {
    for (int i = 0; i < count; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int room_count = 5;

    Room* rooms[room_count];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Валентинович");

    bool running = true;

    while (running) {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            visitSelectedRoom(guide, rooms, room_count);
            break;

        case 2:
            cout << endl;
            guide.printCurrentRoomInfo();
            break;

        case 3:
            showVisitedRooms(rooms, room_count);
            break;

        case 4:
            showMostVisitedRoom(rooms, room_count);
            break;

        case 5:
            running = false;
            break;

        default:
            cout << "Такого пункта меню нет." << endl;
            break;
        }
    }

    deleteRooms(rooms, room_count);

    return 0;
}