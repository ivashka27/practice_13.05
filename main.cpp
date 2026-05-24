#include "room.hpp"
#include "guide.hpp"

#include <iostream>

int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Палченков");

    int choice = 0;
    while (true) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
        std::cout << "1. посетить комнату\n";
        std::cout << "2. информация о текущей комнате\n";
        std::cout << "3. показать все посещённые комнаты\n";
        std::cout << "4. самая посещаемая комната\n";
        std::cout << "5. выход\n";
        std::cout << "выберите пункт: ";
        std::cin >> choice;

        if (choice == 1) {
            // список доступных комнат
            std::cout << "\nдоступные комнаты:\n";
            for (int i = 0; i < 5; ++i) {
                std::cout << i + 1 << ". " << rooms[i]->name() << "\n";
            }
            std::cout << "введите номер комнаты: ";
            int roomNum;
            std::cin >> roomNum;
            if (roomNum >= 1 && roomNum <= 5) {
                guide.goTo(rooms[roomNum - 1]);
                std::cout << "гид провёл группу в комнату: " << rooms[roomNum - 1]->name() << "\n";
            } else {
                std::cout << "неверный номер комнаты\n";
            }
        } else if (choice == 2) {
            std::cout << "\n";
            guide.printCurrent();
        } else if (choice == 3) {
            // выводим только посещённые комнаты
            std::cout << "\nпосещённые комнаты:\n";
            bool any = false;
            for (int i = 0; i < 5; ++i) {
                if (rooms[i]->visitCount() > 0) {
                    rooms[i]->printInfo();
                    any = true;
                }
            }
            if (!any) {
                std::cout << "пока не посещено ни одной комнаты\n";
            }
        } else if (choice == 4) {
            // находим комнату с максимальным числом посещений
            Room* mostVisited = nullptr;
            int maxVisits = 0;
            for (int i = 0; i < 5; ++i) {
                if (rooms[i]->visitCount() > maxVisits) {
                    maxVisits = rooms[i]->visitCount();
                    mostVisited = rooms[i];
                }
            }
            if (mostVisited != nullptr) {
                std::cout << "\nсамая посещаемая комната: " << mostVisited->name() << "\n";
                std::cout << "количество посещений: " << maxVisits << "\n";
            } else {
                std::cout << "\nпока нет посещённых комнат\n";
            }
        } else if (choice == 5) {
            std::cout << "\nзавершение экскурсии...\n";
            break;
        } else {
            std::cout << "\nневерный пункт меню попробуйте снова\n";
        }
    }
    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }
    return 0;
}
