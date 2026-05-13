#include <iostream>

using namespace std;

class Room{
    private:
        string name;
        string type;
        int capacity;
        int visitCount;
    public:
        Room(string name, string type, int capacity, int visitCount) : name(name), type(type), capacity(capacity), visitCount(visitCount) {}

        void visit(){
            visitCount++;
        }
         
        void printInfo(){
            cout << "Название: " << name << endl;
            cout << "Тип: " << type << endl;
            cout << "Вместимость: " << capacity << endl;
            cout << "Количество посещений: " << visitCount << endl;
            
        }

        int getVisitCount(){ return visitCount; }

        string getName(){ return name; }

};

class Guide{
    private:
        string name;
        Room* currentRoom;
    public:
        Guide(string name) : name(name), currentRoom(nullptr) {}
        
        void goToRoom(Room* room){
            currentRoom = room;
            currentRoom->visit();
        }

        void printCurrentRoomInfo(){
            if (currentRoom == nullptr) {
                cout << "Сначала посетите комнату (пункт 1)." << endl;
                return;
            }
            currentRoom->printInfo();
        }
        void printAllVisitedRooms(Room* rooms[], size_t n){
            cout << "Посещённые комнаты:" << endl;
            for (size_t i = 0; i < n; i++){
                if(rooms[i]->getVisitCount() > 0){
                    cout << " " << endl;
                    rooms[i]->printInfo();
                }
            }
        }
        void printMostVisitedRoom(Room* rooms[], size_t n){
            int maxVisitCount = 0;
            Room* mostVisitedRoom = nullptr;
            for (size_t i = 0; i < n; i++){
                if(rooms[i]->getVisitCount() > maxVisitCount){
                    maxVisitCount = rooms[i]->getVisitCount();
                    mostVisitedRoom = rooms[i];
                }
            }
            if (mostVisitedRoom == nullptr) {
                cout << "Пока нет посещённых комнат." << endl;
                return;
            }
            cout << "Самая посещаемая комната:" << endl;
            cout << " " << endl;
            mostVisitedRoom->printInfo();
        }

        Room* getCurrentRoom(){ return currentRoom; }
        
        
};


int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12, 0);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20, 0);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40, 0);
    rooms[3] = new Room("Зона отдыха", "отдых", 15, 0);
    rooms[4] = new Room("Серверная", "техническая", 5, 0);

    const size_t numRooms = sizeof(rooms) / sizeof(rooms[0]);

    Guide* guide = new Guide("Иван Валерьевич");

    cout << "===== Экскурсия по офису Яндекса =====" << endl;
    cout << "1. Посетить комнату" << endl;
    cout << "2. Информация о текущей комнате" << endl;
    cout << "3. Показать все посещённые комнаты" << endl;
    cout << "4. Самая посещаемая комната" << endl;
    cout << "5. Выход" << endl;

    while(true){
        cout << "Выберите пункт: ";
        int choice;
        cin >> choice;
        cout << " " << endl;
        switch(choice){
            case 1:
                cout << "Доступные комнаты: " << endl;
                for (size_t i = 0; i < numRooms; i++){
                    cout << i + 1 << ". " << rooms[i]->getName() << endl;
                }
                cout << "Введите номер комнаты: ";
                int roomNumber;
                cin >> roomNumber;
                cout << " " << endl;
                guide->goToRoom(rooms[roomNumber - 1]);
                cout << "Гид провёл группу в комнату: " << rooms[roomNumber - 1]->getName() << endl;
                cout << endl;
                break;
            case 2:
                guide->printCurrentRoomInfo();
                break;
            case 3:
                guide->printAllVisitedRooms(rooms, numRooms);
                break;
            case 4:
                guide->printMostVisitedRoom(rooms, numRooms);
                break;
            case 5:
                for (size_t i = 0; i < numRooms; i++){
                    delete rooms[i];
                }
                delete guide;
                return 0;
            default:
                cout << "Некорректный выбор" << endl;
                break;
        }
        cout << "================================================" << endl;
    }

    return 0;
}