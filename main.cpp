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
        cout << "Название: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Количество посещений: " << visitCount << endl;
    }

    void visit() {
        visitCount = visitCount + 1;
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
        currentRoom = NULL;
    }

    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();
        cout << "Гид провёл группу в комнату: " << currentRoom->getName() << endl;
    }

    void printCurrentRoomInfo() {
        if (currentRoom == NULL) {
            cout << "Группа пока не находится ни в одной комнате." << endl;
        } else {
            cout << "Текущая комната:" << endl;
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {
    Room* rooms[5];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Гид");

    int choice = 0;

    while (choice != 5) {
        cout << endl;
        cout << "===== Экскурсия по офису Яндекса =====" << endl;
        cout << "1. Посетить комнату" << endl;
        cout << "2. Информация о текущей комнате" << endl;
        cout << "3. Показать все посещённые комнаты" << endl;
        cout << "4. Самая посещаемая комната" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        if (choice == 1) {
            int roomNumber;

            cout << endl;
            cout << "Доступные комнаты:" << endl;
            cout << "1. Переговорка Толстой" << endl;
            cout << "2. Кухня 3 этаж" << endl;
            cout << "3. Open space Backend" << endl;
            cout << "4. Зона отдыха" << endl;
            cout << "5. Серверная" << endl;
            cout << "Введите номер комнаты: ";
            cin >> roomNumber;

            if (roomNumber >= 1 && roomNumber <= 5) {
                guide.goToRoom(rooms[roomNumber - 1]);
            } else {
                cout << "Такой комнаты нет." << endl;
            }
        } else if (choice == 2) {
            guide.printCurrentRoomInfo();
        } else if (choice == 3) {
            int i;
            int found = 0;

            for (i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    rooms[i]->printInfo();
                    cout << endl;
                    found = 1;
                }
            }

            if (found == 0) {
                cout << "Пока не посещено ни одной комнаты." << endl;
            }
        } else if (choice == 4) {
            int i;
            int maxVisits = 0;
            int maxIndex = -1;

            for (i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > maxVisits) {
                    maxVisits = rooms[i]->getVisitCount();
                    maxIndex = i;
                }
            }

            if (maxIndex == -1) {
                cout << "Пока нет посещённых комнат." << endl;
            } else {
                cout << "Самая посещаемая комната: " << rooms[maxIndex]->getName() << endl;
                cout << "Количество посещений: " << rooms[maxIndex]->getVisitCount() << endl;
            }
        } else if (choice == 5) {
            cout << "Программа завершена." << endl;
        } else {
            cout << "Неправильный пункт меню." << endl;
        }
    }

    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}
