#include <string>
#include <iostream>

class Room {
private:
    std::string name;
    std::string type;
    unsigned int capacity;
    unsigned int visitCount;
public:
    Room(std::string name_, std::string type_, unsigned int capacity_ = 0, unsigned int visitCount_ = 0) :
        name(name_), type(type_), capacity(capacity_), visitCount(visitCount_) {}
    void printInfo() const {
        std::cout << "Текущая комната:\n" 
                  << "Название: " << name << '\n'
                  << "Тип: " << type << '\n'
                  << "Вместимость: " << capacity << '\n'
                  << "Количество посещений: " << visitCount << '\n';
    }
    void visit() {visitCount++;}
    unsigned int getVisitCount() const {return visitCount;}
    std::string getName() const {return name;}
};

class Guide {
private:
    std::string name;
    Room* currentRoom;
public:
    Guide(std::string name_, Room* currentRoom_ = nullptr) 
        : name(name_), currentRoom(currentRoom_) {}
    void goToRoom(Room* room) {
        currentRoom = room;
        currentRoom->visit();
    }
    void printCurrentRoomInfo() const {
        if (currentRoom)
            currentRoom->printInfo();
        else
            std::cout << "Группа пока не находится ни в одной комнате.\n";
    }
    Room* getCurrentRoom() const {return currentRoom;}
};

int main(){
    const int ROOM_COUNT = 5;
    Room* Yandex[ROOM_COUNT] = {new Room("Переговорка Толстой", "переговорная", 12), 
                       new Room("Кухня 3 этаж", "кухня", 20),
                       new Room("Open space Backend", "рабочая зона", 40),
                       new Room("Зона отдыха", "отдых", 15),
                       new Room("Серверная", "техническая", 5)};
    Guide guide("Пётр Владимирович");
    int decision = -1;
    std::cout << "===== Экскурсия по офису Яндекса =====\n"
            << "1. Посетить комнату\n" 
            << "2. Информация о текущей комнате\n"
            << "3. Показать все посещённые комнаты\n"
            << "4. Самая посещаемая комната\n"
            << "5. Выход\n";
            
    while (decision != 5){
        std::cout << "\nВыберите пункт: ";
        std::cin >> decision;
        std::cout << '\n';
        switch (decision)
        {
        case 1:{
            std::cout << "Доступные комнаты:\n";
            for (int i = 0; i < ROOM_COUNT; i++){
                std::cout << i + 1 << ". " << Yandex[i]->getName() << '\n';
            }
            std::cout << "\nВведите номер комнаты: ";
            int roomChoise = 0;
            std::cin >> roomChoise;
            if (1 <= roomChoise && roomChoise <= ROOM_COUNT){
                std::cout << "Гид провёл группу в комнату: " << Yandex[roomChoise - 1]->getName() << '\n';
                guide.goToRoom(Yandex[roomChoise - 1]);
            }
            else {
                std::cout << "Такой комнаты нет.\n";
            }
            break;
        }
        case 2:
            guide.printCurrentRoomInfo();
            break;
        case 3:{
            bool flag = true;
            int allVisits = 0;
            for (int i = 0; i < ROOM_COUNT; i++){
                unsigned int visitCount = Yandex[i]->getVisitCount();
                allVisits += visitCount;
                if (visitCount != 0){
                    if (flag){
                        std::cout << "Посещённые комнаты:\n";
                        flag = false;
                    }
                    std::cout << Yandex[i]->getName() << " - " << visitCount << " посещений\n";
                }
            }
            if (allVisits == 0)
                std::cout << "Пока не посещено ни одной комнаты.\n";
            else
                std::cout << "Всего было посещений компнат: " << allVisits << '\n';
            break;
        }
        case 4:{
            int roomWithMaxVisits = -1;
            unsigned int maxVisits = 0;
            for (int i = 0; i < ROOM_COUNT; i++){
                unsigned int visitCount = Yandex[i]->getVisitCount();
                if (visitCount > maxVisits){
                    roomWithMaxVisits = i;
                    maxVisits = visitCount;
                }
            }
            if (roomWithMaxVisits != -1){
                std::cout << "Самая посещаемая комната: " << Yandex[roomWithMaxVisits]->getName() << '\n';
                std::cout << "Количество посещений: " << maxVisits << '\n';
            }
            else
                std::cout << "Пока нет посещённых комнат.\n";
            break;
        }
        case 5:
            std::cout << "Прощай!\n";
            break;
        default:
            std::cout << "Такого пункта нет.\n";
            break;
        }
    }
    for (int i = 0; i < ROOM_COUNT; i++){
        delete Yandex[i];
    }
}