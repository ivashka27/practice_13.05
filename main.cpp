#include <iostream>

#include "Room.h"
#include "Guide.h"

const int ROOM_COUNT = 5;

void printMenu() {
    std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
    std::cout << "1. Посетить комнату\n";
    std::cout << "2. Информация о текущей комнате\n";
    std::cout << "3. Показать все посещённые комнаты\n";
    std::cout << "4. Самая посещаемая комната\n";
    std::cout << "5. Выход\n";
    std::cout << "Выберите пункт: ";
}

void printRooms(Room* rooms[], int size) {
    std::cout << "\nДоступные комнаты:\n";

    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". " << rooms[i]->getName() << '\n';
    }
}

void showVisitedRooms(Room* rooms[], int size) {
    bool hasVisitedRooms = false;

    std::cout << "\nПосещённые комнаты:\n";

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            rooms[i]->printInfo();
            std::cout << '\n';
            hasVisitedRooms = true;
        }
    }

    if (!hasVisitedRooms) {
        std::cout << "Пока не посещено ни одной комнаты.\n";
    }
}

void showMostVisitedRoom(Room* rooms[], int size) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < size; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (mostVisitedRoom == nullptr ||
                rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
                mostVisitedRoom = rooms[i];
            }
        }
    }

    if (mostVisitedRoom == nullptr) {
        std::cout << "\nПока нет посещённых комнат.\n";
        return;
    }

    std::cout << "\nСамая посещаемая комната: "
              << mostVisitedRoom->getName() << '\n';
    std::cout << "Количество посещений: "
              << mostVisitedRoom->getVisitCount() << '\n';
}

int main() {
    Room* rooms[ROOM_COUNT];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван (FIFA_GRANDMASTER)");

    int choice = 0;

    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                printRooms(rooms, ROOM_COUNT);

                int roomNumber;
                std::cout << "\nВведите номер комнаты: ";
                std::cin >> roomNumber;

                if (roomNumber >= 1 && roomNumber <= ROOM_COUNT) {
                    guide.goToRoom(rooms[roomNumber - 1]);
                } else {
                    std::cout << "Некорректный номер комнаты.\n";
                }

                break;
            }

            case 2: {
                guide.printCurrentRoom();
                break;
            }

            case 3: {
                showVisitedRooms(rooms, ROOM_COUNT);
                break;
            }

            case 4: {
                showMostVisitedRoom(rooms, ROOM_COUNT);
                break;
            }

            case 5: {
                std::cout << "Завершение программы.\n";
                break;
            }

            default: {
                std::cout << "Некорректный пункт меню.\n";
                break;
            }
        }

    } while (choice != 5);

    for (int i = 0; i < ROOM_COUNT; i++) {
        delete rooms[i];
    }

    return 0;
}