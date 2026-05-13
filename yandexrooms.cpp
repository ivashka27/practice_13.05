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
    Room(std::string rName, std::string rType, int rCapacity)
        : name(rName), type(rType), capacity(rCapacity), visitCount(0) {
    }

    void printInfo() const {
        std::cout << "название: " << name << "\n"
            << "тип: " << type << "\n"
            << "вместимость: " << capacity << "\n"
            << "количество посещений: " << visitCount << "\n";
    }

    void printHistoryLine() const {
        std::cout << name << " – " << visitCount << " посещений\n";
    }

    void visit() { visitCount++; }
    int getVisitCount() const { return visitCount; }
    int getCapacity() const { return capacity; }
    std::string getName() const { return name; }
};

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(std::string gName) : name(gName), currentRoom(nullptr) {}

    void goToRoom(Room* room) {
        if (room != nullptr) {
            currentRoom = room;
            currentRoom->visit();
        }
    }

    void printGuideAndRoomInfo() const {
        std::cout << "гид экскурсии: " << name << "\n";
        if (currentRoom != nullptr) {
            std::cout << "текущая локация группы:\n";
            currentRoom->printInfo();
        }
        else {
            std::cout << "группа пока не находится ни в одной комнате.\n";
        }
    }

    Room* getCurrentRoom() const { return currentRoom; }
};


int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    const int ROOMS_COUNT = 5;
    Room* office[ROOMS_COUNT];

    office[0] = new Room("переговорка Толстой", "переговорная", 27);
    office[1] = new Room("кухня 3 этаж", "кухня", 55);
    office[2] = new Room("Open space Backend", "рабочая зона", 67);
    office[3] = new Room("зона отдыха", "отдых", 42);
    office[4] = new Room("серверная", "техническая", 33);

    Guide* guide = new Guide("Иван");

    int groupSize = 0;
    std::cout << "введите количество человек в группе: ";
    std::cin >> groupSize;

    int choice = 0;

    while (true) {
        std::cout << "\n<- экскурсия по офису яндекса ->\n";
        std::cout << "1)посетить комнату\n";
        std::cout << "2)информация о текущей комнате\n";
        std::cout << "3)показать все посещённые комнаты\n";
        std::cout << "4)самая посещаемая комната\n";
        std::cout << "5)показать список всех доступных комнат\n";
        std::cout << "6)выход\n";
        std::cout << "выберите пункт: ";
        std::cin >> choice;

        if (choice == 6) {
            break;
        }

        switch (choice) {
        case 1: {
            std::cout << "\nдоступные комнаты:\n";
            for (int i = 0; i < ROOMS_COUNT; ++i) {
                std::cout << i + 1 << ". " << office[i]->getName()
                    << " (вместимость: " << office[i]->getCapacity() << ")\n";
            }
            std::cout << "\nвведите номер комнаты: ";
            int roomChoice;
            std::cin >> roomChoice;

            if (roomChoice >= 1 && roomChoice <= ROOMS_COUNT) {
                Room* targetRoom = office[roomChoice - 1];

                if (targetRoom->getName() == "серверная" && groupSize > targetRoom->getCapacity()) {
                    std::cout << "группа слишком большая для Серверной \n";
          
                }
                else {
                    guide->goToRoom(targetRoom);
                    std::cout << "Иван провёл группу в комнату: " << targetRoom->getName() << "\n";
                }
            }
            else {
                std::cout << "неверный номер комнаты!\n";
            }
            break;
        }
        case 2: {
            std::cout << "\n";
            guide->printGuideAndRoomInfo();
            break;
        }
        case 3: {
            std::cout << "\nпосещённые комнаты:\n";
            bool anyVisited = false;
            int totalVisits = 0;

            for (int i = 0; i < ROOMS_COUNT; ++i) {
                totalVisits += office[i]->getVisitCount();
            }

            std::cout << "общее количество посещений всех комнат: " << totalVisits << "\n";
            std::cout << "----------------------\n";

            for (int i = 0; i < ROOMS_COUNT; ++i) {
                if (office[i]->getVisitCount() > 0) {
                    office[i]->printHistoryLine();
                    anyVisited = true;
                }
            }

            if (!anyVisited) {
                std::cout << "пока не посещено ни одной комнаты.\n";
            }
            break;
        }
        case 4: {
            std::cout << "\n";
            Room* mostVisited = office[0];
            bool anyVisits = false;

            for (int i = 0; i < ROOMS_COUNT; ++i) {
                if (office[i]->getVisitCount() > 0) {
                    anyVisits = true;
                }
                if (office[i]->getVisitCount() > mostVisited->getVisitCount()) {
                    mostVisited = office[i];
                }
            }

            if (!anyVisits) {
                std::cout << "пока нет посещённых комнат.\n";
            }
            else {
                std::cout << "самая посещаемая комната: " << mostVisited->getName() << "\n"
                    << "количество посещений: " << mostVisited->getVisitCount() << "\n";
            }
            break;
        }
        case 5: {
            std::cout << "\n--- список всех комнат офиса яндекс ---\n";
            for (int i = 0; i < ROOMS_COUNT; ++i) {
                office[i]->printInfo();
                std::cout << "----------------------\n";
            }
            break;
        }
        default:
            std::cout << "неверный пункт меню. попробуйте снова.\n";
            break;
        }
    }

    for (int i = 0; i < ROOMS_COUNT; ++i) {
        delete office[i];
    }
    delete guide;

    return 0;
}
