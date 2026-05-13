#include<iostream>
#include "Room.hpp"
#include "Guide.hpp"

int main(){
    const int count_room = 5;
    Room* rooms[count_room];

    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван");

    int choice = 0;
    while(choice!=5){
        std::cout << "\n===== Экскурсия по офису Яндекса =====" << std::endl;
        std::cout << "1. Посетить комнату"                      << std::endl;
        std::cout << "2. Информация о текущей комнате"          << std::endl;
        std::cout << "3. Показать все посещённые комнаты"       << std::endl;
        std::cout << "4. Самая посещаемая комната"              << std::endl;
        std::cout << "5. Выход"                                 << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin  >> choice;
        std::cout << std::endl;

        if (choice==1){
            std::cout << "Доступные комнаты:" << std::endl;
            for (int i=0; i<count_room; i++){
                std::cout<< i+1 << ". " << rooms[i]->getName() << std::endl;
            }
            int RoomChoice = 0;
            std::cout << "Введите номер комнаты: ";
            std::cin >> RoomChoice;

            if (RoomChoice>=1 && RoomChoice<=count_room){
                guide.goToRoom(rooms[RoomChoice-1]);
            }
            else{
                std::cout << "Неверный номер." << std::endl;
            }
        }

        else if (choice==2){
            guide.printCurrentRoomInfo();
        }

        else if (choice == 3){
            bool anyVisited = false;
            for(int i=0; i<count_room; i++){
                if(rooms[i]->getVisitCount()>0){
                    if (!anyVisited){
                        std::cout<<"Посещённые комнаты:" << std::endl;
                        anyVisited = true;
                    }
                    std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений" << std::endl;
                }
            }
            if (!anyVisited) {
                std::cout<< "Пока не посещено ни одной комнаты." << std::endl;
            }
        }

        else if (choice==4){
            Room* mostVisited = nullptr;
            for (int i=0; i<count_room; i++){
                if (rooms[i]->getVisitCount() > 0) {
                    if (mostVisited == nullptr || rooms[i]->getVisitCount() > mostVisited->getVisitCount()) {
                        mostVisited = rooms[i];
                    }
                }
            }
            if (mostVisited==nullptr){
                std::cout << "Пока нет посещённых комнат." << std::endl;
            }
            else{
                std::cout <<"Самая посещаемая комната: " << mostVisited->getName() << std::endl;
                std::cout<< "Количество посещений: " << mostVisited->getVisitCount() << std::endl;
            }
        }

        else if(choice==5){
            std::cout << "Экскурсия завершена. До свидания!" << std::endl;
        }
        else{
            std::cout << "Неверный пункт. Попробуйте снова." << std::endl;
        }
    }

    for (int i = 0; i < count_room; i++) {
        delete rooms[i];
        rooms[i] = nullptr;
    }
};
