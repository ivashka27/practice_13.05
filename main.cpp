#include <iostream>

#include "Room.h"
#include "Guide.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    Room* rooms[5];

    rooms[0] = new Room(
        "Переговорка Толстой",
        "переговорная",
        12
    );

    rooms[1] = new Room(
        "Кухня 3 этаж",
        "кухня",
        20
    );

    rooms[2] = new Room(
        "Open space Backend",
        "рабочая зона",
        40
    );

    rooms[3] = new Room(
        "Зона отдыха",
        "отдых",
        15
    );

    rooms[4] = new Room(
        "Серверная",
        "техническая",
        5
    );

    Guide guide("Алексей");

    int choice;

    do {

        cout << endl;

        cout << "===== Экскурсия по офису Яндекса ====="
            << endl;

        cout << "1. Посетить комнату" << endl;

        cout << "2. Информация о текущей комнате"
            << endl;

        cout << "3. Показать все посещённые комнаты"
            << endl;

        cout << "4. Самая посещаемая комната"
            << endl;

        cout << "5. Выход" << endl;

        cout << "Выберите пункт: ";

        cin >> choice;

        if (choice == 1) {

            cout << endl;

            cout << "Доступные комнаты:"
                << endl;

            for (int i = 0; i < 5; i++) {

                cout << i + 1
                    << ". "
                    << rooms[i]->getName()
                    << endl;
            }

            int roomNumber;

            cout << "Введите номер комнаты: ";

            cin >> roomNumber;

            if (roomNumber >= 1 &&
                roomNumber <= 5) {

                guide.goToRoom(
                    rooms[roomNumber - 1]
                );
            }
            else {

                cout << "Неверный номер комнаты."
                    << endl;
            }
        }

        else if (choice == 2) {

            cout << endl;

            guide.printCurrentRoomInfo();
        }

        else if (choice == 3) {

            bool found = false;

            cout << endl;

            cout << "Посещённые комнаты:"
                << endl;

            for (int i = 0; i < 5; i++) {

                if (rooms[i]->getVisitCount() > 0) {

                    found = true;

                    cout << rooms[i]->getName()
                        << " — "
                        << rooms[i]->getVisitCount()
                        << " посещений"
                        << endl;
                }
            }

            if (!found) {

                cout << "Пока не посещено "
                    << "ни одной комнаты."
                    << endl;
            }
        }

        else if (choice == 4) {

            Room* mostVisited = nullptr;

            for (int i = 0; i < 5; i++) {

                if (rooms[i]->getVisitCount() > 0) {

                    if (mostVisited == nullptr ||

                        rooms[i]->getVisitCount() >
                        mostVisited->getVisitCount()) {

                        mostVisited = rooms[i];
                    }
                }
            }

            cout << endl;

            if (mostVisited == nullptr) {

                cout << "Пока нет посещённых комнат."
                    << endl;
            }
            else {

                cout << "Самая посещаемая комната: "
                    << mostVisited->getName()
                    << endl;

                cout << "Количество посещений: "
                    << mostVisited->getVisitCount()
                    << endl;
            }
        }

        else if (choice == 5) {

            cout << "Программа завершена."
                << endl;
        }

        else {

            cout << "Неверный пункт меню."
                << endl;
        }

    } while (choice != 5);

    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}