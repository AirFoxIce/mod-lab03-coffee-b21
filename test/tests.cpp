// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, StartsInOffState) {
    Automata a;
    EXPECT_EQ(a.getState(), OFF);
}

TEST(AutomataTest, TurnsOnToWaitState) {
    Automata a;
    a.on();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CoinChangesStateToAccept) {
    Automata a;
    a.on();
    a.coin(20);
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, CoinAccumulatesCash) {
    Automata a;
    a.on();
    a.coin(10);
    a.coin(20);
    a.choice(0);
    EXPECT_TRUE(a.check(0));
}

TEST(AutomataTest, ValidChoiceGoesToCheck) {
    Automata a;
    a.on();
    a.coin(30);
    a.choice(1);
    EXPECT_EQ(a.getState(), CHECK);
}

TEST(AutomataTest, CheckFailsIfNotEnoughCash) {
    Automata a;
    a.on();
    a.coin(5);
    a.choice(2);
    EXPECT_FALSE(a.check(2));
    EXPECT_EQ(a.getState(), ACCEPT);
}

TEST(AutomataTest, CookFromCheckState) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    EXPECT_TRUE(a.check(1));
    a.cook(1);
    EXPECT_EQ(a.getState(), COOK);
}

TEST(AutomataTest, FinishReturnsToWait) {
    Automata a;
    a.on();
    a.coin(50);
    a.choice(1);
    a.check(1);
    a.cook(1);
    a.finish(1);
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CancelResetsStateAndCash) {
    Automata a;
    a.on();
    a.coin(30);
    a.cancel();
    EXPECT_EQ(a.getState(), WAIT);
}

TEST(AutomataTest, CannotOffFromAccept) {
    Automata a;
    a.on();
    a.coin(30);
    a.off();
    EXPECT_NE(a.getState(), OFF);
}
