#include <iostream>
#include <string>

class Room {
private:
	std::string name;
	std::string type;
	int capacity;
	int visitCount;

public:
	Room(std::string n, std::string t, int c) {
		name = n;
		type = t;
		capacity = c;
		visitCount = 0;
	}

	void printInfo() {
		std::cout << "Имя комнаты: " << name << std::endl;
		std::cout << "Тип комнаты: " << type << std::endl;
		std::cout << "Вместимость комнаты: " << capacity << std::endl;
		std::cout << "Количество посещений в комнате: " << visitCount << std::endl;
	}

	void visit() {
		visitCount += 1;
	}

	int getVisitCount() {
		return visitCount;
	}

	std::string getName() {
		return name;
	}
};

class Guide {
private:
	std::string name;
	Room* currentRoom;

public:
	Guide(std::string n) {
		name = n;
		currentRoom = nullptr;
	}

	void goToRoom(Room* room) {
		currentRoom = room;
		currentRoom->visit();
		std::cout << "Гид провёл группу в комнату: " << currentRoom->getName() << std::endl;
	}

	void printCurrentRoomInfo() {
		currentRoom->printInfo();
	}

	Room* getCurrentRoom() {
		return currentRoom;
	}
};

int main() {
	setlocale(LC_ALL, ".UTF-8");

	const int count_rooms = 5;
	Room* rooms[count_rooms];
	rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
	rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
	rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
	rooms[3] = new Room("Зона отдыха", "отдых", 15);
	rooms[4] = new Room("Серверная", "техническая", 5);

	Guide guide("Ivan");

	std::cout << "===== Экскурсия по офису Яндекса =====" << std::endl;
	std::cout << "1. Посетить комнату" << std::endl;
	std::cout << "2. Информация о текущей комнате" << std::endl;
	std::cout << "3. Показать все посещённые комнаты" << std::endl;
	std::cout << "4. Самая посещаемая комната" << std::endl;
	std::cout << "5. Выход" << std::endl;

	while (true) {
		std::cout << "Выберите пункт: ";
		int num;
		std::cin >> num;

		// пользователь выбрал 1 (посетить комнату)
		if (num == 1) {
			std::cout << std::endl << "Доступные комнаты: " << std::endl;
			for (int i = 1; i <= count_rooms; i++) {
				std::cout << i << ". " << rooms[i - 1]->getName() << std::endl;
			}
			std::cout << "Введите номер комнаты: ";
			int num_room;
			std::cin >> num_room;
			guide.goToRoom(rooms[num_room - 1]);
			std::cout << std::endl;
		}

		// пользователь выбрал 2 (информация о текущей комнате)
		if (num == 2) {
			std::cout << "Текущая комната: " << std::endl;
			guide.printCurrentRoomInfo();
			std::cout << std::endl;
		}

		// пользователь выбрал 3 (показать посещенные комнаты)
		if (num == 3) {
			std::cout << std::endl << "Посещённые комнаты: " << std::endl;
			for (int i = 0; i < count_rooms; i++) {
				if (rooms[i]->getVisitCount() > 0) {
					std::cout << rooms[i]->getName() << " - " << rooms[i]->getVisitCount() << " посещений" << std::endl;
				}
			}
			std::cout << std::endl;
		}

		// пользователь выбрал 4 (самая посещаемая комната)
		if (num == 4) {
			Room* mostVisitedRoom = rooms[0];
			std::cout << std::endl << "Самая посещаемая комната: ";
			for (int i = 0; i < count_rooms; i++) {
				if (rooms[i]->getVisitCount() > mostVisitedRoom->getVisitCount()) {
					mostVisitedRoom = rooms[i];
				}
			}
			std::cout << mostVisitedRoom->getName() << std::endl;
			std::cout << "Количество посещений: " << mostVisitedRoom->getVisitCount();
			std::cout << std::endl;
		}

		// пользователь выбрал 5 (выход)
		if (num == 5) {
			std::cout << std::endl << "Экскурсия завершена" << std::endl;
			break;
		}
	}

	// очистка памяти
	for (int i = 0; i < count_rooms; i++) {
		delete rooms[i];
	}
	return 0;
}
