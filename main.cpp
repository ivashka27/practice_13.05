#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class OfficeLocation {
private:
    std::string m_title;
    std::string m_category;
    int m_maxOccupancy;
    int m_trafficCounter;

public:
    OfficeLocation(std::string title, std::string category, int maxOccupancy)
        : m_title(std::move(title)), m_category(std::move(category)), 
          m_maxOccupancy(maxOccupancy), m_trafficCounter(0) {}

    void displayDetails() const {
        std::cout << "Название: " << m_title << "\n"
                  << "Тип: " << m_category << "\n"
                  << "Вместимость: " << m_maxOccupancy << "\n"
                  << "Количество посещений: " << m_trafficCounter << "\n";
    }

    void registerEntry() {
        m_trafficCounter++;
    }

    int getTraffic() const { return m_trafficCounter; }
    std::string getTitle() const { return m_title; }
    int getMaxOccupancy() const { return m_maxOccupancy; }
};

class TourLeader {
private:
    std::string m_leaderName;
    int m_partySize;
    OfficeLocation* m_currentStop;

public:
    TourLeader(std::string name, int size)
        : m_leaderName(std::move(name)), m_partySize(size), m_currentStop(nullptr) {}

    void moveToLocation(OfficeLocation* destination) {
        if (destination->getTitle() == "Серверная" && m_partySize > destination->getMaxOccupancy()) {
            std::cout << "[ОТКАЗ] Группа из " << m_partySize
                      << " человек слишком большая для Серверной (вместимость: "
                      << destination->getMaxOccupancy() << "). Вход воспрещен!\n";
            return;
        }

        m_currentStop = destination;
        m_currentStop->registerEntry();
        std::cout << "Гид " << m_leaderName << " провёл группу в комнату: "
                  << m_currentStop->getTitle() << "\n";
    }

    void showCurrentLocation() const {
        if (!m_currentStop) {
            std::cout << "Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            m_currentStop->displayDetails();
        }
    }

    void showFullStatus() const {
        std::cout << "--- Информация об экскурсии ---\n";
        std::cout << "Гид: " << m_leaderName << "\n";
        std::cout << "Размер группы: " << m_partySize << " чел.\n";

        if (!m_currentStop) {
            std::cout << "Статус: Группа пока не находится ни в одной комнате.\n";
        } else {
            std::cout << "Текущая комната:\n";
            m_currentStop->displayDetails();
        }
    }

    OfficeLocation* getCurrentStop() const { return m_currentStop; }
};

static void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static int readInteger(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            clearInputStream();
            return value;
        }
        std::cout << "Ошибка ввода. Пожалуйста, введите число.\n";
        clearInputStream();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<OfficeLocation*> buildingMap;
    buildingMap.push_back(new OfficeLocation("Переговорка Толстой", "переговорная", 12));
    buildingMap.push_back(new OfficeLocation("Кухня 3 этаж", "кухня", 20));
    buildingMap.push_back(new OfficeLocation("Open space Backend", "рабочая зона", 40));
    buildingMap.push_back(new OfficeLocation("Зона отдыха", "отдых", 15));
    buildingMap.push_back(new OfficeLocation("Серверная", "техническая", 5));

    TourLeader excursionGuide("Иван", 8);
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\n===== Экскурсия по офису Яндекса =====\n"
                  << "1. Посетить комнату\n"
                  << "2. Информация о гиде и текущей комнате\n"
                  << "3. Показать все посещённые комнаты\n"
                  << "4. Самая посещаемая комната\n"
                  << "5. Показать все доступные комнаты в офисе\n"
                  << "6. Общее количество посещений офиса\n"
                  << "7. Выход\n";

        int option = readInteger("Выберите пункт: ");
        std::cout << "\n";

        switch (option) {
            case 1: {
                int index = readInteger(
                    "Куда направимся? Введите номер от 1 до " + 
                    std::to_string(buildingMap.size()) + ": "
                );

                if (index >= 1 && index <= static_cast<int>(buildingMap.size())) {
                    excursionGuide.moveToLocation(buildingMap[index - 1]);
                } else {
                    std::cout << "Неверный номер комнаты!\n";
                }
                break;
            }

            case 2: {
                excursionGuide.showFullStatus();
                break;
            }

            case 3: {
                std::cout << "Посещённые комнаты:\n";
                bool found = false;
                for (const auto* loc : buildingMap) {
                    if (loc->getTraffic() > 0) {
                        std::cout << loc->getTitle() << " — "
                                  << loc->getTraffic() << " посещений\n";
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "Пока не посещено ни одной комнаты.\n";
                }
                break;
            }

            case 4: {
                auto maxElement = std::max_element(
                    buildingMap.begin(), buildingMap.end(),
                    [](const OfficeLocation* a, const OfficeLocation* b) {
                        return a->getTraffic() < b->getTraffic();
                    }
                );

                if ((*maxElement)->getTraffic() == 0) {
                    std::cout << "Пока нет посещённых комнат.\n";
                } else {
                    std::cout << "Самая посещаемая комната: " 
                              << (*maxElement)->getTitle() << "\n"
                              << "Количество посещений: " 
                              << (*maxElement)->getTraffic() << "\n";
                }
                break;
            }

            case 5: {
                std::cout << "Список всех помещений офиса:\n";
                for (size_t i = 0; i < buildingMap.size(); ++i) {
                    std::cout << i + 1 << ". " << buildingMap[i]->getTitle()
                              << " (Вместимость: " 
                              << buildingMap[i]->getMaxOccupancy() << " чел.)\n";
                }
                break;
            }

            case 6: {
                int totalTraffic = 0;
                for (const auto* loc : buildingMap) {
                    totalTraffic += loc->getTraffic();
                }
                std::cout << "Общее количество перемещений групп по офису: " 
                          << totalTraffic << "\n";
                break;
            }

            case 7: {
                std::cout << "Экскурсия завершена. До свидания!\n";
                isRunning = false;
                break;
            }

            default: {
                std::cout << "Неверный пункт меню. Попробуйте снова.\n";
                break;
            }
        }
    }

    for (auto* loc : buildingMap) {
        delete loc;
    }

    return 0;
}
