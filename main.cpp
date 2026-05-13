#include <iostream>
#include "Office.h"

int main() {
    const int COUNT = 5;
    Room* rooms[COUNT];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Алексей");
    int choice = 0;

    while (true) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n"
                  << "1. Посетить комнату\n"
                  << "2. Информация о текущей комнате\n"
                  << "3. Показать все посещённые комнаты\n"
                  << "4. Самая посещаемая комната\n"
                  << "5. Выход\n"
                  << "Выберите пункт: ";
        
        if (!(std::cin >> choice)) break;

        if (choice == 1) {
            std::cout << "\nДоступные комнаты:\n";
            for (int i = 0; i < COUNT; i++) {
                std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
            }
            std::cout << "\nВведите номер комнаты: ";
            int idx;
            std::cin >> idx;
            if (idx >= 1 && idx <= COUNT) {
                guide.goToRoom(rooms[idx - 1]);
            }
        } 
        else if (choice == 2) {
            guide.printCurrentRoomInfo();
        }
        else if (choice == 3) {
            bool anyVisited = false;
            for (int i = 0; i < COUNT; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    if (!anyVisited) std::cout << "Посещённые комнаты:\n";
                    std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений\n";
                    anyVisited = true;
                }
            }
            if (!anyVisited) std::cout << "Пока не посещено ни одной комнаты." << std::endl;
        }
        else if (choice == 4) {
            Room* top = nullptr;
            for (int i = 0; i < COUNT; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    if (!top || rooms[i]->getVisitCount() > top->getVisitCount()) {
                        top = rooms[i];
                    }
                }
            }
            if (top) {
                std::cout << "Самая посещаемая комната: " << top->getName() << "\n"
                          << "Количество посещений: " << top->getVisitCount() << std::endl;
            } else {
                std::cout << "Пока нет посещённых комнат." << std::endl;
            }
        }
        else if (choice == 5) {
            break;
        }
    }

    for (int i = 0; i < COUNT; i++) {
        delete rooms[i];
    }

    return 0;
}
