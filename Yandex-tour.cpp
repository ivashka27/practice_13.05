#include <iostream>
#include <windows.h>
#include "Room.hpp"
#include "Guide.hpp"



int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Пальченков");

    int choice = 0;
    while (true) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====" << std::endl;
        std::cout << "1. Посетить комнату" << std::endl;
        std::cout << "2. Информация о текущей комнате" << std::endl;
        std::cout << "3. Показать все посещённые комнаты" << std::endl;
        std::cout << "4. Самая посещаемая комната" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 5) break;

        switch (choice) {
            case 1: { 
                std::cout << "\nДоступные комнаты:" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
                }
                std::cout << "Введите номер комнаты: ";
                int roomNum;
                std::cin >> roomNum;

                if (roomNum >= 1 && roomNum <= 5) {
                    guide.goToRoom(rooms[roomNum - 1]);
                } else {
                    std::cout << "Ошибка: Неверный номер комнаты!" << std::endl;
                }
                break;
            }
            case 2:
                guide.printCurrentRoomInfo();
                break;
            case 3: {
                bool found = false;
                std::cout << "\nПосещённые комнаты:" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        std::cout << rooms[i]->getName() << " — " 
                                  << rooms[i]->getVisitCount() << " посещений." << std::endl;
                        found = true;
                    }
                }
                if (!found) std::cout << "Пока не посещено ни одной комнаты." << std::endl;
                break;
            }
            case 4: {
                Room* mostVisited = nullptr;
                int maxVisits = 0;

                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > maxVisits) {
                        maxVisits = rooms[i]->getVisitCount();
                        mostVisited = rooms[i];
                    }
                }
                if (mostVisited) {
                    std::cout << "\nСамая посещаемая комната: " << mostVisited->getName() << std::endl;
                    std::cout << "Количество посещений: " << mostVisited->getVisitCount() << std::endl;
                } else {
                    std::cout << "Пока нет посещённых комнат." << std::endl;
                }
                break;
            }
            default:
                std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
        }
    }

    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }
    return 0;
}