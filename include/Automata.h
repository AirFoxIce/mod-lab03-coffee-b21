#include <vector>
#include <string>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    // Переменные класса
    int cash;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES states;

public:
    // Методы из задания
    void on();
    void off();
    void coin();
    void etMenu();
    STATES getState();
    void choice();
    bool check();
    void cancel();
    void cook();
    void finish();
}