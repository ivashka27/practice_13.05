#ifndef EXCURSION_H
#define EXCURSION_H

class Room {
private:
    char* name;         
    char* type;         
    int capacity;       
    int visitCount;     

public:
    Room(const char* n, const char* t, int cap);
    
    ~Room();
    
    // Вывод информации о комнате
    void printInfo();
    
    // Увеличить количество посещений
    void visit();
    
    // Получить количество посещений
    int getVisitCount() const;
    
    // Получить название комнаты
    const char* getName() const;
    
    // Получить тип комнаты
    const char* getType() const;
    
    // Получить вместимость
    int getCapacity() const;
};

class Guide {
private:
    char* name;         
    Room* currentRoom;  

public:
    Guide(const char* n);
    
    ~Guide();
    
    // Перевести группу в другую комнату
    void goToRoom(Room* room);
    
    // Вывести информацию о текущей комнате
    void printCurrentRoomInfo();
    
    // Получить указатель на текущую комнату
    Room* getCurrentRoom() const;
    
    // Получить имя гида
    const char* getName() const;
};

#endif 