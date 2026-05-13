#pragma once
#include <string>

class Room {
    private:
        std::string name;
        std::string type;
        int capacity;
        int visitCount;
    public:
        Room(std::string name, std::string type, int capacity);
        void printInfo() const;
        void visit();
        int getVisitCount() const;
        std::string getName() const;
};
