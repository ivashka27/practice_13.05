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
        cout << "Гид провёл группу в комнату: " << currentRoom->getName() << endl;
    }

    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            cout << "Группа пока не находится ни в одной комнате." << endl;
        }
        else {
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

    Guide guide("Дарья");

    int choice;

    cout << endl;
        cout << "===== Экскурсия по офису Яндекса =====" << endl;
        cout << "1. Посетить комнату" << endl;
        cout << "2. Информация о текущей комнате" << endl;
        cout << "3. Показать все посещённые комнаты" << endl;
        cout << "4. Самая посещаемая комната" << endl;
        cout << "5. Выход" << endl;

    do {
        cout << "Выберите пункт: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            cout << "Доступные комнаты:" << endl;
            cout << "1. Переговорка Толстой" << endl;
            cout << "2. Кухня 3 этаж" << endl;
            cout << "3. Open space Backend" << endl;
            cout << "4. Зона отдыха" << endl;
            cout << "5. Серверная" << endl;
            cout << endl;
            cout << "Введите номер комнаты: ";
            int roomChoice;
            cin >> roomChoice;
            if ((roomChoice >= 1) && (roomChoice <= 5)) {
                guide.goToRoom(rooms[roomChoice - 1]);
            }
            else {
                cout << "Неверный номер комнаты" << endl;
            }
            cout << endl;
        }
        else if (choice == 2) {
            guide.printCurrentRoomInfo();
            cout << endl;
        }
        else if (choice == 3) {
            bool found = false;
            
            for (int i = 0; i < 5; i++) {

                if (rooms[i]->getVisitCount()>0) {
                    
                    if (found == false){
                        cout << "Посещенные комнаты: " << endl;
                    }
                    rooms[i]->printInfo();
                    cout << endl;
                    found = true;
                }
            }

            if (found == false) {
                cout << "Пока не посещено ни одной комнаты." << endl;
            }
            cout << endl;
        }
        else if (choice == 4) {
            Room* mostVisited = nullptr;

            for (int i = 0; i < 5; i++) {

                if (((mostVisited == nullptr) || (rooms[i]->getVisitCount() > mostVisited->getVisitCount())) && (rooms[i]->getVisitCount() > 0)) {
                    mostVisited = rooms[i];
                }
            }

            if (mostVisited == nullptr) {
                cout << "Пока нет посещённых комнат." << endl;
            }
            else {
                cout << "Самая посещаемая комната: "
                    << mostVisited->getName() << endl;

                cout << "Количество посещений: "
                    << mostVisited->getVisitCount() << endl;
            }
            cout << endl;
        }
        else if (choice == 5) {
            cout << "Завершение программы." << endl;
        }
        else {
            cout << "Некорректный пункт меню." << endl;
        }

    } while (choice != 5);

    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}