#include <iostream>
#include "Room.h"
#include "Guide.h"

int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Гид");

    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====" << std::endl;
        std::cout << "1. Посетить комнату" << std::endl;
        std::cout << "2. Информация о текущей комнате" << std::endl;
        std::cout << "3. Показать все посещённые комнаты" << std::endl;
        std::cout << "4. Самая посещаемая комната" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nДоступные комнаты:" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
                }
                int num;
                std::cout << "Введите номер комнаты: ";
                std::cin >> num;
                if (num >= 1 && num <= 5) {
                    guide.goToRoom(rooms[num - 1]);
                } else {
                    std::cout << "Неверный номер комнаты." << std::endl;
                }
                break;
            }
            case 2: {
                guide.printCurrentRoomInfo();
                break;
            }
            case 3: {
                bool any = false;
                std::cout << "\nПосещённые комнаты:" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        std::cout << rooms[i]->getName()
                                  << " — " << rooms[i]->getVisitCount() << " посещений" << std::endl;
                        any = true;
                    }
                }
                if (!any) {
                    std::cout << "Пока не посещено ни одной комнаты." << std::endl;
                }
                break;
            }
            case 4: {
                int maxCount = -1;
                int maxIndex = -1;
                for (int i = 0; i < 5; ++i) {
                    int cnt = rooms[i]->getVisitCount();
                    if (cnt > maxCount) {
                        maxCount = cnt;
                        maxIndex = i;
                    }
                }
                if (maxCount <= 0) {
                    std::cout << "Пока нет посещённых комнат." << std::endl;
                } else {
                    std::cout << "Самая посещаемая комната: "
                              << rooms[maxIndex]->getName() << std::endl;
                    std::cout << "Количество посещений: " << maxCount << std::endl;
                }
                break;
            }
            case 5: {
                running = false;
                std::cout << "Завершение программы." << std::endl;
                break;
            }
            default: {
                std::cout << "Неверный пункт. Повторите ввод." << std::endl;
                break;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }

    return 0;
}