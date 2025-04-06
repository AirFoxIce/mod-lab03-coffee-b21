// Copyright 2025 AirFoxIce

#include "Automata.h"
#include <iostream>

int main() {
  Automata coffeeMachine;

  coffeeMachine.on();
  coffeeMachine.etMenu();

  coffeeMachine.coin(10);
  coffeeMachine.choice(4);
  coffeeMachine.choice(3);
  coffeeMachine.coin(20);

  coffeeMachine.choice(3);

  if (coffeeMachine.check(3)) {
    coffeeMachine.cook(3);
    coffeeMachine.finish(3);
  } else {
    coffeeMachine.cancel();
  }

  coffeeMachine.off();
  return 0;
}
