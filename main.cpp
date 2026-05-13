#include "Excursion.hpp"
#include <iostream>

Room** createRooms(size_t size) {
	Room** rooms = new Room*[size];

	rooms[0] = new Room("Переговорка Толстой",  "Переговорная", 12);
        rooms[1] = new Room("Кухня 3 этаж", "Кухня", 20);
        rooms[2] = new Room("Open space Backend", "Рабочая зона", 40);
	rooms[3] = new Room("Зона отдыха", "Отдых", 15);
        rooms[4] = new Room("Серверная", "Техническая", 5);

	return rooms;
}

void showMenu() {
        std::cout << "===== Экскурсия по офису Яндекса =====\n";
        std::cout << "1. Посетить комнату\n";
        std::cout << "2. Информация о текущей комнате\n";
        std::cout << "3. Показать все посещённые комнаты\n";
        std::cout << "4. Самая посещаемая комната\n";
        std::cout << "5. Выход\n";
}

void deleteRooms(Room** rooms, size_t size) {
	for (int i = 0; i < size; ++i) {
		delete rooms[i];
	}
	delete[] rooms;
}

void showRooms(Room** rooms, size_t size) {
	std::cout << "Доступные комнаты: " << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << i+1 << " " << rooms[i]->getName() << std::endl;
	}
}

void showVisitedRooms(Room** rooms, size_t size) {
	int counter = 0;
	std::cout << "Посещённые комнаты: " << std::endl;
	for (int i = 0; i < size; ++i) {
		Room* room = rooms[i];
		if (room->getVisitCount() > 0) {
			room->printInfo();
			counter += 1;
		}
	}
	if (counter == 0) {
		std::cout << "Пока не посещено ни одной комнаты" << std::endl;
	}
}

void showMostVisitedRoom(Room** rooms, size_t size) {
	Room* MostVisitedRoom = nullptr;
	uint32_t MostVisitedRoomCounter = 0;
	for (int i = 0; i < size; ++i) {
		Room* room = rooms[i];
		if (room->getVisitCount() > MostVisitedRoomCounter) {
			MostVisitedRoom = room;
			MostVisitedRoomCounter = room->getVisitCount();
		}
	}
	if (MostVisitedRoom != nullptr) {
		std::cout << "Самая посещаемая комната: " << MostVisitedRoom->getName() << std::endl;
		std::cout << "Количество посещений: " << MostVisitedRoom->getVisitCount() << std::endl;
	}
	else {
		std::cout << "Группа ещё не посетила ни одной комнаты" << std::endl;
	}
}


int main() {
	size_t size = 5;
	Guide guide = Guide("Иван Валентинович");
	Room** rooms = createRooms(size);
	showMenu();

	while (true) {
        int choice = 0;
	std::cout << "Выберите пункт: ";
	std::cin >> choice;

        switch (choice) {
            case 1: {
		int additionalChoice = 0;
                showRooms(rooms, size);
		std::cout << "Введите номер комнаты: ";
		std::cin >> additionalChoice;
		if (additionalChoice >= 1 && additionalChoice <= size) {
			Room* room = rooms[additionalChoice-1];
			guide.goToRoom(room);
			std::cout << "Гид провёл группу в комнату: " << room->getName() << std::endl;
		}
		else {
			std::cout << "Нужно выбрать число от 1 до 5" << std::endl;
		}
		break;
	    }
            case 2:
                if (guide.getCurrentRoom() != nullptr) {
			std::cout << "Информация о текущей комнате: " << std::endl;
			guide.printCurrentRoom();
		}
		else {
			std::cout << "Экскурсия ещё не началась" << std::endl;
		}
                break;
            case 3:
                showVisitedRooms(rooms, size);
                break;
            case 4:
                showMostVisitedRoom(rooms, size);
                break;
            case 5:
                std::cout << "Завершение экскурсии";
		deleteRooms(rooms, size);
                return 0;
            default:
                std::cout << "Число должно быть от 1 до 5";
                break;
        }
        std::cout << "\n";
    }

}

