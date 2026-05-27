#include <iostream>
#include <string>
using namespace std;

class Room {
private:
	string name;
	string type;
	int capacity;
	int visitCount;

public:
	Room(string name, string type, int capacity)
		: name(name), type(type), capacity(capacity), visitCount(0) {}

	void printInfo() {
		cout << "Название: " << name << "\n";
		cout << "Тип: " << type << "\n";
		cout << "Вместимость: " << capacity << "\n";
		cout << "Количество посещений: " << visitCount << "\n";
	}

	void visit() {
		visitCount++;
	}

	int getVisitCount() const {return visitCount;}
	string getName() const {return name;}
	string getType() const {return type;}
	int getCapacity() const {return capacity;}
};

class Guide {
private:
	string name;
	Room* currentRoom;

public:
	Guide(string name)
		: name(name), currentRoom(nullptr) {
	}

	void goToRoom(Room* room) {
		currentRoom = room;
		currentRoom->visit();
		cout << "Гид провёл группу в комнату: " << currentRoom->getName() << "\n";
	}

	void printCurrentRoomInfo() {
		if (currentRoom == nullptr) {
			cout << "Группа пока не находится ни в одной комнате.\n";
		}
		else {
			cout << "Текущая комната:\n";
			currentRoom->printInfo();
		}
	}

	Room* getCurrentRoom() const {
		return currentRoom;
	}

	string getName() const {
		return name;
	}
};

int main() {
	const int ROOM_COUNT = 5;
	Room* rooms[ROOM_COUNT];

	rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
	rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
	rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
	rooms[3] = new Room("Зона отдыха", "отдых", 15);
	rooms[4] = new Room("Серверная", "техническая", 5);

	Guide guide("Иван");

	int choice = 0;

	while (true) {
		cout << "\n Экскурсия по офису Яндекса \n";
		cout << "1. Посетить комнату\n";
		cout << "2. Информация о текущей комнате\n";
		cout << "3. Показать все посещённые комнаты\n";
		cout << "4. Самая посещаемая комната\n";
		cout << "5. Выход\n";
		cout << "Выберите пункт: ";
		cin >> choice;

		if (choice == 1) {
			cout << "\nДоступные комнаты:\n";
			for (int i = 0; i < ROOM_COUNT; i++) {
				cout << i + 1 << ". " << rooms[i]->getName() << "\n";
			}
			int roomNum = 0;
			cout << "Введите номер комнаты: ";
			cin >> roomNum;
			if (roomNum < 1 || roomNum > ROOM_COUNT) {
				cout << "Неверный номер комнаты.\n";
			}
			else {
				guide.goToRoom(rooms[roomNum - 1]);
			}
		}

		else if (choice == 2) {
			cout << "\n";
			guide.printCurrentRoomInfo();
		}

		else if (choice == 3) {
			bool anyVisited = false;
			for (int i = 0; i < ROOM_COUNT; i++) {
				if (rooms[i]->getVisitCount() > 0) {
					if (!anyVisited) {
						cout << "\nПосещённые комнаты:\n";
						anyVisited = true;
					}
					cout << rooms[i]->getName()
						<< " — " << rooms[i]->getVisitCount()
						<< " посещений\n";
				}
			}
			if (!anyVisited) {cout << "\nПока не посещено ни одной комнаты.\n";}
		}

		else if (choice == 4) {
			int maxVisits = 0;
			Room* mostVisited = nullptr;
			for (int i = 0; i < ROOM_COUNT; i++) {
				if (rooms[i]->getVisitCount() > maxVisits) {
					maxVisits = rooms[i]->getVisitCount();
					mostVisited = rooms[i];
				}
			}

			if (mostVisited == nullptr) {
				cout << "\nПока нет посещённых комнат.\n";
			}
			else {
				cout << "\nСамая посещаемая комната: " << mostVisited->getName() << "\n";
				cout << "Количество посещений: " << mostVisited->getVisitCount() << "\n";
			}
		}

		else if (choice == 5) {
			cout << "\nЭкскурсия завершена. До свидания!\n";
			break;
		}

		else {cout << "Неверный пункт. Попробуйте снова.\n";}
	}

	for (int i = 0; i < ROOM_COUNT; i++) {
		delete rooms[i];
	}

	return 0;
}