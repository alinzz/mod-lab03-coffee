// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include "Automata.h"

using std::invalid_argument;
using std::domain_error;

TEST(test1, incorrect_operation) {
    Automata machine;
    machine.state = CHECK;
    try {
        machine.on();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test2, incorrect_operation) {
    Automata machine;
    machine.state = CHECK;
    try {
        machine.off();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test3, incorrect_operation) {
    Automata machine;
    machine.state = OFF;
    try {
        machine.coin(100);
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test4, incorrect_operation) {
    Automata machine;
    machine.state = WAIT;
    try {
        machine.cancel();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test5, incorrect_operation) {
    Automata machine;
    machine.state = WAIT;
    try {
        machine.choice(3);
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test6, incorrect_operation) {
    Automata machine;
    machine.state = ACCEPT;
    try {
        machine.check();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test7, incorrect_operation) {
    Automata machine;
    machine.state = OFF;
    try {
        machine.cook();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test8, incorrect_operation) {
    Automata machine;
    machine.state = CHECK;
    try {
        machine.finish();
    }
    catch(domain_error& err) {
        ASSERT_STREQ("Incorrect operation.", err.what());
    }
}

TEST(test9, incorrect_value) {
    Automata machine;
    machine.state = ACCEPT;
    try {
        machine.coin(-500);
    }
    catch(invalid_argument& err) {
        ASSERT_STREQ("Incorrect value.", err.what());
    }
}

TEST(test10, states) {
    Automata machine;
    machine.on();
    EXPECT_EQ(WAIT, machine.state);
}

TEST(test11, states) {
    Automata machine;
    machine.on();
    machine.coin(1000);
    EXPECT_EQ(ACCEPT, machine.state);
}

TEST(test12, states) {
    Automata machine;
    machine.on();
    machine.coin(1000);
    machine.choice(2);
    EXPECT_EQ(CHECK, machine.state);
}

TEST(test13, states) {
    Automata machine;
    machine.on();
    machine.coin(1000);
    machine.choice(2);
    machine.cook();
    EXPECT_EQ(COOK, machine.state);
}

TEST(test14, states) {
    Automata machine;
    machine.on();
    machine.coin(1000);
    machine.choice(2);
    machine.cook();
    machine.finish();
    EXPECT_EQ(WAIT, machine.state);
}

TEST(test15, states) {
    Automata machine;
    machine.on();
    machine.coin(10);
    machine.choice(2);
    machine.cancel();
    EXPECT_EQ(WAIT, machine.state);
}

TEST(test16, states) {
    Automata machine;
    machine.on();
    machine.coin(1000);
    machine.choice(2);
    machine.cook();
    machine.finish();
    machine.off();
    EXPECT_EQ(OFF, machine.state);
}
