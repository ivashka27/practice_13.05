#include <iostream>
#include <vector>
#include "room.hpp"
#include "guide.hpp"

using namespace std;

void print_menu() 
{
    cout << endl << "===== Экскурсия по офису Яндекса =====" << endl
         << "1. Посетить комнату" << endl
         << "2. Информация о текущей комнате" << endl
         << "3. Показать все посещённые комнаты" << endl
         << "4. Самая посещаемая комната" << endl
         << "5. Выход" << endl
         << "Выберите пункт: ";
}

void print_available_rooms(const vector<Room*>& rooms) 
{
    cout << endl << "Доступные комнаты:" << endl;
    for (size_t i = 0; i < rooms.size(); i++) 
    {
        cout << i + 1 << ". " << rooms[i]->getName() << endl;
    }
}

void show_visited_rooms(const vector<Room*>& rooms) 
{
    bool has_visited = false;
    cout << endl << "Посещённые комнаты:" << endl;
    
    for (size_t i = 0; i < rooms.size(); i++) 
    {
        if (rooms[i]->getVisitCount() > 0) 
        {
            cout << rooms[i]->getName() << " (" << rooms[i]->getType() 
                 << ", вместимость: " << rooms[i]->getCapacity() 
                 << ") — " << rooms[i]->getVisitCount() << " посещений" << endl;
            has_visited = true;
        }
    }
    
    if (!has_visited) 
    {
        cout << "Пока не посещено ни одной комнаты." << endl;
    }
}

void find_most_visited_room(const vector<Room*>& rooms) 
{
    int max_visits = -1;
    int max_index = -1;
    
    for (size_t i = 0; i < rooms.size(); i++) 
    {
        if (rooms[i]->getVisitCount() > max_visits) 
        {
            max_visits = rooms[i]->getVisitCount();
            max_index = i;
        }
    }
    
    if (max_visits > 0 && max_index != -1) 
    {
        cout << endl << "Самая посещаемая комната: " << rooms[max_index]->getName() << endl;
        cout << "Количество посещений: " << max_visits << endl;
    } 
    else 
    {
        cout << endl << "Пока нет посещённых комнат." << endl;
    }
}

int main() {
    vector<Room*> rooms;
    
    rooms.push_back(new Room("Переговорка Толстой", "переговорная", 12));
    rooms.push_back(new Room("Кухня 3 этаж", "кухня", 20));
    rooms.push_back(new Room("Open space Backend", "рабочая зона", 40));
    rooms.push_back(new Room("Зона отдыха", "отдых", 15));
    rooms.push_back(new Room("Серверная", "техническая", 5));
    
    Guide guide("Иван");
    
    int choice;
    bool running = true;
    
    while (running) 
    {
        print_menu();
        cin >> choice;
        
        switch (choice)
        {
            case 1: 
            {
                print_available_rooms(rooms);
                cout << "Введите номер комнаты: ";
                int room_number;
                cin >> room_number;
                
                if (room_number >= 1 && room_number <= static_cast<int>(rooms.size())) 
                {
                    guide.goToRoom(rooms[room_number - 1]);
                } 
                else 
                {
                    cout << "Неверный номер комнаты!" << endl;
                }
                break;
            }
            
            case 2: 
            { 
                guide.printCurrentRoomInfo();
                break;
            }
            
            case 3: 
            { 
                show_visited_rooms(rooms);
                break;
            }
            
            case 4: 
            { 
                find_most_visited_room(rooms);
                break;
            }
            
            case 5: 
            {
                cout << "Завершение работы программы..." << endl;
                running = false;
                break;
            }
            
            default: 
            {
                cout << "Неверный пункт меню! Попробуйте снова." << endl;
                break;
            }
        }
    }
 
    for (size_t i = 0; i < rooms.size(); i++) 
    {
        delete rooms[i];
    }
    
    cout << "Память освобождена. Программа завершена." << endl;
    
    return 0;
}