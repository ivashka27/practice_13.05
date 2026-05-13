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
    Room(const string& _name, const string& _type, int _capacity) {
        name = _name;
        type = _type;
        capacity = _capacity;
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
    Guide(const string& _name) {
        name = _name;
        currentRoom = nullptr;
    }

    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();
        cout << "Гид " << name <<  " провёл группу в комнату : "
            << currentRoom->getName() << endl;
    }

    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            cout << "Группа пока не находится ни в одной комнате." << endl;
            return;
        }
        cout << "Текущая комната:" << endl;
        currentRoom->printInfo();
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

void printAllRooms(Room* rooms[], int roomCount) {
    cout << endl;
    cout << "Доступные комнаты:" << endl;

    for (int i = 0; i < roomCount; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

void visitRoom(Guide& guide, Room* rooms[], int roomCount) {
    printAllRooms(rooms, roomCount);

    cout << endl;
    cout << "Введите номер комнаты: ";
    int roomNumber;
    cin >> roomNumber;
    if (roomNumber < 1 || roomNumber > roomCount) {
        cout << "Комнаты с таким номером нет." << endl;
        return;
    }
    guide.goToRoom(rooms[roomNumber - 1]);
}

void showVisitedRooms(Room* rooms[], int roomCount) {
    bool flag = false;

    cout << endl;
    cout << "Посещённые комнаты:" << endl;

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            rooms[i]->printInfo();
            cout << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "Пока не посещено ни одной комнаты." << endl;
    }
}

void printMostVisitedRoom(Room* rooms[], int roomCount) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < roomCount; i++) {
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
        return;
    }

    cout << "Самая посещаемая комната: " << mostVisitedRoom->getName() << endl;
    cout << "Количество посещений: " << mostVisitedRoom->getVisitCount() << endl;
}


void deleteRooms(Room* rooms[], int roomCount) {
    for (int i = 0; i < roomCount; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Room* rooms[5];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Валентинович");

    bool isRunning = true;

    while (isRunning) {
        printMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            visitRoom(guide, rooms, 5);
            break;

        case 2:
            cout << endl;
            guide.printCurrentRoomInfo();
            break;

        case 3:
            showVisitedRooms(rooms, 5);
            break;

        case 4:
            printMostVisitedRoom(rooms, 5);
            break;
        case 5:
            isRunning = false;
            break;

        default:
            cout << "Такого пункта нет." << endl;
            break;
        }
    }

    deleteRooms(rooms, 5);

}