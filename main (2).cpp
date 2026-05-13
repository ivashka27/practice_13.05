#include <clocale>
#include <iostream>
#include <limits>
#include "guide.hpp"
#include "room.hpp"

const int ROOM_COUNT = 5;
void printMenu() {
    std::cout << std::endl;
    std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;
    std::cout << "1. Посетить комнату" << std::endl;
    std::cout << "2. Информация о текущей комнате" << std::endl;
    std::cout << "3. Показать все посещённые комнаты" << std::endl;
    std::cout << "4. Самая посещаемая комната" << std::endl;
    std::cout << "5. Выход" << std::endl;
    std::cout << "Выберите пункт: ";
}
void printAvailableRooms(Room* rooms[], int count) {
    std::cout << std::endl;
    std::cout << "Доступные комнаты:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
    }
}
int readNumber() {
    int value;
    std::cin >> value;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите число: ";
        std::cin >> value;
    }
    return value;
}
void visitRoom(Guide& guide, Room* rooms[], int count) {
    printAvailableRooms(rooms, count);
    std::cout << std::endl;
    std::cout << "Введите номер комнаты: ";
    int roomNumber = readNumber();
    if (roomNumber < 1 || roomNumber > count) {
        std::cout << "Комнаты с таким номером нет." << std::endl;
        return;
    }
    guide.goToRoom(rooms[roomNumber - 1]);
}
void printVisitedRooms(Room* rooms[], int count) {
    bool hasVisitedRooms = false;
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (!hasVisitedRooms) {
                std::cout << "Посещённые комнаты:" << std::endl;
                hasVisitedRooms = true;
            }
            rooms[i]->printInfo();
            std::cout << std::endl;
        }
    }
    if (!hasVisitedRooms) {
        std::cout << "Пока не посещено ни одной комнаты." << std::endl;
    }
}
void printMostVisitedRoom(Room* rooms[], int count) {
    Room* mostVisitedRoom = nullptr;
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            if (mostVisitedRoom == nullptr ||
                rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
                mostVisitedRoom = rooms[i];
            }
        }
    }
    if (mostVisitedRoom == nullptr) {
        std::cout << "Пока нет посещённых комнат." << std::endl;
        return;
    }
    std::cout << "Самая посещаемая комната: " << mostVisitedRoom->getName() << std::endl;
    std::cout << "Количество посещений: " << mostVisitedRoom->getVisitCount() << std::endl;
}
void deleteRooms(Room* rooms[], int count) {
    for (int i = 0; i < count; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
}
int main() {
    std::setlocale(LC_ALL, "");
    Room* rooms[ROOM_COUNT];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);
    Guide guide("Иван");
    int menuItem = 0;
    while (menuItem != 5) {
        printMenu();
        menuItem = readNumber();
        std::cout << std::endl;
        switch (menuItem) {
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
                std::cout << "Работа программы завершена." << std::endl;
                break;
            default:
                std::cout << "Такого пункта меню нет." << std::endl;
                break;
        }
    }
    deleteRooms(rooms, ROOM_COUNT);
    return 0;
}
