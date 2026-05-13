#include <iostream>
#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string n, std::string t, int c) 
        : name(n), type(t), capacity(c), visitCount(0) {}

    void printInfo() {
        std::cout << "Название: " << name << "\n"
                  << "Тип: " << type << "\n"
                  << "Вместимость: " << capacity << "\n"
                  << "Количество посещений: " << visitCount << "\n";
    }

    void visit() {
        visitCount++;
    }

    int getVisitCount() {
        return visitCount;
    }

    std::string getName() {
        return name;
    }
    int getCapacity() { 
        return capacity; 
    }
};

class Guide {
private:
    std::string name;
    int groupSize;
    Room* currentRoom;

public:
    Guide(std::string n, int size) : name(n), groupSize(size), currentRoom(nullptr) {}

    void goToRoom(Room* room) {
        if (room->getName() == "Серверная" && groupSize > room->getCapacity()) {
            std::cout << "[ОТКАЗ] Группа из " << groupSize 
                      << " человек слишком большая для Серверной (вместимость: " 
                      << room->getCapacity() << "). Вход воспрещен!\n";
            return;
        }

        currentRoom = room;
        currentRoom->visit();
        std::cout << "Гид " << name << " провёл группу в комнату: " << currentRoom->getName() << "\n";
    }

    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            currentRoom->printInfo();
        }
    }

    void printGuideAndRoomInfo() {
        std::cout << "--- Информация об экскурсии ---\n";
        std::cout << "Гид: " << name << "\n";
        std::cout << "Размер группы: " << groupSize << " чел.\n";
        
        if (currentRoom == nullptr) {
            std::cout << "Статус: Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    const int ROOMS_COUNT = 5;
    Room* rooms[ROOMS_COUNT];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван", 8);

    int choice = 0;

    while (choice != 7) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n"
                  << "1. Посетить комнату\n"
                  << "2. Информация о гиде и текущей комнате\n"
                  << "3. Показать все посещённые комнаты\n"
                  << "4. Самая посещаемая комната\n"
                  << "5. Показать все доступные комнаты в офисе\n" 
                  << "6. Общее количество посещений офиса\n"
                  << "7. Выход\n"
                  << "Выберите пункт: ";
        
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
            case 1: {
                std::cout << "Куда направимся? Введите номер от 1 до " << ROOMS_COUNT << ": ";
                int roomNum;
                std::cin >> roomNum;

                if (roomNum >= 1 && roomNum <= ROOMS_COUNT) {
                    guide.goToRoom(rooms[roomNum - 1]);
                } else {
                    std::cout << "Неверный номер комнаты!\n";
                }
                break;
            }
            case 2: {
                guide.printGuideAndRoomInfo();
                break;
            }
            case 3: {
                bool hasVisited = false;
                std::cout << "Посещённые комнаты:\n";
                for (int i = 0; i < ROOMS_COUNT; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        std::cout << rooms[i]->getName() << " — " 
                                  << rooms[i]->getVisitCount() << " посещений\n";
                        hasVisited = true;
                    }
                }
                if (!hasVisited) {
                    std::cout << "Пока не посещено ни одной комнаты.\n";
                }
                break;
            }
            case 4: {
                Room* mostVisited = nullptr;
                int maxVisits = 0;

                for (int i = 0; i < ROOMS_COUNT; ++i) {
                    if (rooms[i]->getVisitCount() > maxVisits) {
                        maxVisits = rooms[i]->getVisitCount();
                        mostVisited = rooms[i];
                    }
                }

                if (maxVisits == 0 || mostVisited == nullptr) {
                    std::cout << "Пока нет посещённых комнат.\n";
                } else {
                    std::cout << "Самая посещаемая комната: " << mostVisited->getName() << "\n"
                              << "Количество посещений: " << mostVisited->getVisitCount() << "\n";
                }
                break;
            }
            case 5: {
                std::cout << "Список всех помещений офиса:\n";
                for (int i = 0; i < ROOMS_COUNT; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() 
                              << " (Вместимость: " << rooms[i]->getCapacity() << " чел.)\n";
                }
                break;
            }
            case 6: {
                int totalVisits = 0;
                for (int i = 0; i < ROOMS_COUNT; ++i) {
                    totalVisits += rooms[i]->getVisitCount();
                }
                std::cout << "Общее количество перемещений групп по офису: " << totalVisits << "\n";
                break;
            }
            case 7: {
                std::cout << "Экскурсия завершена. До свидания!\n";
                break;
            }
            default: {
                std::cout << "Неверный пункт меню. Попробуйте снова.\n";
                break;
            }
        }
    }

    for (int i = 0; i < ROOMS_COUNT; ++i) {
        delete rooms[i];
    }

    return 0;
}