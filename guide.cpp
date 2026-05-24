#include "guide.hpp"

Guide::Guide(std::string name)
    : name_(std::move(name)), current_(nullptr) {}

void Guide::goTo(Room* room) {
    current_ = room;
    if (current_ != nullptr) {
        current_->visit();
    }
}

void Guide::printCurrent() const {
    if (current_ == nullptr) {
        std::cout << "группа пока не находится ни в одной комнате\n";
    } else {
        std::cout << "текущая комната:\n";
        current_->printInfo();
    }
}

Room* Guide::currentRoom() const {
    return current_;
}
