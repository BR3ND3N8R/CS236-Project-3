//
// Created by brend on 12/1/2021.
//

#include "Right_ParenAutomaton.h"

void Right_ParenAutomaton::S0(const std::string &input) {
    if (input[index] == ')'){
        inputRead++;
    }
    else {
        Serr();
    }
}
