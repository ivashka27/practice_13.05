#include <iostream>
#include <string>
#include <clocale> // Для русского языка

using namespace std;

// Класс Комната
class Room {
public:
    string name;       // Название
    string type;       // Тип
    int capacity;      // Вместимость
    int visitCount;    // Счетчик посещений

    // Конструктор комнаты
    Room(string n, string t, int c) {
        name = n;
        type = t;
        capacity = c;
        visitCount = 0; 
    }

    // Метод: увеличить счетчик посещений
    void visit() {
        visitCount++;
    }

    // Метод: вывести информацию о комнате
    void printInfo() {
        cout << "Название: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Количество посещений: " << visitCount << endl;
    }

    // Геттеры (по ТЗ)
    int getVisitCount() {
        return visitCount;
    }

    string getName() {
        return name;
    }
};

// Класс Гид
class Guide {
public:
    string name;         // Имя гида
    Room* currentRoom;   // Указатель на комнату, где мы сейчас

    // Конструктор гида
    Guide(string n) {
        name = n;
        currentRoom = nullptr; 
    }

    // Метод: перейти в комнату
    void goToRoom(Room* r) {
        currentRoom = r;
        if (currentRoom != nullptr) {
            currentRoom->visit(); 
        }
    }

    // Метод: вывести информацию о текущей комнате (название из ТЗ)
    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            cout << "Группа пока не находится ни в одной комнате." << endl;
        } else {
            cout << "Текущая комната:" << endl;
            currentRoom->printInfo();
        }
    }

    // Геттер (по ТЗ)
    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {
    // Включаем русский язык
    setlocale(LC_ALL, "Russian");

    // 1. Создаем 5 комнат динамически (new)
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    // 2. Создаем объект гида
    Guide guide("Иван");

    int choice;
    bool work = true;

    // 3. Цикл меню
    while (work) {
        cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
        cout << "1. Посетить комнату" << endl;
        cout << "2. Информация о текущей комнате" << endl;
        cout << "3. Показать все посещённые комнаты" << endl;
        cout << "4. Самая посещаемая комната" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите пункт: ";
        
        cin >> choice;

        switch (choice) {
        case 1: {
            // Посетить комнату
            cout << "\nДоступные комнаты:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << rooms[i]->getName() << endl; // Используем геттер
            }
            cout << "Введите номер комнаты: ";
            int num;
            cin >> num;
            
            if (num >= 1 && num <= 5) {
                guide.goToRoom(rooms[num - 1]);
                cout << "Гид провёл группу в комнату: " << rooms[num - 1]->getName() << endl;
            } else {
                cout << "Некорректный номер комнаты." << endl;
            }
            break;
        }
        case 2: {
            // Информация о текущей комнате
            guide.printCurrentRoomInfo();
            break;
        }
        case 3: {
            // Показать все посещённые комнаты
            bool hasVisited = false;
            cout << "\nПосещённые комнаты:" << endl;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    // Вывод в формате из примера: Имя — Кол-во посещений
                    cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений" << endl;
                    hasVisited = true;
                }
            }
            if (!hasVisited) {
                cout << "Пока не посещено ни одной комнаты." << endl; // Текст из ТЗ
            }
            break;
        }
        case 4: {
            // Найти самую посещаемую комнату
            Room* mostVisited = nullptr;
            int maxCount = -1;
            bool foundAny = false;

            for (int i = 0; i < 5; i++) {
                int visits = rooms[i]->getVisitCount();
                if (visits > 0) {
                    foundAny = true; // Мы нашли хотя бы одну посещенную
                    if (visits > maxCount) {
                        maxCount = visits;
                        mostVisited = rooms[i];
                    }
                }
            }

            if (!foundAny) {
                cout << "Пока нет посещённых комнат." << endl; // Текст из ТЗ
            } else {
                cout << "Самая посещаемая комната: " << mostVisited->getName() << endl;
                cout << "Количество посещений: " << mostVisited->getVisitCount() << endl;
            }
            break;
        }
        case 5: {
            // Выход
            work = false;
            break;
        }
        default:
            cout << "Неверный пункт меню. Попробуйте снова." << endl;
        }
    }

    // 4. Освобождение памяти (delete)
    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    cout << "Программа завершена. Всего доброго!" << endl;
    return 0;
}