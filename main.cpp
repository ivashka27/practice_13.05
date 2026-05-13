#include <iostream>
#include "room.h"
#include "guide.h"

using namespace std;

int main() {
	const int count = 5;
	Room* rooms[count];
	rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
	rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
	rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
	rooms[3] = new Room("Зона отдыха", "отдых", 15);
	rooms[4] = new Room("Серверная", "техническая", 5);

	Guide guide("Иван");

	int choice;
	do {
		cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
		cout << "1. Посетить комнату" << endl;
		cout << "2. Информация о текущей комнате" << endl;
		cout << "3. Показать все посещённые комнаты" << endl;
		cout << "4. Самая посещаемая комната" << endl;
		cout << "5. Выход" << endl;
		cout << "Выберите пункт: ";
		cin >> choice;
		
		cout << "\n";
		switch (choice) {
		case 1: {
			cout << "\nДоступные комнаты:" << endl;
			for (int i = 0; i < count; i++) {
				cout << (i + 1) << ". " << rooms[i]->getName() << endl;
			}
			cout << "Введите номер комнаты: ";
			int num;
			cin >> num;
			if (num >= 1 && num <= count) {
				guide.goToRoom(rooms[num - 1]);
			}
			else {
				cout << "Некорректный номер." << endl;
			}
			break;
		}
		case 2:
			guide.printCurrentRoomInfo();
			break;
		case 3: {
			bool visitedAny = false;
			cout << "Посещённые комнаты:" << endl;
			for (int i = 0; i < count; i++) {
				if (rooms[i]->getVisitCount() > 0) {
					cout << rooms[i]->getName() << " — " << rooms[i]->getVisitCount() << " посещений" << endl;
					visitedAny = true;
				}
			}
			if (!visitedAny) {
				cout << "Пока не посещено ни одной комнаты." << endl;
			}
			break;
		}
		case 4: {
			int maxVisits = 0;
			Room* mostVisited = nullptr;
			for (int i = 0; i < count; i++) {
				if (rooms[i]->getVisitCount() > maxVisits) {
					maxVisits = rooms[i]->getVisitCount();
					mostVisited = rooms[i];
				}
			}
			if (mostVisited == nullptr || maxVisits == 0) {
				cout << "Пока нет посещённых комнат." << endl;
			}
			else {
				cout << "Самая посещаемая комната: " << mostVisited->getName() << endl;
				cout << "Количество посещений: " << maxVisits << endl;
			}
			break;
		}
		case 5:
			cout << "Завершение программы." << endl;
			break;
		default:
			cout << "Некорректный пункт меню." << endl;
		}

	} while (choice != 5);

	for (int i = 0; i < count; i++) {
		delete rooms[i];
	}

	return 0;
}
      