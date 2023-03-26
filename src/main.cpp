#include <iostream>
#include <string>
#include "Automata.h"


int main() {
    Automata machine;
    machine.on();
    machine.coin(1000);
    machine.choice(2);   //американо
    if (machine.check()) {
        machine.cook();
        machine.finish();
    } else {
        machine.cancel();
    }
    machine.off();
    return 0;
}
