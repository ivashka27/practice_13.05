#include "Room.hpp"
#include "Guide.hpp"
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Валентинович");

    
        std::cout << "\n===== Экскурсия по офису Яндекса =====" << std::endl;
    while (true) {
        std::cout << std::endl;
        std::cout << "1. Посетить комнату" << std::endl;
        std::cout << "2. Информация о текущей комнате" << std::endl;
        std::cout << "3. Показать все посещённые комнаты" << std::endl;
        std::cout << "4. Самая посещаемая комната" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        
        std::string input_choice;
        std::cin >> input_choice;
        if (input_choice.length() != 1 || std::string("12345").find(input_choice[0]) == std::string::npos) {
            std::cout << "\nНекорректный ввод!" << std::endl;
            continue; 
        }
        int choice = input_choice[0] - '0'; 

        if (choice == 5) break;

        switch (choice) {
            case 1: {
                std::cout << "\nДоступные комнаты:" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() << std::endl;
                }
                std::cout << "Введите номер комнаты: ";
                std::string room_input;
                std::cin >> room_input;
                if (room_input.length() == 1 && std::string("12345").find(room_input[0]) != std::string::npos) {
                    int roomNum = room_input[0] - '0';
                    guide.goToRoom(rooms[roomNum - 1]);
                } else {
                    std::cout << "Неверный номер комнаты!" << std::endl;
                }
                break;
            }

            case 2:
                guide.printCurrentRoomInfo();
                break;

            case 3: {
                bool found = false;
                std::cout << "\nПосещённые комнаты:" << std::endl;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений" << std::endl;
                        found = true;
                    }
                }
                if (!found) std::cout << "Пока не посещено ни одной комнаты." << std::endl;
                break;
            }

            case 4: {
                Room* mostVisited = nullptr;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        if (mostVisited == nullptr || rooms[i]->getVisitCount() > mostVisited->getVisitCount()) {
                            mostVisited = rooms[i];
                        }
                    }
                }

                if (mostVisited != nullptr) {
                    std::cout << "\nСамая посещаемая комната: " << mostVisited->getName() << std::endl;
                    std::cout << "Количество посещений: " << mostVisited->getVisitCount() << std::endl;
                } else {
                    std::cout << "\nПока нет посещённых комнат." << std::endl;
                }
                break;
            }

            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }

    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }

    std::cout << "Программа завершена. Память очищена." << std::endl;
    return 0;
}