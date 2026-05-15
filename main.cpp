#include <iostream>
#include "excursion.hpp"

using namespace std;

// Функция для вывода меню
void printMenu() {
    cout << "\n===== Экскурсия по офису Яндекса =====" << endl;
    cout << "1. Посетить комнату" << endl;
    cout << "2. Информация о текущей комнате" << endl;
    cout << "3. Показать все посещённые комнаты" << endl;
    cout << "4. Самая посещаемая комната" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите пункт: ";
}

// Функция для вывода списка доступных комнат
void printAvailableRooms(Room* rooms[], int count) {
    cout << "\nДоступные комнаты:" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

// Функция для вывода всех посещённых комнат
void printVisitedRooms(Room* rooms[], int count) {
    bool hasVisited = false;
    cout << "\nПосещённые комнаты:" << endl;
    
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > 0) {
            cout << rooms[i]->getName() << " — " 
                 << rooms[i]->getVisitCount() << " посещений" << endl;
            hasVisited = true;
        }
    }
    
    if (!hasVisited) {
        cout << "Пока не посещено ни одной комнаты." << endl;
    }
}

// Функция для поиска самой посещаемой комнаты
void findMostVisitedRoom(Room* rooms[], int count) {
    int maxVisits = -1;
    Room* mostVisited = nullptr;
    
    for (int i = 0; i < count; i++) {
        if (rooms[i]->getVisitCount() > maxVisits) {
            maxVisits = rooms[i]->getVisitCount();
            mostVisited = rooms[i];
        }
    }
    
    if (mostVisited != nullptr && maxVisits > 0) {
        cout << "\nСамая посещаемая комната: " << mostVisited->getName() << endl;
        cout << "Количество посещений: " << maxVisits << endl;
    } else {
        cout << "\nПока нет посещённых комнат." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    // Создание 5 комнат динамически
    Room* rooms[5];
    rooms[0] = new Room("Переговорка Толстой", "переговорная", 12);
    rooms[1] = new Room("Кухня 3 этаж", "кухня", 20);
    rooms[2] = new Room("Open space Backend", "рабочая зона", 40);
    rooms[3] = new Room("Зона отдыха", "отдых", 15);
    rooms[4] = new Room("Серверная", "техническая", 5);
    
    // Создание гида
    Guide guide("Иван Валентинович");
    
    int choice;
    bool running = true;
    
    // Главный цикл программы
    while (running) {
        printMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: { // Посетить комнату
                printAvailableRooms(rooms, 5);
                cout << "Введите номер комнаты: ";
                int roomNumber;
                cin >> roomNumber;
                
                if (roomNumber >= 1 && roomNumber <= 5) {
                    guide.goToRoom(rooms[roomNumber - 1]);
                } else {
                    cout << "Неверный номер комнаты!" << endl;
                }
                break;
            }
            
            case 2: { // Информация о текущей комнате
                guide.printCurrentRoomInfo();
                break;
            }
            
            case 3: { // Показать все посещённые комнаты
                printVisitedRooms(rooms, 5);
                break;
            }
            
            case 4: { // Самая посещаемая комната
                findMostVisitedRoom(rooms, 5);
                break;
            }
            
            case 5: { // Выход
                cout << "Завершение работы программы..." << endl;
                running = false;
                break;
            }
            
            default: {
                cout << "Неверный пункт меню! Попробуйте снова." << endl;
                break;
            }
        }
    }
    
    // Освобождение памяти
    for (int i = 0; i < 5; i++) {
        delete rooms[i];
    }

    return 0;
}