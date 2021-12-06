//
// Created by brend on 12/1/2021.
//

#include "AddAutomaton.h"

void AddAutomaton::S0(const std::string &input) {
    if (input[index] == '+'){
        inputRead++;
    }
    else {
        Serr();
    }
}
