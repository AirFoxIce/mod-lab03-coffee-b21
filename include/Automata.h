// Copyright 2025 AirFoxIce

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <string>
#include <vector>

enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 public:
  Automata();
  void on();
  void off();
  void coin(int value);
  void etMenu();
  STATES getState();
  void choice(int index);
  bool check(int index);
  void cancel();
  void cook(int index);     // ← исправлено
  void finish(int index);   // ← исправлено

 private:
  int cash;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES states;
};

#endif  // INCLUDE_AUTOMATA_H_
