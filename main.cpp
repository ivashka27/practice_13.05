#include <iostream>
#include <string>

int main() {

    class Room {
    private:

        std::string name, type;
        int capacity, visitCount;

    public:

        Room(std::string name_, std::string type_, int capacity_) {
            name = name_;
            type = type_;
            capacity = capacity_;
            visitCount = 0;
        }

        void printInfo() {
            std::cout << "Название: " << name << "\n";
            std::cout << "Тип: " << type << "\n";
            std::cout << "Вместимость: " << capacity << "\n";
            std::cout << "Счётчик посещений: " << visitCount << "\n";
        }

        void visit() {
            ++visitCount;
        }

        int getVisitCount() const {
            return visitCount;
        }

        std::string getName() const {
            return name;
        }
    };

    class Guide {
    private:

        std::string name;
        Room* currentRoom;

    public:

        Guide(std::string name_) {
            name = name_;
            currentRoom = nullptr;
        }

        void goToRoom(Room* room) {
            currentRoom = room;
            room->visit();
        }

        void printCurrentRoomInfo() {
            if (currentRoom != nullptr) {
                std::cout << "Текущая комната:\n";
                currentRoom->printInfo();
            } else {
                std::cout << "Вы сейчас не находитесь в комнате.\n";
            }
        }

        Room* getCurrentRoom() {
            return currentRoom;
        }
    };

    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорочная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Джарвис");

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n===== Экскурсия по Яндексу =====\n";
        std::cout << "1. Посетить комнату\n";
        std::cout << "2. Информация о текущей комнате\n";
        std::cout << "3. Показать все посещённые комнаты\n";
        std::cout << "4. Самая посещаемая комната\n";
        std::cout << "5. Выход\n\n";
        std::cout << "Выберите пункт: ";

        std::cin >> choice;
        std::cout << "\n";

        if (choice == 1) {
            std::cout << "Доступные комнаты:\n";
            for (int i = 0; i < 5; i++) {
                std::cout << i + 1 << ". " << rooms[i]->getName() << "\n";
            }
            std::cout << "\nВведите номер комнаты: ";
            int roomID;
            std::cin >> roomID;
            guide.goToRoom(rooms[roomID - 1]);
        }
         else if (choice == 2) {
            guide.printCurrentRoomInfo();
        }
         else if (choice == 3) {
            std::cout << "Посещённые комнаты:\n";
            bool found = false;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    std::cout << rooms[i]->getName() << " - "
                              << rooms[i]->getVisitCount() << " посещений\n";
                    found = true;
                }
            }
            if (!found) std::cout << "Пока не посещено ни одной комнаты.\n";
        }
         else if (choice == 4) {
            int maxVis = 0, maxID = 0;
            for (int i = 0; i < 5; i++) {
                int curVis = rooms[i]->getVisitCount();
                if (curVis > maxVis) {
                    maxVis = curVis;
                    maxID = i;
                }
            }
            if (maxVis == 0) {
                std::cout << "Вы не посетили ни одной комнаты!\n";
            } else {
                std::cout << "Самая посещаемая комната: " << rooms[maxID]->getName() << "\n";
                std::cout << "Число посещений: " << maxVis << "\n";
            }
        }
         else if (choice == 5) {
        // Можно ничего не писать - цикл сам завершится при choice = 5
        }
         else {
            std::cout << "Неверный пункт выбора меню!";
        }
    }

    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}