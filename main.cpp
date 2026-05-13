#include "Room.h"
#include "Guide.h"
#include <iostream>

int main() {
    const int rCount = 5;

    Room* rooms[rCount];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Валентинович");

    std::cout << std::endl;
    std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;
    std::cout << "1. Посетить комнату" << std::endl;
    std::cout << "2. Информация о текущей комнате" << std::endl;
    std::cout << "3. Показать все посещённые комнаты" << std::endl;
    std::cout << "4. Самая посещаемая комната" << std::endl;
    std::cout << "5. Показать общее количество посещений" << std::endl;
    std::cout << "6. Выход" << std::endl;

    int choice;

    while (choice != 6) 
    {
        std::cout << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        if (choice == 1) //Посетить комнату
        {
            std::cout << std::endl;
            std::cout << "Доступные комнаты:" << std::endl;

            for (int i = 0; i < rCount; i++) 
            {
                std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
            }

            int rNumber;
            std::cout << std::endl;
            std::cout << "Введите номер комнаты: ";
            std::cin >> rNumber;

            if (rNumber >= 1 && rNumber < rCount) 
            {
                guide.goToRoom(rooms[rNumber - 1]);
            } 
            else if (rNumber == 5) 
            {
                int groupSize;
                std::cout << std::endl;
                std::cout << "Введите размер экскурсионной группы: ";
                std::cin >> groupSize;

                if (groupSize >= rooms[4]->getCapacity()) //группа + гид
                {
                    std::cout << std::endl;
                    std::cout << "Экскурсионной группа слищком большая.";
                }
                else 
                {
                    guide.goToRoom(rooms[rNumber - 1]);
                }
            }
            else 
            {
                std::cout << "Такой комнаты нет." << std::endl;
            }
        }
        else if (choice == 2) //Информация о текущей комнате
        {
            std::cout << std::endl;
            guide.printCurrentRoomInfo();
        } 
        else if (choice == 3) //Показать все посещённые комнаты
        {
            std::cout << std::endl;
            
            bool hasVisitedRooms = false;
            
            for (int i = 0; i < rCount; i++) {
                if (rooms[i]->getVisitCount() > 0) 
                {
                    rooms[i]->printInfo();
                    std::cout << std::endl;
                    hasVisitedRooms = true;
                }
            }

            if (!hasVisitedRooms) {
                std::cout << "Пока не посещено ни одной комнаты." << std::endl;
            }
        } 
        else if (choice == 4) //Самая посещаемая комната
        {
            std::cout << std::endl;

            Room* popularRoom = nullptr;
            for (int i = 0; i < rCount; i++) {
                if (rooms[i]->getVisitCount() > 0)
                {
                    if (popularRoom == nullptr ||
                    rooms[i]->getVisitCount() > popularRoom->getVisitCount()) 
                    {
                        popularRoom = rooms[i];
                    }
                }
            }

            if (popularRoom == nullptr) {
                std::cout << "Пока нет посещённых комнат." << std::endl;
            } else {
                std::cout << "Самая посещаемая комната: " << popularRoom->getName() << std::endl;
                std::cout << "Количество посещений: " << popularRoom->getVisitCount() << std::endl;
            }
        }
        else if (choice == 5) //Показать общее количество посещений
        {
            int totalVisits = 0;

            for (int i = 0; i < rCount; i++) {
                totalVisits += rooms[i]->getVisitCount();
            }

            std::cout << "Общее количество посещений: " << totalVisits << std::endl;
        }
        else if (choice == 6) //Выход
        {
            std::cout << "Экскурсия завершена."<< std::endl;
        }
        



    }
}