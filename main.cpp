#include <iostream>
#include "Room.h"
#include "Guide.h"

int main() {
    const int ROOM_COUNT = 5;

    Room* rooms[ROOM_COUNT];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван");

    int choice;

    do {
        std::cout << std::endl;
        std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;
        std::cout << "1. Посетить комнату" << std::endl;
        std::cout << "2. Информация о текущей комнате" << std::endl;
        std::cout << "3. Показать все посещённые комнаты" << std::endl;
        std::cout << "4. Самая посещаемая комната" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        std::cout << std::endl;

        switch (choice) {
        case 1: {
            std::cout << "Доступные комнаты:" << std::endl;

            for (int i = 0; i < ROOM_COUNT; i++) {
                std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
            }

            int roomNumber;

            std::cout << std::endl;
            std::cout << "Введите номер комнаты: ";
            std::cin >> roomNumber;

            if (roomNumber >= 1 && roomNumber <= ROOM_COUNT) {
                guide.goToRoom(rooms[roomNumber - 1]);
            } else {
                std::cout << "Неверный номер комнаты." << std::endl;
            }

            break;
        }

        case 2:
            guide.printCurrentRoomInfo();
            break;

        case 3: {
            bool found = false;

            std::cout << "Посещённые комнаты:" << std::endl;

            for (int i = 0; i < ROOM_COUNT; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    rooms[i]->printInfo();
                    std::cout << std::endl;
                    found = true;
                }
            }

            if (!found) {
                std::cout << "Пока не посещено ни одной комнаты." << std::endl;
            }

            break;
        }

        case 4: {
            Room* mostVisitedRoom = nullptr;

            for (int i = 0; i < ROOM_COUNT; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    if (mostVisitedRoom == nullptr || rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
                        mostVisitedRoom = rooms[i];
                    }
                }
            }

            if (mostVisitedRoom == nullptr) {
                std::cout << "Пока нет посещённых комнат." << std::endl;
            } else {
                std::cout << "Самая посещаемая комната: " << mostVisitedRoom->getName() << std::endl;
                std::cout << "Количество посещений: " << mostVisitedRoom->getVisitCount() << std::endl;
            }

            break;
        }

        case 5:
            std::cout << "Завершение экскурсии." << std::endl;
            break;

        default:
            std::cout << "Неверный пункт меню." << std::endl;
            break;
        }

    } while (choice != 5);

    for (int i = 0; i < ROOM_COUNT; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }

    return 0;
}