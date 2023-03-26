// Copyright 2023 UNN-IASR
#pragma once
#include <iostream>
#include <string>

enum STATES {OFF, WAIT, ACCEPT, CHECK, COOK};

using std::string;

class Automata {
 public:
        STATES state;
        int cash;
        const string menu[10] = {
            "Espresso",
            "Americano",
            "Cappuccino",
            "Latte",
            "Macchiato",
            "BlackTea",
            "GreenTea",
            "BubbleTea",
            "Cacao",
            "HotChocolate"
        };
        int option;  // - выбор напитка
        const int prices[10] = {
            80, 100, 150, 150, 160, 120, 120, 180, 140, 170
            };

 public:
        Automata();
        void on();  // - включение
        void off();  // - выключение
        void coin(int x);  // - занесение денег на счёт пользователем
        void getMenu();  // - считывание меню
        void getState();  // - считывание текущего состояния для пользователя
        void choice(int x);  // - выбор напитка пользователем
        bool check();  // - проверка наличия необходимой суммы
        int returnCash();  // - возвращает сдачу/деньги
        void cancel();  // - отмена сеанса обслуживания пользователем
        void cook();  // - имитация процесса приготовления напитка
        void finish();  // - завершение обслуживания пользователя
};
