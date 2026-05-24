#pragma once

#include <string>
#include "room.hpp"

// класс описывает гида который проводит экскурсию
class Guide {
private:
    std::string name_;
    Room* current_;
public:
    // создаёт гида с указанным именем без текущей комнаты
    explicit Guide(std::string name);
    // переводит группу в выбранную комнату и увеличивает счётчик посещений
    void goTo(Room* room);
    void goToRoom(Room* room) { goTo(room); }
    // выводит информацию о текущей комнате или сообщение если она не выбрана
    void printCurrent() const;
    void printCurrentRoomInfo() const { printCurrent(); }
    // возвращает текущую комнату
    Room* currentRoom() const;
    Room* getCurrentRoom() const { return currentRoom(); }
};
