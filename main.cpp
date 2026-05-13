#include <iostream>
#include <string>

using namespace std;

// --- 1. Класс Room ---
class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    // Конструктор для инициализации всех полей
    Room(string n, string t, int c) : name(n), type(t), capacity(c), visitCount(0) {}

    // Выводит информацию о комнате
    void printInfo() {
        cout << "Название: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Количество посещений: " << visitCount << endl;
    }

    // Увеличивает количество посещений на 1
    void visit() {
        visitCount++;
    }

    int getVisitCount() {
        return visitCount;
    }

    string getName() {
        return name;
    }

    // Дополнительные геттеры для вывода списка
    string getType() { return type; }
    int getCapacity() { return capacity; }
};

// --- 2. Класс Guide ---
class Guide {
private:
    string name;
    Room* currentRoom; // Указатель на текущую комнату

public:
    Guide(string n) : name(n), currentRoom(nullptr) {}

    // Переводит группу в указанную комнату
    void goToRoom(Room* room) {
        if (room != nullptr) {
            currentRoom = room;
            currentRoom->visit(); // Увеличиваем счётчик посещений
            cout << "Гид " << name << " провел группу в комнату: " << currentRoom->getName() << endl;
        }
    }

    // Выводит информацию о текущей комнате
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

// --- Основная программа ---
int main() {
    // 1. Создание комнат динамически
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    // 2. Создание гида
    Guide guide("Алексей");

    int choice = 0;
    while (true) {
        cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
        cout << "1. Посетить комнату" << endl;
        cout << "2. Информация о текущей комнате" << endl;
        cout << "3. Показать все посещённые комнаты" << endl;
        cout << "4. Самая посещаемая комната" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nДоступные комнаты:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << rooms[i]->getName() << endl;
            }
            cout << "Введите номер комнаты: ";
            int roomIdx;
            cin >> roomIdx;

            if (roomIdx >= 1 && roomIdx <= 5) {
                guide.goToRoom(rooms[roomIdx - 1]);
            } else {
                cout << "Некорректный номер комнаты!" << endl;
            }

        } else if (choice == 2) {
            cout << endl;
            guide.printCurrentRoomInfo();

        } else if (choice == 3) {
            bool found = false;
            cout << "\nПосещённые комнаты:" << endl;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    cout << rooms[i]->getName() << " [" << rooms[i]->getType() 
                         << "] — " << rooms[i]->getVisitCount() << " посещений" << endl;
                    found = true;
                }
            }
            if (!found) cout << "Пока не посещено ни одной комнаты." << endl;

        } else if (choice == 4) {
            Room* mostVisited = nullptr;
            int maxVisits = 0;

            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > maxVisits) {
                    maxVisits = rooms[i]->getVisitCount();
                    mostVisited = rooms[i];
                }
            }

            if (mostVisited != nullptr) {
                cout << "\nСамая посещаемая комната: " << mostVisited->getName() << endl;
                cout << "Количество посещений: " << mostVisited->getVisitCount() << endl;
            } else {
                cout << "\nПока нет посещённых комнат." << endl;
            }

        } else if (choice == 5) {
            cout << "Завершение экскурсии. До встречи в Яндексе!" << endl;
            break;
        } else {
            cout << "Неверный пункт меню, попробуйте снова." << endl;
        }
    }

    // 3. Освобождение памяти
    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}
