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
    Automata();
    void on();
    void off();
    void coin(int value);
    void etMenu();
    STATES getState();
    void choice(int index);
    bool check(int index);
    void cancel();
    void cook();
    void finish();
}