#include <iostream>
#include <string>
#include <windows.h>


// Класс, описывающий комнату
class Room {
private:
    std::string name;       // Название комнаты
    std::string type;       // Тип комнаты
    int capacity;           // Вместимость
    int visitCount;         // Количество посещений

public:
    // Конструктор для инициализации всех полей
    Room(const std::string& name, const std::string& type, int capacity)
        : name(name), type(type), capacity(capacity), visitCount(0) {}

    // Вывод информации о комнате
    void printInfo() const {
        std::cout << "Название: " << name << std::endl;
        std::cout << "Тип: " << type << std::endl;
        std::cout << "Вместимость: " << capacity << std::endl;
        std::cout << "Количество посещений: " << visitCount << std::endl;
    }

    // Увеличить счётчик посещений
    void visit() {
        ++visitCount;
    }

    // Получить количество посещений
    int getVisitCount() const {
        return visitCount;
    }

    // Получить название комнаты
    std::string getName() const {
        return name;
    }
};

// Класс, описывающий гида
class Guide {
private:
    std::string name;       // Имя гида
    Room* currentRoom;      // Указатель на текущую комнату

public:
    // Конструктор
    Guide(const std::string& name) : name(name), currentRoom(nullptr) {}

    // Перевести группу в указанную комнату
    void goToRoom(Room* room) {
        if (room != nullptr) {
            currentRoom = room;
            currentRoom->visit();
            std::cout << "Гид " << name << " провёл группу в комнату: "
                      << currentRoom->getName() << std::endl;
        }
    }

    // Вывести информацию о текущей комнате
    void printCurrentRoomInfo() const {
        if (currentRoom != nullptr) {
            currentRoom->printInfo();
        } else {
            std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
        }
    }

    // Получить указатель на текущую комнату
    Room* getCurrentRoom() const {
        return currentRoom;
    }
};

// Функция вывода главного меню
void printMenu() {
    std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
    std::cout << "1. Посетить комнату\n";
    std::cout << "2. Информация о текущей комнате\n";
    std::cout << "3. Показать все посещённые комнаты\n";
    std::cout << "4. Самая посещаемая комната\n";
    std::cout << "5. Выход\n";
    std::cout << "Выберите пункт: ";
}

int main() {
    system("chcp 65001");

    // 1. Создание комнат динамически
    const int ROOM_COUNT = 5;
    Room* rooms[ROOM_COUNT];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    // 2. Создание гида
    Guide guide("Иван Валентинович");

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: { // Посетить комнату
                std::cout << "\nДоступные комнаты:\n";
                for (int i = 0; i < ROOM_COUNT; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
                }
                int roomNumber;
                std::cout << "Введите номер комнаты: ";
                std::cin >> roomNumber;
                if (roomNumber >= 1 && roomNumber <= ROOM_COUNT) {
                    guide.goToRoom(rooms[roomNumber - 1]);
                } else {
                    std::cout << "Неверный номер комнаты." << std::endl;
                }
                break;
            }
            case 2: { // Информация о текущей комнате
                std::cout << std::endl;
                guide.printCurrentRoomInfo();
                break;
            }
            case 3: { // Показать все посещённые комнаты
                std::cout << "\nПосещённые комнаты:\n";
                bool anyVisited = false;
                for (int i = 0; i < ROOM_COUNT; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        anyVisited = true;
                        std::cout << rooms[i]->getName() << " — "
                                  << rooms[i]->getVisitCount() << " посещений" << std::endl;
                    }
                }
                if (!anyVisited) {
                    std::cout << "Пока не посещено ни одной комнаты." << std::endl;
                }
                break;
            }
            case 4: { // Самая посещаемая комната
                int maxVisits = 0;
                Room* mostVisited = nullptr;
                for (int i = 0; i < ROOM_COUNT; ++i) {
                    int visits = rooms[i]->getVisitCount();
                    if (visits > maxVisits) {
                        maxVisits = visits;
                        mostVisited = rooms[i];
                    }
                }
                if (mostVisited != nullptr && maxVisits > 0) {
                    std::cout << "\nСамая посещаемая комната: "
                              << mostVisited->getName() << std::endl;
                    std::cout << "Количество посещений: " << maxVisits << std::endl;
                } else {
                    std::cout << "\nПока нет посещённых комнат." << std::endl;
                }
                break;
            }
            case 5: { // Выход
                std::cout << "Завершение программы." << std::endl;
                break;
            }
            default:
                std::cout << "Неверный пункт меню. Попробуйте снова." << std::endl;
        }
    } while (choice != 5);

    // Освобождение памяти
    for (int i = 0; i < ROOM_COUNT; ++i) {
        delete rooms[i];
    }

    return 0;
}