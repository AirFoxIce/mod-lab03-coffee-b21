#include "Automata.h"
#include <iostream>

void main() {
    Automata coffeeMachine;

    coffeeMachine.on();
    coffeeMachine.etMenu();

    coffeeMachine.coin(10);
    coffeeMachine.choice(4);
    coffeeMachine.choice(3);
    coffeeMachine.coin(20);

    coffeeMachine.choice(3);

    if (coffeeMachine.check()) {
        coffeeMachine.cook();
        coffeeMachine.finish();
    } else {
        coffeeMachine.cancel();
    }

    coffeeMachine.off();
}