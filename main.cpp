#include "excursion.h"
#include <vector>
#include <iostream>

Room *Room1 = new Room("Переговорка Толстой", "Переговорка", 12);
Room *Room2 = new Room("Кухня 3 этаж", "Кухня", 20);
Room *Room3 = new Room("Open space Backend", "Рабочая зона", 40);
Room *Room4 = new Room("Зона отдыха", "Отдых", 15);
Room *Room5 = new Room("Серверная", "Техническая", 5);

std::vector<Room *> roomPointers = {Room1, Room2, Room3, Room4, Room5};

Guide guide = Guide("Pou");

int main()
{
    int exit_flag = 0;
    std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;

    do
    {
        std::cout << std::endl
                  << std::endl
                  << "1. Посетить комнату" << std::endl;
        std::cout << "2. Информация о текущей комнате" << std::endl;
        std::cout << "3. Показать все посещённые комнаты" << std::endl;
        std::cout << "4. Самая посещаемая комната" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите пункт: " << std::endl;

        std::string user_input;
        std::cin >> user_input;

        if (user_input == "1")
        {
            std::cout << "Доступные команты: " << std::endl;
            for (std::size_t i = 0; i < roomPointers.size(); i++)
            {
                std::cout << i + 1 << " " << roomPointers[i]->getName() << std::endl;
            }
            std::cin >> user_input;
            std::size_t roomNumber = std::stoi(user_input) - 1;
            guide.goToRoom(roomPointers[roomNumber]);
        }

        else if (user_input == "2")
        {
            guide.printCurrentRoomInfo();
        }
        else if (user_input == "3")
        {
            bool visitedAnyRooms = false;
            for (auto room : roomPointers)
            {
                if (room->getVisitCount() > 0)
                {
                    room->printInfo();
                    visitedAnyRooms = true;
                }
            }
            if (!visitedAnyRooms)
            {
                std::cout << "Пока не посещено ни одной комнаты." << std::endl;
            }
        }

        else if (user_input == "4")
        {
            // bool visitedAnyRooms = false;
            int max_visitings = 0;
            Room *maxVisitedRoom = nullptr;

            for (auto room : roomPointers)
            {
                if (room->getVisitCount() > max_visitings)
                {
                    max_visitings = room->getVisitCount();
                    maxVisitedRoom = room;
                }
            }
            if (maxVisitedRoom == nullptr)
            {
                std::cout << "Пока нет посещённых комнат." << std::endl;
            }
            else
            {
                std::cout << "Название: " << maxVisitedRoom->getName() << std::endl;
                std::cout << "Количество посещений: " << max_visitings << std::endl;
            }
        }
        else
        {
            exit_flag = 1;
        }
    } while (exit_flag != 1);

    for (auto roomPtr : roomPointers)
    {
        delete roomPtr;
    }
    return 0;
}
