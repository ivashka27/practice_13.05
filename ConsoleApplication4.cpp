#include <iostream>
#include <string>

using namespace std;

class Room {
public:
    string name;
    string type;
    int capacity;
    int visitCount;

    Room(string n, string t, int c) {
        name = n;
        type = t;
        capacity = c;
        visitCount = 0;
    }

    void printInfo() {
        cout << "Название: " << name << "\n";
        cout << "Тип: " << type << "\n";
        cout << "Вместимость: " << capacity << "\n";
        cout << "Количество посещений: " << visitCount << "\n";
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
public:
    string name;
    Room* currentRoom;

    Guide(string n) {
        name = n;
        currentRoom = nullptr;
    }

    void goToRoom(Room* r) {
        currentRoom = r;
        currentRoom->visit();
        cout << "Гид провёл группу в комнату: " << currentRoom->getName() << "\n";
    }

    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            cout << "Группа пока не находится ни в одной комнате.\n";
        }
        else {
            cout << "Текущая комната:\n";
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Ivan");

    int choice = 0;
    while (choice != 5) {
        cout << "\n===== Экскурсия по офису Яндекса =====\n";
        cout << "1. Посетить комнату\n";
        cout << "2. Информация о текущей комнате\n";
        cout << "3. Показать все посещённые комнаты\n";
        cout << "4. Самая посещаемая комната\n";
        cout << "5. Выход\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nДоступные комнаты:\n";
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << rooms[i]->getName() << "\n";
            }
            cout << "\nВведите номер комнаты: ";
            int num;
            cin >> num;
            if (num >= 1 && num <= 5) {
                guide.goToRoom(rooms[num - 1]);
            }
        }
        else if (choice == 2) {
            cout << "\n";
            guide.printCurrentRoomInfo();
        }
        else if (choice == 3) {
            cout << "\n";
            bool hasVisited = false;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    if (hasVisited == false) {
                        cout << "Посещённые комнаты:\n";
                        hasVisited = true;
                    }
                    cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений\n";
                }
            }
            if (hasVisited == false) {
                cout << "Пока не посещено ни одной комнаты.\n";
            }
        }
        else if (choice == 4) {
            cout << "\n";
            int maxVisits = 0;
            Room* topRoom = nullptr;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > maxVisits) {
                    maxVisits = rooms[i]->getVisitCount();
                    topRoom = rooms[i];
                }
            }
            if (maxVisits == 0) {
                cout << "Пока нет посещённых комнат.\n";
            }
            else {
                cout << "Самая посещаемая комната: " << topRoom->getName() << "\n";
                cout << "Количество посещений: " << maxVisits << "\n";
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}