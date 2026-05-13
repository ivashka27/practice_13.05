#include <iostream>
#include <string>
#include <limits>
#include "room.h"
#include "guide.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showAvailableRooms(Room* rooms[], int roomCount) {
    std::cout << "\nДоступные комнаты:" << std::endl;
    for (int i = 0; i < roomCount; i++) {
        std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
    }
}

void showVisitedRooms(Room* rooms[], int roomCount) {
    std::cout << "\nПосещённые комнаты:" << std::endl;
    bool hasVisited = false;
    
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            std::cout << rooms[i]->getName() << " — " 
                      << rooms[i]->getVisitCount() << " посещений" << std::endl;
            hasVisited = true;
        }
    }
    
    if (!hasVisited) {
        std::cout << "Пока не посещено ни одной комнаты." << std::endl;
    }
}

void showMostVisitedRoom(Room* rooms[], int roomCount) {
    Room* mostVisited = nullptr;
    int maxVisits = -1;
    
    for (int i = 0; i < roomCount; i++) {
        int visits = rooms[i]->getVisitCount();
        if (visits > maxVisits) {
            maxVisits = visits;
            mostVisited = rooms[i];
        }
    }
    
    std::cout << "\n";
    if (mostVisited != nullptr && maxVisits > 0) {
        std::cout << "Самая посещаемая комната: " << mostVisited->getName() << std::endl;
        std::cout << "Количество посещений: " << maxVisits << std::endl;
    } else {
        std::cout << "Пока нет посещённых комнат." << std::endl;
    }
}

void showTotalVisits(Room* rooms[], int roomCount) {
    int total = 0;
    for (int i = 0; i < roomCount; i++) {
        total += rooms[i]->getVisitCount();
    }
    std::cout << "\nОбщее количество посещений всех комнат: " << total << std::endl;
}

int main() {
    const int ROOM_COUNT = 5;

    Room* rooms[ROOM_COUNT];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Анна");
    
    std::cout << "=====================================" << std::endl;
    std::cout << "   Экскурсия по офису Яндекса" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Вас приветствует гид " << guide.getName() << "!" << std::endl;
    
    int choice;
    bool running = true;
    
    while (running) {
        std::cout << "\n=====================================" << std::endl;
        std::cout << "1. Посетить комнату" << std::endl;
        std::cout << "2. Информация о текущей комнате" << std::endl;
        std::cout << "3. Показать все посещённые комнаты" << std::endl;
        std::cout << "4. Самая посещаемая комната" << std::endl;
        std::cout << "5. Показать общее количество посещений" << std::endl;
        std::cout << "6. Выход" << std::endl;
        std::cout << "=====================================" << std::endl;
        std::cout << "Выберите пункт: ";
        
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Ошибка: пожалуйста, введите число!" << std::endl;
            clearInput();
            continue;
        }
        
        switch (choice) {
            case 1: {
                showAvailableRooms(rooms, ROOM_COUNT);
                std::cout << "Введите номер комнаты (1-" << ROOM_COUNT << "): ";
                
                int roomNumber;
                std::cin >> roomNumber;
                
                if (std::cin.fail()) {
                    std::cout << "Ошибка: введите корректный номер!" << std::endl;
                    clearInput();
                    break;
                }
                
                if (roomNumber >= 1 && roomNumber <= ROOM_COUNT) {
                    guide.goToRoom(rooms[roomNumber - 1]);
                } else {
                    std::cout << "Ошибка: неверный номер комнаты!" << std::endl;
                }
                break;
            }
            
            case 2:
                guide.printCurrentRoomInfo();
                break;
                
            case 3:
                showVisitedRooms(rooms, ROOM_COUNT);
                break;
                
            case 4:
                showMostVisitedRoom(rooms, ROOM_COUNT);
                break;
                
            case 5:
                showTotalVisits(rooms, ROOM_COUNT);
                break;
                
            case 6:
                std::cout << "\nЭкскурсия завершена. Спасибо за внимание!" << std::endl;
                running = false;
                break;
                
            default:
                std::cout << "Ошибка: неверный пункт меню! Попробуйте снова." << std::endl;
                break;
        }
    }
    
    std::cout << "\nОсвобождение памяти..." << std::endl;
    for (int i = 0; i < ROOM_COUNT; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
    std::cout << "Память успешно освобождена." << std::endl;
    
    return 0;
}
