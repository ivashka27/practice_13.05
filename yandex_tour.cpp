#include <iostream>
#include <string>

class Room {
private:
    std::string name;
    std::string type;
    int capacity;
    int visitCount;

public:
    Room(const std::string& n, const std::string& t, int cap)
        : name(n), type(t), capacity(cap), visitCount(0) {}

    void printInfo() const {
        std::cout << "Название: " << name << "\n"
                  << "Тип: " << type << "\n"
                  << "Вместимость: " << capacity << "\n"
                  << "Количество посещений: " << visitCount << std::endl;
    }

    void visit() { ++visitCount; }
    int getVisitCount() const { return visitCount; }
    const std::string& getName() const { return name; }
    int getCapacity() const { return capacity; }  // для проверки доп задания с сервеной
};

class Guide {
private:
    std::string name;
    int groupSize;  // размер группы тоже для допа
    Room* currentRoom;

public:
    Guide(const std::string& n, int size) : name(n), groupSize(size), currentRoom(nullptr) {}

    void goToRoom(Room* room) {
        if (room == nullptr) return;
        
        // запрет на серверную, если группа больше вместимости
        if (room->getName() == "Серверная" && groupSize > room->getCapacity()) {
            std::cout << "Доступ воспрещен! Группа из " << groupSize 
                      << " человек не может зайти в серверную (вместимость: " 
                      << room->getCapacity() << "!)." << std::endl;
            return;
        }
        
        currentRoom = room;
        currentRoom->visit();
        std::cout << "Гид " << name << " провёл группу из " << groupSize 
                  << " человек в комнату: " << currentRoom->getName() << std::endl;
    }

    // имя гида и инфа о текущей комнате для допа
    void printGuideAndRoomInfo() const {
        std::cout << "Гид: " << name << std::endl;
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
        } else {
            currentRoom->printInfo();
        }
    }

    void printCurrentRoomInfo() const {
        if (currentRoom == nullptr) {
            std::cout << "Группа пока не находится ни в одной комнате." << std::endl;
        } else {
            currentRoom->printInfo();
        }
    }

    Room* getCurrentRoom() const { return currentRoom; }
    int getGroupSize() const { return groupSize; }  // геттер для вывода общего колва посещений
};

int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Ивашка27", 6);

    int choice;
    do {
        std::cout << "\n~~~ Экскурсия по офису Яндекса ~~~\n";
        std::cout << "1. Посетить комнату\n";
        std::cout << "2. Информация о гиде и текущей комнате\n";
        std::cout << "3. Показать все посещённые комнаты\n";
        std::cout << "4. Самая посещаемая комната\n";
        std::cout << "5. Общее количество посещений всех комнат\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "\nДоступные комнаты:\n";
                for (int i = 0; i < 5; ++i) {
                    std::cout << i + 1 << ". " << rooms[i]->getName() 
                              << " (вместимость: " << rooms[i]->getCapacity() << ")" << std::endl;
                }
                int num;
                std::cout << "Введите номер комнаты: ";
                std::cin >> num;
                if (num >= 1 && num <= 5) {
                    guide.goToRoom(rooms[num - 1]);
                } else {
                    std::cout << "Неверный номер." << std::endl;
                }
                break;
            }
            case 2:
                std::cout << std::endl;
                guide.printGuideAndRoomInfo();
                break;
            case 3: {
                std::cout << "\nПосещенные комнаты:\n";
                bool any = false;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > 0) {
                        any = true;
                        std::cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount()
                                  << " посещений" << std::endl;
                    }
                }
                if (!any) {
                    std::cout << "Пока не посещено ни одной комнаты." << std::endl;
                }
                break;
            }
            case 4: {
                int maxCount = -1;
                int maxIndex = -1;
                for (int i = 0; i < 5; ++i) {
                    if (rooms[i]->getVisitCount() > maxCount) {
                        maxCount = rooms[i]->getVisitCount();
                        maxIndex = i;
                    }
                }
                if (maxCount <= 0) {
                    std::cout << "Пока нет посещенных комнат." << std::endl;
                } else {
                    std::cout << "\nСамая посещаемая комната: " << rooms[maxIndex]->getName()
                              << "\nКоличество посещений: " << maxCount << std::endl;
                }
                break;
            }
            case 5: {
                int total = 0;
                for (int i = 0; i < 5; ++i) {
                    total += rooms[i]->getVisitCount();
                }
                std::cout << "\nОбщее количество посещений всех комнат: " << total << std::endl;
                break;
            }
            case 6:
                std::cout << "Завершение работы..." << std::endl;
                break;
            default:
                std::cout << "Неверный пункт. Повторите ввод." << std::endl;
        }
    } while (choice != 6);

    // долгожданная свобода (только для памяти, к сожалению)
    for (int i = 0; i < 5; ++i) {
        delete rooms[i];
    }

    return 0;
}
