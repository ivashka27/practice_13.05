#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// === Класс Room (Комната) ===
class Room {
private:
    string name;
    string type;
    int capacity;
    int visitCount;

public:
    // Конструктор
    Room(string n, string t, int c) : name(n), type(t), capacity(c), visitCount(0) {}

    // Вывод информации о комнате
    void printInfo() const {
        cout << "-----------------------------------" << endl;
        cout << "Название:      " << name << endl;
        cout << "Тип:           " << type << endl;
        cout << "Вместимость:   " << capacity << " чел." << endl;
        cout << "Посещений:     " << visitCount << endl;
        cout << "-----------------------------------" << endl;
    }

    // Увеличение счётчика посещений
    void visit() {
        visitCount++;
    }

    int getVisitCount() const { return visitCount; }
    string getName() const { return name; }
    string getType() const { return type; }
    int getCapacity() const { return capacity; }
};

// === Класс Guide (Гид) ===
class Guide {
private:
    string name;
    Room* currentRoom; // Указатель на текущую комнату

public:
    // Конструктор (изначально гид не в комнате)
    Guide(string n) : name(n), currentRoom(nullptr) {}

    // Переход в комнату
    void goToRoom(Room* room) {
        if (room != nullptr) {
            currentRoom = room;
            currentRoom->visit(); // Вызов метода через указатель
            cout << "\nГид " << name << " провел группу в комнату: " << currentRoom->getName() << endl;
        }
    }

    // Информация о текущей комнате
    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            cout << "\nГруппа пока не находится ни в одной комнате." << endl;
        } else {
            cout << "\nТекущая комната:" << endl;
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() const { return currentRoom; }
};

// === Основная программа ===
int main() {
    setlocale(LC_ALL, "Russian"); // Для корректного отображения кириллицы

    // 1 & 2. Создаем 5 комнат динамически и сохраняем в массив указателей
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    // 3. Создаем гида
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
        
        if (!(cin >> choice)) { // Защита от некорректного ввода (букв)
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 5) break;

        switch (choice) {
            case 1: {
                cout << "\nДоступные комнаты:" << endl;
                for (int i = 0; i < 5; ++i) {
                    cout << i + 1 << ". " << rooms[i]->getName() << endl;
                }
                cout << "Введите номер комнаты: ";
                int roomNum;
                cin >> roomNum;
                if (roomNum >= 1 && roomNum <= 5) {
                    guide.goToRoom(rooms[roomNum - 1]);
                } else {
                    cout << "Неверный номер комнаты!" << endl;
                }
                break;
            }

            case 2:
                guide.printCurrentRoomInfo();
                break;

            case 3: {
                bool found = false;
                cout << "\nПосещённые комнаты:" << endl;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений" << endl;
                        found = true;
                    }
                }
                if (!found) cout << "Пока не посещено ни одной комнаты." << endl;
                break;
            }

            case 4: {
                Room* mostVisited = nullptr;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        if (mostVisited == nullptr || rooms[i]->getVisitCount() > mostVisited->getVisitCount()) {
                            mostVisited = rooms[i];
                        }
                    }
                }

                if (mostVisited != nullptr) {
                    cout << "\nСамая посещаемая комната: " << mostVisited->getName() << endl;
                    cout << "Количество посещений: " << mostVisited->getVisitCount() << endl;
                } else {
                    cout << "\nПока нет посещённых комнат." << endl;
                }
                break;
            }

            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    // 5. Освобождение памяти
    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }

    cout << "Программа завершена. Память очищена." << endl;
    return 0;
}