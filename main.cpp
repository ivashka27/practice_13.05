#include "Room.h"
#include "Guide.h"
#include "printMenu.h"

#include <iostream>

int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Ivan");

    bool excursion_ongoing = true;
    while (excursion_ongoing) {
        printMenu();

        int input;
        std::cin>>input;
        std::cout<<std::endl;
        std::cout<<std::endl;

        switch (input) {
            case 1: {
                std::cout<<"Доступные комнаты:"<<std::endl;
                int count = 1;
                for (Room* room : rooms) {
                    std::cout<<count<<". "<<room->getName()<<std::endl;
                    count++;
                }

                std::cout<<std::endl;
                std::cout<<"Введите номер комнаты: ";
                int room_input;
                std::cin>>room_input;
                std::cout<<std::endl;
                guide.goToRoom(rooms[room_input-1]);
                break;
            }
            case 2: {
                guide.printCurrentRoomInfo();
                break;
            }
            case 3: {
                int count = 0;

                for (Room* room : rooms) {
                    if (room->getVisitCount() > 0) {
                        if (count == 0) {
                            std::cout<<"Посещённые комнаты:"<<std::endl;
                        }
                        std::cout<<room->getName()<<" — "<<room->getVisitCount()<<" посещений"<<std::endl;
                        count++;
                    }
                }

                if (count == 0) {
                    std::cout<<"Пока не посещено ни одной комнаты."<<std::endl;
                }
                break;
            }
            case 4: {
                int room_to_print = -1;
                int count = 0;
                int max_attends = 0;
                
                for (Room* room : rooms) {
                    if (room->getVisitCount() > max_attends) {
                        room_to_print = count;
                        max_attends = room->getVisitCount();
                    }
                    count++;
                }

                if (room_to_print == -1) {
                    std::cout<<"Пока нет посещённых комнат."<<std::endl;
                }
                else {
                    std::cout<<"Самая посещаемая комната:"<<std::endl;
                    rooms[room_to_print]->printInfo();
                }
                break;
            }
            case 5: {
                std::cout<<"Наша экскурсия подошла к концу! Спасибо за внимание! Вы можете взять ручки от Яндекса)"<<std::endl;
                excursion_ongoing = false;
                break;
            }
        }
        std::cout<<std::endl;
    }

    for (int i=0; i<5; i++) {
        delete rooms[i];
    }

    return 0;
}