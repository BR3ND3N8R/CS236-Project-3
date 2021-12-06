//
// Created by brend on 12/1/2021.
//

#include "Q_MarkAutomaton.h"

void Q_MarkAutomaton::S0(const std::string &input) {
    if (input[index] == '?'){
        inputRead++;
    }
    else {
        Serr();
    }
}
