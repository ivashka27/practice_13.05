#include <iostream>
#include "Room.h"
#include "Guide.h"

using namespace std;

int main() {
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Алексей");
    cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
    cout << "1. Посетить комнату\n2. Информация о текущей комнате\n"
         << "3. Показать все посещённые комнаты\n4. Самая посещаемая комната\n5. Выход\n";

    int choice = 0;
    while (true) {
        cout << "Выберите пункт: ";
        cin >> choice;
        if (choice == 5) break;

        switch (choice) {
            case 1: {
                cout << "\nДоступные комнаты:" << endl;
                for (int i = 0; i < 5; i++) cout << i + 1 << ". " << rooms[i]->getName() << endl;
                int roomIdx;
                cout << "Введите номер комнаты: ";
                cin >> roomIdx;
                if (roomIdx >= 1 && roomIdx <= size(rooms)) guide.goToRoom(rooms[roomIdx - 1]);
                break;
            }
            case 2:
                guide.printCurrentRoomInfo();
                break;
            case 3: {
                bool visitedAny = false;
                for (int i = 0; i < 5; i++) {
                    if (rooms[i]->getVisitCount() > 0) {
                        cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " раз(а)" << endl;
                        visitedAny = true;
                    }
                }
                if (!visitedAny) cout << "Пока не посещено ни одной комнаты." << endl;
                break;
            }
            case 4: {
                Room* maxRoom = rooms[0];
                for (int i = 1; i < 5; i++) {
                    if (rooms[i]->getVisitCount() > maxRoom->getVisitCount()) maxRoom = rooms[i];
                }
                if (maxRoom->getVisitCount() > 0) {
                    cout << "Самая популярная: " << maxRoom->getName() << " (" << maxRoom->getVisitCount() << ")" << endl;
                } else {
                    cout << "Посещённых комнат нет." << endl;
                }
                break;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) delete rooms[i];
    return 0;
}