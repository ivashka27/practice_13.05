#include <iostream>
#include "Room.h"
#include "Guide.h"

using namespace std;

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

void printRooms(Room* rooms[], int roomCount) {
    cout << endl;
    cout << "Доступные комнаты:" << endl;
    for (int i = 0; i < roomCount; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

void printVisitedRooms(Room* rooms[], int roomCount) {
    bool hasVisitedRooms = false;

    cout << endl;
    cout << "Посещённые комнаты:" << endl;

    for (int i = 0; i < roomCount; i++) {
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

    if (mostVisitedRoom == nullptr) {
        cout << "Пока нет посещённых комнат." << endl;
    } else {
        cout << "Самая посещаемая комната: " << mostVisitedRoom->getName() << endl;
        cout << "Количество посещений: " << mostVisitedRoom->getVisitCount() << endl;
    }
}

int main() {
    const int roomCount = 5;

    Room* rooms[roomCount];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Пальченков Иван Валентинович");

    int choice = 0;

    while (choice != 5) {
        printMenu();
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            printRooms(rooms, roomCount);

            int roomNumber;
            cout << endl;
            cout << "Введите номер комнаты: ";
            cin >> roomNumber;
            cout << endl;

            if (roomNumber >= 1 && roomNumber <= roomCount) {
                guide.goToRoom(rooms[roomNumber - 1]);
                cout << "Гид провёл группу в комнату: "
                     << rooms[roomNumber - 1]->getName() << endl;
            } else {
                cout << "Некорректный номер комнаты." << endl;
            }
        } else if (choice == 2) {
            guide.printCurrentRoomInfoWithGuide();
        } else if (choice == 3) {
            printVisitedRooms(rooms, roomCount);
        } else if (choice == 4) {
            printMostVisitedRoom(rooms, roomCount);
        } else if (choice == 5) {
            cout << "Экскурсия завершена." << endl;
        } else {
            cout << "Некорректный пункт меню." << endl;
        }
    }

    for (int i = 0; i < roomCount; i++) {
        delete rooms[i];
    }

    return 0;
}
