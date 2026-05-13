#include <iostream> 

#include "guide.hpp"
#include "room.hpp"

int main() {
    const int amount = 5;

    Room* room[amount] = {
        new Room("Переговорка Толстой", "переговорная", 12),
        new Room("Кухня 3 этаж", "кухня", 20),
        new Room("Open space Backend", "рабочая зона", 40),
        new Room("Зона отдыха", "отдых", 15),
        new Room("Серверная", "техническая", 5)
    };

    Guide guide("Макарка");
    int choice = 0;
    bool skip = false;

    while (choice != 6) {
        
        std::cout << std::endl;
        if (skip == true) {
            choice = 1;
            skip = false;
        } else {
            std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;
            std::cout << "1. Посетить комнату" << std::endl;
            std::cout << "2. Информация о текущей комнате" << std::endl;
            std::cout << "3. Показать все посещённые комнаты" << std::endl;
            std::cout << "4. Самая посещаемая комната" << std::endl;
            std::cout << "5. Общее количество посещений всех комнат" << std::endl;
            std::cout << "6. Выход" << std::endl;
            std::cout << "Выберите пункт: ";
            std::cin >> choice;
        }

        if (choice == 1) {
            int chosenRoom = 0;

            
            std::cout << std::endl;
            std::cout << "Доступные комнаты:" << std::endl;

            for (int i = 0; i < amount; i++) {
                std::cout << i + 1 << ". " << room[i]->getName() << std::endl; 
            }
            std::cout << "Напишите 6 чтобы показать все комнаты или ";
            std::cout << "выберите номер комнаты: ";
            std::cin >> chosenRoom;

            if (chosenRoom >= 1 && chosenRoom <= amount) {
                guide.goToRoom(room[chosenRoom - 1]);
            } else if (chosenRoom == 6) {
                skip = true;
            } else {
                std::cout << "Некорректный номер комнаты" << std::endl;
            }

        } else if (choice == 2) {
            
            guide.printCurrentRoomInfo();

        } else if (choice == 3) {
            bool visited = false;

            std::cout << "Посещенные комнаты:" << std::endl;
            for (int i = 0; i < amount; i++) {
                if (room[i]->getVisitCount() > 0) {
                    std::cout << room[i]->getName() << " - "
                              << room[i]->getVisitCount() << " посещений" << std::endl;
                    visited = true;
                }
            }
            if (visited == false) {
                std::cout << "Пока не посещено ни одной комнаты." << std::endl;
            }
        } else if (choice == 4) {
            Room* max = room[0];

            for (int i = 1; i < amount; i++) {
                if (room[i]->getVisitCount() > max->getVisitCount()) {
                    max = room[i];
                }
            }

            if (max->getVisitCount() == 0) {
                std::cout << "Пока нет посещенных комнат." << std::endl;
            } else {
                std::cout << "Самая посещаемая комната: "
                          << max->getName() << std::endl;
                std::cout << "Количество посещений: "
                          << max->getVisitCount() << std::endl;
            }
        } else if (choice == 6) {
            std::cout << "Экскурсия завершена." << std::endl;
        } else if (choice == 5) {
            int total = 0;
            for (int i = 0; i < amount; i++) {
                total = total + room[i]->getVisitCount();
            }
            std::cout << "Всего посещений всех комнат: " << total << std::endl;
        } else {
            std::cout << "Некорректный пункт меню." << std::endl;
        }
    }

    for (int i = 0; i < amount; i++) {
        delete room[i];
    }
    
    return 0;
}
