// Copyright 2025 AirFoxIce

#include "Automata.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>

Automata::Automata() {
  cash = 0;
  menu = {"Coffe", "Tea", "Chocolate"};
  prices = {20, 15, 25};
  states = OFF;
}

void Automata::on() {
  if (states == OFF) {
    states = WAIT;
    std::cout << "Автомат включен. Ожидание...\n";
  }
}

void Automata::off() {
  if (states == WAIT) {
    states = OFF;
    std::cout << "Автомат выключен.\n";
  }
  else{
    std::cout << "Автомат не выключится из-за актвного сеанса.\n";
  }
}

void Automata::coin(int value) {
  if (states == WAIT || states == ACCEPT) {
    states = ACCEPT;
    cash += value;
    std::cout << "Баланс: " << cash << "р.\n";
  } else {
    std::cout << "Нельзя пополнить баланс в этом режиме.\n";
  }
}

void Automata::etMenu() {
  std::cout << "Меню:\n";
  for (int i = 0; i < static_cast<int>(menu.size()); i++) {
    std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << "р.\n";
  }
}

STATES Automata::getState() {
  return states;
}

void Automata::choice(int index) {
  if (states == ACCEPT) {
    if (index >= 0 && index < static_cast<int>(menu.size())) {
      std::cout << "Ваш выбор: " << menu[index]
                << " - " << prices[index] << "р.\n";
      states = CHECK;
    } else {
      std::cout << "Вы выбрали несуществующую позицию.\n";
    }
  } else {
    std::cout << "Вы не внесли деньги.\n";
  }
}

bool Automata::check(int index) {
  if (states == CHECK) {
    if (cash >= prices[index]) {
      return true;
    } else {
      std::cout << "Недостаточно средств. Баланс: "
                << cash << "р.\n";
      states = ACCEPT;
      return false;
    }
  }
  return false;
}

void Automata::cancel() {
  if (states == ACCEPT || states == CHECK) {
    std::cout << "Операция отменена. Возврат " << cash << "р.\n";
    cash = 0;
    states = WAIT;
  } else {
    std::cout << "Нет активных операций.\n";
  }
}

void Automata::cook(int index) {
  if (states == CHECK && cash >= prices[index]) {
    std::cout << "Готовим напиток: " << menu[index] << "...\n";
    states = COOK;
  } else {
    std::cout << "Нельзя приготовить напиток. Пройдите проверку.\n";
  }
}

void Automata::finish(int index) {
  if (states == COOK) {
    std::cout << "Напиток готов! Приятного дня.\n";
    std::cout << "Сдача: " << cash - prices[index] << "р.\n";
    cash = 0;
    states = WAIT;
  } else {
    std::cout << "Автомат не находится в процессе приготовления.\n";
  }
}
