#include <iostream>
#include <string>

class Room {
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string n, std::string t, int c) {
        name = n;
        type = t;
        capacity = c;
        visitCount = 0;
    }

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
};

class Guide {
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string n) {
        name = n;
        currentRoom = nullptr;
    }

    void goToRoom(Room* room) {
        currentRoom = room;
        if (currentRoom != nullptr) {
            currentRoom->visit();
        }
    }

    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате.\n";
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
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван");

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n"
                  << "1. Посетить комнату\n"
                  << "2. Информация о текущей комнате\n"
                  << "3. Показать все посещённые комнаты\n"
                  << "4. Самая посещаемая комната\n"
                  << "5. Выход\n"
                  << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nДоступные комнаты:\n";
                for (int i = 0; i < 5; i++) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
                }
                std::cout << "Введите номер комнаты: ";
                
                int roomNum;
                std::cin >> roomNum;
                
                if (roomNum >= 1 && roomNum <= 5) {
                    guide.goToRoom(rooms[roomNum - 1]);
                    std::cout << "Гид провёл группу в комнату: " << rooms[roomNum - 1]->getName() << "\n";
                } else {
                    std::cout << "Неверный номер комнаты.\n";
                }
                break;
            }
            case 2: {
                std::cout << "\n";
                guide.printCurrentRoomInfo();
                break;
            }
            case 3: {
                std::cout << "\n";
                bool visitedAny = false;
                for (int i = 0; i < 5; i++) {
                    if (rooms[i]->getVisitCount() > 0) {
                        if (!visitedAny) {
                            std::cout << "Посещённые комнаты:\n";
                            visitedAny = true;
                        }
                        std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений\n";
                    }
                }
                if (!visitedAny) {
                    std::cout << "Пока не посещено ни одной комнаты.\n";
                }
                break;
            }
            case 4: {
                std::cout << "\n";
                Room* maxRoom = nullptr;
                for (int i = 0; i < 5; i++) {
                    if (rooms[i]->getVisitCount() > 0) {
                        if (maxRoom == nullptr || rooms[i]->getVisitCount() > maxRoom->getVisitCount()) {
                            maxRoom = rooms[i];
                        }
                    }
                }
                if (maxRoom != nullptr) {
                    std::cout << "Самая посещаемая комната: " << maxRoom->getName() << "\n"
                              << "Количество посещений: " << maxRoom->getVisitCount() << "\n";
                } else {
                    std::cout << "Пока нет посещённых комнат.\n";
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                std::cout << "\nНеверный пункт меню, попробуйте снова.\n";
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}