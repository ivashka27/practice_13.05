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
    Room(const std::string& name, const std::string& type, int capacity)
        : name(name), type(type), capacity(capacity), visitCount(0) {}

    void printInfo() const {
        std::cout << "Название: " << name << "\n";
        std::cout << "Тип: " << type << "\n";
        std::cout << "Вместимость: " << capacity << "\n";
        std::cout << "Кол-во посещений: " << visitCount << "\n";
    }

    void visit() {
        ++visitCount;
    }

    int getVisitCount() const { return visitCount; }
    std::string getName() const { return name; }
    std::string getType() const { return type; }
    int getCapacity() const { return capacity; }
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
        std::cout << "Гид провёл группу в комнату: " << room->getName() << "\n";
    }

    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            currentRoom->printInfo();
        }
    }

    void printInfoWithGuide() const {
        std::cout << "Гид: " << name << "\n";
        printCurrentRoomInfo();
    }

    Room* getCurrentRoom() const { return currentRoom; }
};

void printSeparator() {
    std::cout << "----------------------------------------\n";
}

void printMenu() {
    std::cout << "\n===== Экскурсия по офису Яндекса =====\n";
    std::cout << "1. Посетить комнату\n";
    std::cout << "2. Информация о текущей комнате (с именем гида)\n";
    std::cout << "3. Показать все посещённые комнаты\n";
    std::cout << "4. Самая посещаемая комната\n";
    std::cout << "5. Общее количество посещений\n";
    std::cout << "6. Выход\n";
    std::cout << "Выберите пункт: ";
}

void printRoomList(Room* rooms[], int count) {
    std::cout << "\nДоступные комнаты:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
    }
}

void visitRoom(Guide& guide, Room* rooms[], int count) {
    printRoomList(rooms, count);
    std::cout << "Введите номер комнаты: ";

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > count) {
        std::cout << "Некорректный номер. Попробуйте снова.\n";
        return;
    }

    guide.goToRoom(rooms[choice - 1]);
}

void showVisitedRooms(Room* rooms[], int count) {
    bool anyVisited = false;

    std::cout << "\nПосещённые комнаты:\n";
    printSeparator();

    for (int i = 0; i < count; ++i) {
        if (rooms[i]->getVisitCount() > 0) {
            std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещ.\n";
            anyVisited = true;
        }
    }

    if (!anyVisited) {
        std::cout << "Пока не посещено ни одной комнаты.\n";
    }
}

void showMostVisitedRoom(Room* rooms[], int count) {
    Room* best = nullptr;

    for (int i = 0; i < count; ++i) {
        if (rooms[i]->getVisitCount() > 0) {
            if (best == nullptr || rooms[i]->getVisitCount() > best->getVisitCount()) {
                best = rooms[i];
            }
        }
    }

    std::cout << "\n";
    if (best == nullptr) {
        std::cout << "Пока нет посещённых комнат.\n";
    } else {
        std::cout << "Самая посещаемая комната: " << best->getName() << "\n";
        std::cout << "Количество посещений: " << best->getVisitCount() << "\n";
    }
}

void showTotalVisits(Room* rooms[], int count) {
    int total = 0;
    for (int i = 0; i < count; ++i) {
        total += rooms[i]->getVisitCount();
    }
    std::cout << "\nОбщее количество посещений всех комнат: " << total << "\n";
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
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
        printSeparator();

        switch (choice) {
            case 1:
                visitRoom(guide, rooms, ROOM_COUNT);
                break;
            case 2:
                guide.printInfoWithGuide();
                break;
            case 3:
                showVisitedRooms(rooms, ROOM_COUNT);
                break;
            case 4:
                showMostVisitedRoom(rooms, ROOM_COUNT);
                break;
            case 5:
                showTotalVisits(rooms, ROOM_COUNT);
                break;
            case 6:
                std::cout << "Экскурсия завершена. До свидания.\n";
                for (int i = 0; i < ROOM_COUNT; ++i) {
                    delete rooms[i];
                }
                return 0;
            default:
                std::cout << "Неизвестный пункт. Введите число от 1 до 6.\n";
                break;
        }
    }
}