#include "..\\include\\guide.hpp"
#include "..\\include\\room.hpp"

#include <iostream>
#include <limits>

int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    const int peopleInGroup = 20;
    Guide guide("Родя", peopleInGroup);

    while (true) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
        std::cout << "1. Посетить комнату\n";
        std::cout << "2. Информация о текущей комнате\n";
        std::cout << "3. Показать все посещённые комнаты\n";
        std::cout << "4. Самая посещаемая комната\n";
        std::cout << "5. Выход\n";
        std::cout << "6. Общее количество посещений всех комнат\n";
        std::cout << "7. Показать список всех комнат\n";
        std::cout << "Выберите пункт: ";

        int p;
        if (!(std::cin >> p)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите число.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (p) {
        case 1: {
            std::cout << "\nДоступные комнаты:\n";
            for (int i = 0; i < 5; i++) {
                std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
            }
            std::cout << "\nВведите номер комнаты: ";
            int n;
            if (!(std::cin >> n)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введите число.\n";
                break;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (n < 1 || n > 5) {
                std::cout << "Номер от 1 до 5.\n";
                break;
            }

            Room* selected = rooms[n - 1];
            const int before = selected->getVisitCount();
            guide.goToRoom(selected);
            const int after = selected->getVisitCount();

            if (after > before) {
                std::cout << "Гид провёл группу в комнату: " << selected->getName() << "\n";
            }
            break;
        }

        case 2:
            guide.printGuideAndCurrentRoom();
            break;

        case 3: {
            bool was = false;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    if (!was) {
                        std::cout << "Посещённые комнаты:\n";
                        was = true;
                    }
                    rooms[i]->printInfo();
                    std::cout << "\n";
                }
            }
            if (!was) {
                std::cout << "Пока не посещено ни одной комнаты.\n";
            }
            break;
        }

        case 4: {
            int best = 0;
            for (int i = 1; i < 5; i++) {
                if (rooms[i]->getVisitCount() > rooms[best]->getVisitCount()) {
                    best = i;
                }
            }
            if (rooms[best]->getVisitCount() == 0) {
                std::cout << "Пока нет посещённых комнат.\n";
            } else {
                std::cout << "Самая посещаемая комната: " << rooms[best]->getName() << "\n";
                std::cout << "Количество посещений: " << rooms[best]->getVisitCount() << "\n";
            }
            break;
        }

        case 5:
            for (int i = 0; i < 5; i++) {
                delete rooms[i];
                rooms[i] = nullptr;
            }
            return 0;

//расширение для доп. задания

        case 6: {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += rooms[i]->getVisitCount();
            }
            std::cout << "Общее количество посещений (по всем комнатам): " << sum << "\n";
            break;
        }

        case 7:
            std::cout << "Все комнаты:\n";
            for (int i = 0; i < 5; i++) {
                std::cout << i + 1 << ") ";
                rooms[i]->printInfo();
                std::cout << "\n";
            }
            break;

        default:
            std::cout << "Пункт от 1 до 7 (выход — 5).\n";
            break;
        }
    }
}