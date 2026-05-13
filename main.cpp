#include <iostream>
#include "Room.h"
#include "Guide.h"

int main() {
    // Создание 5 комнат динамически
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    // Создание гида
    Guide guide("Анна");

    int choice;
    do {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
        std::cout << "1. Посетить комнату\n";
        std::cout << "2. Информация о текущей комнате\n";
        std::cout << "3. Показать все посещённые комнаты\n";
        std::cout << "4. Самая посещаемая комната\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nДоступные комнаты:\n";
                for (int i = 0; i < 5; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
                }
                int roomNum;
                std::cout << "Введите номер комнаты: ";
                std::cin >> roomNum;
                if (roomNum >= 1 && roomNum <= 5) {
                    guide.goToRoom(rooms[roomNum - 1]);
                } else {
                    std::cout << "Неверный номер комнаты.\n";
                }
                break;
            }
            case 2:
                std::cout << "\nТекущая комната:\n";
                guide.printCurrentRoomInfo();
                break;
            case 3: {
                bool anyVisited = false;
                std::cout << "\nПосещённые комнаты:\n";
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        std::cout << rooms[i]->getName() << " — "
                                  << rooms[i]->getVisitCount() << " посещений\n";
                        anyVisited = true;
                    }
                }
                if (!anyVisited) {
                    std::cout << "Пока не посещено ни одной комнаты.\n";
                }
                break;
            }
            case 4: {
                int maxVisits = -1;
                Room* mostVisited = nullptr;
                for (int i = 0; i < 5; ++i) {
                    int visits = rooms[i]->getVisitCount();
                    if (visits > maxVisits) {
                        maxVisits = visits;
                        mostVisited = rooms[i];
                    }
                }
                if (mostVisited == nullptr || maxVisits == 0) {
                    std::cout << "Пока нет посещённых комнат.\n";
                } else {
                    std::cout << "Самая посещаемая комната: " << mostVisited->getName()
                              << "\nКоличество посещений: " << maxVisits << "\n";
                }
                break;
            }
            case 5:
                std::cout << "Завершение программы.\n";
                break;
            default:
                std::cout << "Неверный пункт. Повторите ввод.\n";
                break;
        }
    } while (choice != 5);

    // Освобождение памяти
    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }

    return 0;
}
