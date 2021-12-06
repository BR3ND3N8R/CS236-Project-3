//
// Created by brend on 12/1/2021.
//

#include "PeriodAutomaton.h"

void PeriodAutomaton::S0(const std::string &input) {
    if (input[index] == '.'){
        inputRead++;
    }
    else {
        Serr();
    }
}
