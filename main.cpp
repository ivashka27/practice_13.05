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
        visitCount = 0; // Сначала посещений нет
    }

    // Метод: посетить комнату
    void visit() {
        visitCount++;
    }

    // Метод: показать информацию
    void printInfo() {
        cout << "Название: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Вместимость: " << capacity << endl;
        cout << "Посещений: " << visitCount << endl;
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
        currentRoom = nullptr; // Сначала комнаты нет
    }

    // Метод: перейти в комнату
    void goToRoom(Room* r) {
        currentRoom = r;
        if (currentRoom != nullptr) {
            currentRoom->visit(); // Увеличиваем счетчик комнаты
        }
    }

    // Метод: показать где мы
    void showCurrentRoom() {
        if (currentRoom == nullptr) {
            cout << "Группа пока не в комнате." << endl;
        } else {
            cout << "Текущая комната:" << endl;
            currentRoom->printInfo();
        }
    }
};

int main() {
    // Включаем русский язык в консоли
    setlocale(LC_ALL, "Russian");

    // Создаем 5 комнат через new (динамически)
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    // Создаем гида
    Guide guide("Иван");

    int choice;
    bool work = true;

    // Главный цикл меню
    while (work) {
        cout << "\n===== Меню =====" << endl;
        cout << "1. Посетить комнату" << endl;
        cout << "2. Информация о текущей комнате" << endl;
        cout << "3. Список посещённых комнат" << endl;
        cout << "4. Самая посещаемая комната" << endl;
        cout << "5. Выход" << endl;
        cout << "Ваш выбор: ";
        
        cin >> choice;

        // Обработка выбора
        switch (choice) {
        case 1: // Посетить комнату
            cout << "\nСписок комнат:" << endl;
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << rooms[i]->name << endl;
            }
            cout << "Введите номер: ";
            int num;
            cin >> num;
            
            if (num >= 1 && num <= 5) {
                guide.goToRoom(rooms[num - 1]);
                cout << "Перешли в комнату: " << rooms[num - 1]->name << endl;
            } else {
                cout << "Ошибка ввода." << endl;
            }
            break;

        case 2: // Информация
            guide.showCurrentRoom();
            break;

        case 3: // Все посещенные
            {
                bool found = false;
                cout << "\nПосещённые комнаты:" << endl;
                for (int i = 0; i < 5; i++) {
                    if (rooms[i]->visitCount > 0) {
                        cout << rooms[i]->name << " (" << rooms[i]->visitCount << " раз)" << endl;
                        found = true;
                    }
                }
                if (!found) cout << "Пока пусто." << endl;
            }
            break;

        case 4: // Самая популярная
            {
                Room* best = nullptr;
                int maxVisits = -1;
                
                for (int i = 0; i < 5; i++) {
                    if (rooms[i]->visitCount > maxVisits) {
                        maxVisits = rooms[i]->visitCount;
                        best = rooms[i];
                    }
                }

                if (best != nullptr) {
                    cout << "Самая популярная: " << best->name << endl;
                    cout << "Посещений: " << best->visitCount << endl;
                } else {
                    cout << "Ещё никто никуда не ходил." << endl;
                }
            }
            break;

        case 5: // Выход
            work = false;
            break;

        default:
            cout << "Нет такого пункта." << endl;
        }
    }

    // Очистка памяти (удаление комнат)
    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    cout << "Конец программы." << endl;
    return 0;
}