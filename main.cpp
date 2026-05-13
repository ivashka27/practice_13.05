#include <iostream>
#include "Room.hpp"
#include "Guide.hpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);

    Guide guide("Алексей");
    int choice = 0;

    while (choice != 5) {
        cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
        cout << "1. Посетить комнату\n2. Информация о текущей комнате\n3. Показать все посещенные комнаты\n4. Самая посещаемая комната\n5. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nДоступные комнаты:" << endl;
            for (int i = 0; i < 5; i++) cout << i + 1 << ". " << rooms[i]->getName() << endl;
            cout << "Введите номер комнаты: ";
            int idx; cin >> idx;
            if (idx >= 1 && idx <= 5) guide.goToRoom(rooms[idx - 1]);
        }
        else if (choice == 2) {
            guide.printCurrentRoomInfo();
        }
        else if (choice == 3) {
            bool any = false;
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений" << endl;
                    any = true;
                }
            }
            if (!any) cout << "Пока не посещено ни одной комнаты." << endl;
        }
        else if (choice == 4) {
            Room* maxRoom = nullptr; 
            for (int i = 0; i < 5; i++) {
                if (rooms[i]->getVisitCount() > 0) {
                    if (maxRoom == nullptr || rooms[i]->getVisitCount() > maxRoom->getVisitCount())
                        maxRoom = rooms[i];
                }
            }
            if (maxRoom) cout << "Самая посещаемая: " << maxRoom->getName() << " (" << maxRoom->getVisitCount() << ")" << endl;
            else cout << "Пока нет посещенных комнат." << endl;
        }
    }


    for (int i = 0; i < 5; i++) {
        delete rooms[i]; 
    }

    return 0;
}