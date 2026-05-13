#pragma once

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
    Room(string n, string t, int c);

    void printInfo();

    void visit();

    int getVisitCount();

    string getName();
};