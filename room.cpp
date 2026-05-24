#include "room.hpp"

Room::Room(std::string name, std::string type, int capacity)
    : name_(std::move(name)), type_(std::move(type)), capacity_(capacity), visits_(0) {}

void Room::visit() {
    ++visits_;
}

int Room::visitCount() const {
    return visits_;
}

std::string Room::name() const {
    return name_;
}

void Room::printInfo() const {
    std::cout << "название: " << name_ << "\n";
    std::cout << "тип: " << type_ << "\n";
    std::cout << "вместимость: " << capacity_ << "\n";
    std::cout << "посещений: " << visits_ << "\n";
}
