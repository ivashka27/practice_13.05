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
    Room(string z, string x, int c) {
        name = z;
        type = x;
        capacity = c;
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
    Guide(string z) {
        name = z;
        currentRoom = nullptr;
    }
    void goToRoom(Room* z) {
        currentRoom = z;
        z->visit();
        cout << "Гид " << name << " провёл группу в комнату: "
             << z->getName() << endl;
    }
    void printCurrentRoomInfo() {
        if (currentRoom != nullptr) {
            cout << "Текущая комната:" << endl;
            currentRoom->printInfo();
        } else {
            cout << "Группа пока не находится ни в одной комнате." << endl;
        }
    }
    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {

    Room* z[5];
    z[0] = new Room("Переговорка Толстой", "переговорная", 12);
    z[1] = new Room("Кухня 3 этаж", "кухня", 20);
    z[2] = new Room("Open space Backend", "рабочая зона", 40);
    z[3] = new Room("Зона отдыха", "отдых", 15);
    z[4] = new Room("Серверная", "техническая", 5);
    Guide x("Экскурсовод");
    int c = 0;
    while (c != 5) {
        cout << endl;
        cout << "===== Экскурсия по офису Яндекса =====" << endl;
        cout << "1. Посетить комнату" << endl;
        cout << "2. Информация о текущей комнате" << endl;
        cout << "3. Показать все посещённые комнаты" << endl;
        cout << "4. Самая посещаемая комната" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> c;
        cout << endl;
        if (c == 1) {
            cout << "Доступные комнаты:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << z[i]->getName() << endl;
            }
            int v;
            cout << "Введите номер комнаты: ";
            cin >> v;
            if (v >= 1 && v <= 5) {
                x.goToRoom(z[v - 1]);
            } else {
                cout << "Неверный номер комнаты." << endl;
            }
        }

        else if (c == 2) {
            x.printCurrentRoomInfo();
        }

        else if (c == 3) {
            bool b = false;
            cout << "Посещённые комнаты:" << endl;
            for (int i = 0; i < 5; i++) {
                if (z[i]->getVisitCount() > 0) {
                    cout << z[i]->getName()
                         << " — " << z[i]->getVisitCount()
                         << " посещений" << endl;
                    b = true;
                }
            }
            if (!b) {
                cout << "Пока не посещено ни одной комнаты." << endl;
            }
        }

        else if (c == 4) {
            int n = 0;
            int id = 0;
            for (int i = 0; i < 5; i++) {
                if (z[i]->getVisitCount() > n) {
                    n = z[i]->getVisitCount();
                    id = i;
                }
            }
            if (n == 0) {
                cout << "Пока нет посещённых комнат." << endl;
            } else {
                cout << "Самая посещаемая комната: "
                     << z[id]->getName() << endl;
                cout << "Количество посещений: " << n << endl;
            }
        }

        else if (c == 5) {
            cout << "Выход из программы." << endl;
        }

        else {
            cout << "Неверный пункт меню." << endl;
        }
    }

    for (int i = 0; i < 5; i++) {
        delete z[i];
    }
    return 0;
}