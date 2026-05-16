#include <iostream>
#include <string>
#include <windows.h>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(std::string roomName, std::string roomType, int roomCapacity) {
        name = roomName;
        type = roomType;
        capacity = roomCapacity;
        visitCount = 0;
    }

    void printInfo() {
        std::cout << "Название: " << name << "\n";
        std::cout << "Тип: " << type << "\n";
        std::cout << "Вместимость: " << capacity << "\n";
        std::cout << "Количество посещений: " << visitCount << "\n";
    }

    void visit() {
        visitCount++;
    }

    int getVisitCount() {
        return visitCount;
    }

    std::string getName() {
        return name;
    }
};

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string guideName) {
        name = guideName;
        currentRoom = nullptr; 
    }

    void goToRoom(Room* room) {
        currentRoom = room;
        
        if (currentRoom != nullptr) {
            currentRoom->visit(); 
        }
    }

    void printCurrentRoomInfo() {
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() {
        return currentRoom;
    }
};

int main() {
    
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Иван Палченков");

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
        std::cout << "1. Посетить комнату\n";
        std::cout << "2. Информация о текущей комнате\n";
        std::cout << "3. Показать все посещённые комнаты\n";
        std::cout << "4. Самая посещаемая комната\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "\nДоступные комнаты:\n";
            for (int i = 0; i < 5; ++i) {
                std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
            }
            std::cout << "Введите номер комнаты: ";
            int roomNum;
            std::cin >> roomNum;

            if (roomNum >= 1 && roomNum <= 5) {
                guide.goToRoom(rooms[roomNum - 1]);
                std::cout << "Гид провёл группу в комнату: " << rooms[roomNum - 1]->getName() << "\n";
            } else {
                std::cout << "Неверный номер комнаты!\n";
            }

        } else if (choice == 2) {
            std::cout << "\n";
            guide.printCurrentRoomInfo();

        } else if (choice == 3) {
            std::cout << "\nПосещённые комнаты:\n";
            bool hasVisited = false;
            for (int i = 0; i < 5; ++i) {
                if (rooms[i]->getVisitCount() > 0) {
                    std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений\n";
                    hasVisited = true;
                }
            }
            if (!hasVisited) {
                std::cout << "Пока не посещено ни одной комнаты.\n";
            }

        } else if (choice == 4) {
            Room* mostVisited = nullptr;
            int maxVisits = 0;

            for (int i = 0; i < 5; ++i) {
                if (rooms[i]->getVisitCount() > maxVisits) {
                    maxVisits = rooms[i]->getVisitCount();
                    mostVisited = rooms[i];
                }
            }

            if (mostVisited != nullptr) {
                std::cout << "\nСамая посещаемая комната: " << mostVisited->getName() << "\n";
                std::cout << "Количество посещений: " << maxVisits << "\n";
            } else {
                std::cout << "\nПока нет посещённых комнат.\n";
            }

        } else if (choice == 5) {
            std::cout << "\nЗавершение экскурсии...\n";
        } else {
            std::cout << "\nНеверный пункт меню. Попробуйте снова.\n";
        }
    }

    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }

    return 0;
}