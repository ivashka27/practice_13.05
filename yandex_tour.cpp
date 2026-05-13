#include <iostream>
#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(const std::string& name, const std::string& type, int capacity)
        : name(name), type(type), capacity(capacity), visitCount(0) {}

    void printInfo() const {
        std::cout << "Название: " << name << "\n"
                  << "Тип: " << type << "\n"
                  << "Вместимость: " << capacity << "\n"
                  << "Количество посещений: " << visitCount << "\n";
    }

    void visit() {
        visitCount++;
    }

    int getVisitCount() const {
        return visitCount;
    }

    std::string getName() const {
        return name;
    }

    std::string getType() const {
        return type;
    }

    int getCapacity() const {
        return capacity;
    }
};

class Guide {
private:
    std::string name;
    Room* currentRoom;

public:
    Guide(const std::string& name)
        : name(name), currentRoom(nullptr) {}

    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();
        std::cout << "Гид " << name << " провёл группу в комнату: " << room->getName() << "\n";
    }

    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() const {
        return currentRoom;
    }

    std::string getName() const {
        return name;
    }
};

void printMenu() {
    std::cout << "\n===== Экскурсия по офису Яндекса =====\n"
              << "1. Посетить комнату\n"
              << "2. Информация о текущей комнате\n"
              << "3. Показать все посещённые комнаты\n"
              << "4. Самая посещаемая комната\n"
              << "5. Выход\n"
              << "Выберите пункт: ";
}

void visitRoom(Guide& guide, Room* rooms[], int count) {
    std::cout << "\nДоступные комнаты:\n";
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
    }
    std::cout << "Введите номер комнаты: ";

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > count) {
        std::cout << "Неверный номер комнаты.\n";
        return;
    }

    guide.goToRoom(rooms[choice - 1]);
}

void showVisitedRooms(Room* rooms[], int count) {
    bool anyVisited = false;

    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            anyVisited = true;
            break;
        }
    }

    if (!anyVisited) {
        std::cout << "Пока не посещено ни одной комнаты.\n";
        return;
    }

    std::cout << "\nПосещённые комнаты:\n";
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            std::cout << rooms[i]->getName()
                      << " — " << rooms[i]->getVisitCount() << " посещений\n";
        }
    }
}

void showMostVisited(Room* rooms[], int count) {
    int maxVisits = 0;
    Room* mostVisited = nullptr;

    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > maxVisits) {
            maxVisits = rooms[i]->getVisitCount();
            mostVisited = rooms[i];
        }
    }

    if (mostVisited == nullptr) {
        std::cout << "Пока нет посещённых комнат.\n";
    } else {
        std::cout << "Самая посещаемая комната: " << mostVisited->getName() << "\n"
                  << "Количество посещений: " << mostVisited->getVisitCount() << "\n";
    }
}

int main() {
    const int ROOM_COUNT = 5;

    Room* rooms[ROOM_COUNT];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Алексей");

    int choice = 0;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                visitRoom(guide, rooms, ROOM_COUNT);
                break;
            case 2:
                guide.printCurrentRoomInfo();
                break;
            case 3:
                showVisitedRooms(rooms, ROOM_COUNT);
                break;
            case 4:
                showMostVisited(rooms, ROOM_COUNT);
                break;
            case 5:
                std::cout << "Экскурсия завершена. До свидания!\n";
                for (int i = 0; i < ROOM_COUNT; i++) {
                    delete rooms[i];
                }
                return 0;
            default:
                std::cout << "Неверный пункт меню. Попробуйте ещё раз.\n";
                break;
        }
    }
}
