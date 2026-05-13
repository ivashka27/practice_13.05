#include "Guide.hpp"

#include <clocale>
#include <iostream>
#include <limits>

const int ROOM_COUNT = 5;

void configureConsole() {
    std::setlocale(LC_ALL, "Russian");
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void createRooms(Room* rooms[]) {
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);
}

void deleteRooms(Room* rooms[], int roomCount) {
    for (int i = 0; i < roomCount; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
}

void printMenu() {
    std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
    std::cout << "1. Посетить комнату\n";
    std::cout << "2. Информация о текущей комнате\n";
    std::cout << "3. Показать все посещенные комнаты\n";
    std::cout << "4. Самая посещаемая комната\n";
    std::cout << "5. Выход\n";
    std::cout << "Выберите пункт: ";
}

void printRoomList(Room* rooms[], int roomCount) {
    std::cout << "\nДоступные комнаты:\n";
    for (int i = 0; i < roomCount; i++) {
        std::cout << i + 1 << ". " << rooms[i]->getName() << '\n';
    }
}

void visitRoom(Guide& guide, Room* rooms[], int roomCount) {
    printRoomList(rooms, roomCount);

    std::cout << "\nВведите номер комнаты: ";
    int roomNumber;
    std::cin >> roomNumber;

    if (!std::cin || roomNumber < 1 || roomNumber > roomCount) {
        std::cout << "Некорректный номер комнаты\n";
        clearInput();
        return;
    }

    guide.goToRoom(rooms[roomNumber - 1]);
}

void printVisitedRooms(Room* rooms[], int roomCount) {
    bool hasVisitedRooms = false;
    int totalVisitCount = 0;

    for (int i = 0; i < roomCount; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (!hasVisitedRooms) {
                std::cout << "\nПосещенные комнаты:\n";
                hasVisitedRooms = true;
            }

            rooms[i]->printInfo();
            std::cout << '\n';
            totalVisitCount += rooms[i]->getVisitCount();
        }
    }

    if (!hasVisitedRooms) {
        std::cout << "Пока не посещено ни одной комнаты\n";
        return;
    }

    std::cout << "Общее количество посещений: " << totalVisitCount << '\n';
}

void printMostVisitedRoom(Room* rooms[], int roomCount) {
    Room* mostVisitedRoom = nullptr;

    for (int i = 0; i < roomCount; i++) {
        if (mostVisitedRoom == nullptr || rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
            mostVisitedRoom = rooms[i];
        }
    }

    if (mostVisitedRoom == nullptr || mostVisitedRoom->getVisitCount() == 0) {
        std::cout << "Пока нет посещенных комнат\n";
        return;
    }

    std::cout << "Самая посещаемая комната: " << mostVisitedRoom->getName() << '\n';
    std::cout << "Количество посещений: " << mostVisitedRoom->getVisitCount() << '\n';
}

int main() {
    configureConsole();

    Room* rooms[ROOM_COUNT];
    createRooms(rooms);

    Guide guide("Mr Guide");

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        if (!std::cin) {
            std::cout << "Некорректный ввод\n";
            clearInput();
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1:
            visitRoom(guide, rooms, ROOM_COUNT);
            break;
        case 2:
            guide.printCurrentRoomInfo();
            break;
        case 3:
            printVisitedRooms(rooms, ROOM_COUNT);
            break;
        case 4:
            printMostVisitedRoom(rooms, ROOM_COUNT);
            break;
        case 5:
            std::cout << "Экскурсия завершена\n";
            break;
        default:
            std::cout << "Такого пункта меню нет\n";
            break;
        }
    } while (choice != 5);

    deleteRooms(rooms, ROOM_COUNT);

    return 0;
}
