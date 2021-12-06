//
// Created by brend on 12/1/2021.
//

#include "MultiplyAutomaton.h"

void MultiplyAutomaton::S0(const std::string &input) {
    if (input[index] == '*'){
        inputRead++;
    }
    else {
        Serr();
    }
}
